#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
  private:
  T item;
  Node<T>* right;
  Node<T>* left;

  public:
  Node();
  Node(T anItem);

  T GetItem();
  Node<T>* GetRight();
  Node<T>* GetLeft();

  void SetRight(Node<T>* rightPtr);
  void SetLeft(Node<T>* leftPtr);
  void SetItem(T anItem);

};
#include "Node.cpp"
#endif
