#include "TreeNode.h"
TreeNode::TreeNode()
{
  right = nullptr;
  left = nullptr;
}


TreeNode::TreeNode(int anItem)
{
  item = anItem;
  right = nullptr;
  left = nullptr;
}


int TreeNode::GetItem()
{
  return item;
}


TreeNode* TreeNode::GetRight()
{
  return right;
}


TreeNode* TreeNode::GetLeft()
{
  return left;
}


void TreeNode::SetItem(int anItem)
{
  item = anItem;
}


void TreeNode::SetRight(TreeNode* rightPtr)
{
  right = rightPtr;
}


void TreeNode::SetLeft(TreeNode* leftPtr)
{
  left = leftPtr;
}
