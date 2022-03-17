#include <iostream>
#include "BTree.h"
#include "BTreeNode.h"
#include "LeafNode.h"
#include "InternalNode.h"
using namespace std;

BTree::BTree(int ISize, int LSize):internalSize(ISize), leafSize(LSize)
{
  root = new LeafNode(LSize, NULL, NULL, NULL);
} // BTree::BTree()


void BTree::insert(const int value)
{
  // students must write this
  BTreeNode *newNode = root->insert(value);
  if (newNode) {
    InternalNode *newRoot = new InternalNode(internalSize, leafSize,NULL, NULL, NULL);
   // newNode->insert(root);
    newRoot->insert(newNode);
    root = newRoot;
    //create internal node
    //insert root and newNode into internal node
  }
//  std::cout << newNode << std::endl;
//  BTreeNode *newRoot = new InternalNode(internalSize, leafSize, NULL, NULL, NULL);
//  newRoot->insert(root);

} // BTree::insert()


void BTree::print()
{
  BTreeNode *BTreeNodePtr;
  Queue<BTreeNode*> queue(1000);

  queue.enqueue(root);
  while(!queue.isEmpty())
  {
    BTreeNodePtr = queue.dequeue();
    BTreeNodePtr->print(queue);
  } // while
} // BTree::print()
