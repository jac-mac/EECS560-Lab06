#ifndef BST_H
#define BST_H

#include "TreeNode.h"
#include <iostream>

class BST
{
  private:
  //TreeNode* root;

  public:
  // BST();
  // TreeNode* GetRoot();
  // void  SetRoot(TreeNode* aRoot);
  TreeNode* AddItem(int key, TreeNode* node);
  TreeNode* DeleteItem(int key, TreeNode* node);
  void Inorder(TreeNode* node);
  TreeNode* InorderSuccessor(int key, TreeNode* node);
  TreeNode* CalcMinValue(TreeNode* node);
  int HeightOfTree(TreeNode* node);
  void LevelOrder(TreeNode* node);
  void PrintLevel(TreeNode* node, int level);
  void LevelOrderSpiral(TreeNode* node);
  void PrintLevelReverse(TreeNode* node, int level);
  TreeNode* KthSmallestItem(TreeNode* node, int k);
  void ClearTree(TreeNode* node);
};
#endif
