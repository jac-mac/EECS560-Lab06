#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include <iostream>
#include <limits>
#include <fstream>

using namespace std;

class Executive
{
  private:
  string fileName;
  //BinarySearchTree<T> bst;

  public:
  Executive(string file);
  void Run();
  void PrintMenu();
  void WrongInputTypeCheck(int &num);
  void GetInputFromFile();
};
#endif
