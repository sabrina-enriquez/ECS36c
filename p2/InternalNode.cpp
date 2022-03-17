#include <iostream>
#include "InternalNode.h"

using namespace std;

InternalNode::InternalNode(int ISize, int LSize,
  InternalNode *p, BTreeNode *left, BTreeNode *right) :
  BTreeNode(LSize, p, left, right), internalSize(ISize)
{
  keys = new int[internalSize]; // keys[i] is the minimum of children[i]
  children = new BTreeNode* [internalSize];
} // InternalNode::InternalNode()


int InternalNode::getMinimum()const
{
  if(count > 0)   // should always be the case
    return children[0]->getMinimum();
  else
    return 0;
} // InternalNode::getMinimum()


InternalNode* InternalNode::insert(int keyValue)
{

    
    //split function for internal node
    //count is number of children and we need to make sure that number is <= internal size
    //so when we are inserting but count-1 = internal size and no left or right sibling takes it, we need to split
    
        int maxKey= keyValue;


    //    set max
        if (maxKey < keys[count])
        {
            maxKey=keys[count];
            sortKeys(maxKey);

        }

        
           count = (internalSize+1)/2;
        if(internalSize%2==0) //internal size is even
        {

            int half=internalSize/2;
            InternalNode *newNode= new InternalNode( internalSize, leafSize ,parent, leftSibling, rightSibling);
            setLeftSibling(leftSibling);

            for (int i=half; i<internalSize; i++) //put the bigger half of the key values into the new node
            {
                newNode -> insert(keys[i]);

            }
            insert(maxKey);
        return newNode;
        }

        else //internal size is odd
        {

            int half=internalSize/2;
            InternalNode *newNode= new InternalNode( internalSize, leafSize, parent, leftSibling, rightSibling);

                for (int i=half+1; i<internalSize; i++) //put the bigger half of the key values into the new node
                {
                    newNode -> insert(keys[i]);

                }
            insert(maxKey);
         
            return newNode;
            
            

        }




    
    
    
    
  return NULL; // to avoid warnings for now.
} // InternalNode::insert()


void InternalNode::insert(BTreeNode *newNode) // from a sibling or BTree::insert // if it splits else NULL //here we need set parent

  //only insert a new internal node if we reach max children for a given internal node
//    we need to check if left sibling or right sibling have space for a new child
//    otherwise we need to split and add a new internal node/ parent set parent
{
    
    int newKey= newNode-> getMinimum();
//    int position;
//    //now see where it fits
//
//
//    //to figure out where we insert we need to keep track of our position through the keys
//    for( int pos= 0; pos<internalSize+1; pos++)
//    {
//    if(newKey> keys[pos])
//    {
//        position=pos;
//        break;
//    }
//    }
    
    
  if (1 + count <= internalSize) {
    sortKeys(newKey);
      
      
      updateMinimums();
      setParent(parent);
  
      count++;
      
  }
 
        else if (leftSibling)
        {
            int minKey = newKey
            ;
            if (keys[0] <minKey)
            {
                minKey=keys[0];
                
            }
    
            leftSibling-> insert( minKey);
            sortKeys(minKey);
    
    
        }
    
        else if( rightSibling)
        {
            int maxKey=keys[internalSize+1];
            int newKey= getMinimum();
            if (newKey>maxKey)
            {
                maxKey= newKey;
            }
            rightSibling-> insert(maxKey);
            updateMinimums();
            sortKeys(maxKey);
        }
    
   
    
    
    
    
} // InternalNode::insert()

void InternalNode::print(Queue <BTreeNode*> &queue)
{
  int i;

  cout << "Internal: ";
  for (i = 0; i < count; i++)
    cout << keys[i] << ' ';
  cout << endl;

  for(i = 0; i < count; i++)
    queue.enqueue(children[i]);

} // InternalNode::print()


void InternalNode::updateMinimums() 
{ // called by child with a new minimum
    for (int i=0; i<count; i++)
    {
        keys[i] = children[i] -> getMinimum();
    }
    
}   // InternalNode::updateMinimums









void InternalNode:: sortKeys(int value)
{
    
      if (count == 0) {
        keys[count] = value;
      }
      else {
        for(int pos = count - 1; pos >= 0; pos-- ) {
          if (value < keys[pos]) {
            keys[pos+1] = keys[pos]; //shift
            keys[pos]=value;//insert value into empty spot
          }
          else {
            keys[pos+1]=value; //insert value into next empty spot
            break;
          }
        }
      }
    }

