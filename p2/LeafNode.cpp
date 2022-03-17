#include <iostream>
#include "LeafNode.h"
#include "InternalNode.h"
#include "QueueAr.h"

using namespace std;


LeafNode::LeafNode(int LSize, InternalNode *p,
  BTreeNode *left, BTreeNode *right) : BTreeNode(LSize, p, left, right)
{
  values = new int[LSize];
}  // LeafNode()



int LeafNode::getMinimum()const
{
  if(count > 0)  // should always be the case
    return values[0];
  else
    return 0;

} // LeafNode::getMinimum()


LeafNode* LeafNode::insert(int value)
{
//there is space so add it to an existing leaf
 
  if (1 + count <= leafSize) {
    sortVal(value);
      count++;
      
  }
 
        else if (leftSibling)
        {
            int minimum=getMinimum();
            if (value <minimum)
            {
                minimum=value;
                
            }
    
            leftSibling->insert(minimum);
            sortVal(value);
    
    
        }
    
        else if( rightSibling)
        {
            int max= values[leafSize];
            if (value > max)
            {
                max= value;
            }
            rightSibling-> insert(max);
            sortVal(value);
        }
    
    
    
    
  //full and no siblings
  else{
      
      return splitLeaf(value);
      
      
      
  }
    
    

  
    return NULL;
  
}  // LeafNode::insert()

void LeafNode::print(Queue <BTreeNode*> &queue)
{
  cout << "Leaf: ";
  for (int i = 0; i < count; i++)
    cout << values[i] << ' ';
  cout << endl;
} // LeafNode::print()




//function to sort the values in a given leaf
void LeafNode::sortVal( int value) {
  if (count == 0) {
    values[count] = value;
  }
  else {
    for(int pos = count - 1; pos >= 0; pos-- ) {
      if (value < values[pos]) {
        values[pos+1] = values[pos]; //shift
        values[pos]=value;//insert value into empty spot
      }
      else {
        values[pos+1]=value; //insert value into next empty spot
        break;
      }
    }
  }
}



LeafNode* LeafNode::splitLeaf(int value)
{
    int maximum= value;
    
    
//    set max
    if (maximum < values[count-1])
    {
        maximum=values[count-1];
        sortVal(value);
        
    }
     count = (leafSize+1)/2;
    if(leafSize%2==0) //leaf size is even
    {
        
        int half=leafSize/2;
        LeafNode *newNode= new LeafNode( leafSize, parent, leftSibling, rightSibling);
        
        for (int i=half; i<leafSize; i++) //put the bigger half of the values into the new node
        {
            newNode -> insert(values[i]);
                          
        }
        insert(maximum);
    return newNode;
    }
    
    else //leaf size is odd
    {
        
        int half=leafSize/2;
        LeafNode *newNode= new LeafNode( leafSize, parent, leftSibling, rightSibling);
            
            for (int i=half+1; i<leafSize; i++) //put the bigger half of the values into the new node
            {
                newNode -> insert(values[i]);
                              
            }
        insert(maximum);
       
        return newNode;
        
    }
        
        
        
   
}

