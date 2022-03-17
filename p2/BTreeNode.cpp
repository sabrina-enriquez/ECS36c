#include "BTreeNode.h"

BTreeNode::BTreeNode(int LSize, InternalNode *p, BTreeNode *left,
  BTreeNode *right) : count(0), leafSize(LSize), parent(p), leftSibling(left),
  rightSibling(right)
{
} // BTreeNode()


int BTreeNode::getCount() const
{
  return count;
} // getCount()


void BTreeNode::setParent(InternalNode *p)
{
  parent = p;
} // setParent()


void BTreeNode::setLeftSibling(BTreeNode *left)
{
  leftSibling = left;
} // setLeftSibling()

