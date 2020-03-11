template <typename T>
Node<T>::Node()
{
  right = nullptr;
  left = nullptr;
}

template <typename T>
Node<T>::Node(T anItem)
{
  item = anItem;
  right = nullptr;
  left = nullptr;
}

template <typename T>
T Node<T>::GetItem()
{
  return item;
}

template <typename T>
Node<T>* Node<T>::GetRight()
{
  return right;
}

template <typename T>
Node<T>* Node<T>::GetLeft()
{
  return left;
}

template <typename T>
void Node<T>::SetItem(T anItem)
{
  item = anItem;
}

template <typename T>
void Node<T>::SetRight(Node<T>* rightPtr)
{
  right = rightPtr;
}

template <typename T>
void Node<T>::SetLeft(Node<T>* leftPtr)
{
  left = leftPtr;
}
