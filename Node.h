#pragma once
template <typename T>
class Node
{
public:
   Node(T value, Node<T>* left, Node<T>* right);
   T Value();
   Node<T>* Left();
   Node<T>* Right();
   void SetLeft(Node<T>* left);
   void SetRight(Node<T>* left);
private:
   T _value;         // Значение узла
   Node<T>* _left;   // Левое поддерево   
   Node<T>* _right;  // Правое поддерево
};
template <typename T>
Node<T>::Node(T value, Node<T>* left, Node<T>* right)
{
   _value = value;
   _left = left;
   _right = right;
}

template<typename T>
T Node<T>::Value()
{
   return _value;
}

template<typename T>
Node<T>* Node<T>::Left()
{
   return _left;
}

template<typename T>
Node<T>* Node<T>::Right()
{
   return _right;
}

template<typename T>
 void Node<T>::SetLeft(Node<T>* left)
{
    _left = left;
}

 template<typename T>
  void Node<T>::SetRight(Node<T>* right)
 {
     _right = right;
 }
