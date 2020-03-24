#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include <iostream>
#include <limits>
#include <fstream>

#include "BinarySearchTree.h"

using namespace std;

class Executive
{
  private:
  string fileName;
  BST* bst;
  TreeNode* rootPtr;

  public:
  Executive(string file);
  void Run();
  void PrintMenu();
  void WrongInputTypeCheck(int &num);
  void GetInputFromFile();
};
#endif
