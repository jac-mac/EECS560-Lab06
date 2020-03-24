#include "BinarySearchTree.h"

// BST::BST()
// {
//   root = nullptr;
// }

// TreeNode* BST::GetRoot()
// {
//   return root;
// }
//
// void BST::SetRoot(TreeNode* aRoot)
// {
//   root = aRoot;
// }

TreeNode* BST::AddItem(int key, TreeNode* node)
{
  if(node == nullptr)
    node = new TreeNode(key);

  else if(key >= node->GetItem())
  {
    node->SetRight(AddItem(key, node->GetRight()));
  }

  else if(key < node->GetItem())
  {
    node->SetLeft(AddItem(key, node->GetLeft()));
  }

  return node;
}

TreeNode* BST::DeleteItem(int key, TreeNode* node)
{
  if(node == nullptr)
    return node;

  else
  {
    if(key < node->GetItem())
      node->SetLeft(DeleteItem(key, node->GetLeft()));

    else if(key > node->GetItem())
      node->SetRight(DeleteItem(key, node->GetRight()));

    else if(key == node->GetItem())
    {
      if(node->GetLeft() == nullptr)
      {
        TreeNode* temp = node->GetRight();
        delete node;
        return temp;
      }
      else if(node->GetRight() == nullptr)
      {
        TreeNode* temp = node->GetLeft();
        delete node;
        return temp;
      }

      TreeNode* temp = CalcMinValue(node->GetRight());
      node->SetItem(temp->GetItem());
      node->SetRight(DeleteItem(temp->GetItem(), node->GetRight()));
    }
  }
  return node;
}

void BST::Inorder(TreeNode* node)
{
  if(node == nullptr)
    return;

  else
  {
    Inorder(node->GetLeft());
    std::cout << node->GetItem();
    Inorder(node->GetRight());
  }
}

TreeNode* BST::InorderSuccessor(int key, TreeNode* node)
{
  if(key == node->GetItem())
  {
    if(node->GetRight() != nullptr)
      return CalcMinValue(node->GetRight());

    else
    {
      return nullptr;
    }
  }

  else if(key < node->GetItem())
  {
    TreeNode* successor = node;
    if(InorderSuccessor(key, node->GetLeft()) == nullptr)
    {
      return successor;
    }
    else
    {
      return (InorderSuccessor(key, node->GetLeft()));
    }
  }

  else if(key > node->GetItem())
  {
    return (InorderSuccessor(key, node->GetRight()));
  }
}

TreeNode* BST::CalcMinValue(TreeNode* node)
{
  TreeNode* current = node;

  if(node != nullptr)
  {
    while(current->GetLeft() != nullptr)
      current = current->GetLeft();
  }

  return current;
}

int BST::HeightOfTree(TreeNode* node)
{
  if(node == nullptr)
    return 0;
  else
  {
    int heightOfLeft = HeightOfTree(node->GetLeft());
    int heightOfRight = HeightOfTree(node->GetRight());

    if(heightOfLeft > heightOfRight)
      return (heightOfLeft + 1);
    else
      return (heightOfRight + 1);
  }
}

void BST::LevelOrder(TreeNode* node)
{
  int height = HeightOfTree(node);
  for(int i = 1; i <= height; i++)
  {
    PrintLevel(node, i);
  }
}

void BST::PrintLevel(TreeNode* node, int level)
{
  if(node == nullptr)
    return;

  if(level == 1)
    std::cout << node->GetItem() << " ";

  else if(level > 1)
  {
      PrintLevel(node->GetLeft(), level-1);
      PrintLevel(node->GetRight(), level-1);
  }
}

void BST::LevelOrderSpiral(TreeNode* node)
{
  int height = HeightOfTree(node);
  for(int i = 1; i <= height; i++)
  {
    if(i%2 == 1)
    {
      PrintLevelReverse(node, i);
    }


    else if(i%2 == 0)
    {
      PrintLevel(node, i);
    }
  }
}

void BST::PrintLevelReverse(TreeNode* node, int level)
{
  if(node == nullptr)
    return;

  if(level == 1)
    std::cout << node->GetItem() << " ";

  else if(level > 1)
  {
    PrintLevelReverse(node->GetRight(), level-1);
    PrintLevelReverse(node->GetLeft(), level-1);
  }
}

void BST::ClearTree(TreeNode* node)
{
  if(node == nullptr)
    return;
  ClearTree(node->GetLeft());
  ClearTree(node->GetRight());

  std::cout << "Deleting node: " << node->GetItem() << '\n';
  delete node;
}
