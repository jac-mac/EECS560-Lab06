#ifndef TREENODE_H
#define TREENODE_H

class TreeNode
{
  private:
  int item;
  TreeNode* right;
  TreeNode* left;

  public:
  TreeNode();
  TreeNode(int anItem);

  int GetItem();
  TreeNode* GetRight();
  TreeNode* GetLeft();

  void SetRight(TreeNode* rightPtr);
  void SetLeft(TreeNode* leftPtr);
  void SetItem(int anItem);

};
#endif
