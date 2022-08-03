#pragma once
#include <stack>
#include "Node.h"
#include "NodeDraw.h"
#include "PrinterBTree.h"
template <typename T>
class BTree
{
public:
	BTree(PrinterBTree<T>* printer);
	~BTree();
   /*������������ �����, ���������� ����� ���������� ����
   *
   * ��������� �������� ����
   *
   * ������ �� ����������*/
   void AddNode(T value);
   void Print();
private:
   // ��������� �� ������ ������
   Node<T>* _root;
   PrinterBTree<T>*_printer;

   /*����� ����������� ���� � ������
   *
   * ��������� �������� value, ��� ������ ����
   * � ��������� root �� ������ ���������
   *
   * ���������� ������ ���������*/
   Node<T>* addNode(T value, Node<T>* root);

   /*������� ������, ���������� ��� ���� ������
   *
   * ��������� ��������� root �� ������ ���������
   *
   * ������ �� ����������*/
   void clear(Node<T>* root);
   void rememberNodes(Node<T>* root, int level, std::stack<NodeDraw<T>>& stack);
};

template <typename T>
BTree<T>::BTree(PrinterBTree<T>* printer)
{
   _root = nullptr;
   _printer = printer;
}

template <typename T>
BTree<T>::~BTree()
{
   clear(_root);
}

template<typename T>
void BTree<T>::AddNode(T value)
{
   _root = addNode(value, _root);     // ��������� ����
}

template<typename T>
void BTree<T>::Print()
{
   std::stack<NodeDraw<T>> stack;
   // ���������� � ���� ����������� ������ �����
   rememberNodes(_root, 0, stack);
   _printer->Print(stack);
}

template<typename T>
Node<T>* BTree<T>::addNode(T value, Node<T>* root)
{
   // ���� ����� �� �����, �� ������� ����� ����
   if (root == nullptr)
      root = new Node<T>(value, nullptr, nullptr);

   // � ����������� �� ����, ������ ������� ��� ������
   // ���� � ����� ��� ������ ���������
   else
   {
      if (value > root->Value())
         root->SetRight(addNode(value, root->Right()));

      if (value < root->Value())
         root->SetLeft(addNode(value, root->Left()));
   }
   // ���������� ������ ���������
   return root;
}

template<typename T> 
void BTree<T>::clear(Node<T>* root)
{
   if (root == nullptr)
      return;
   clear(root->Left());
   clear(root->Right());
   delete root;
}

template<typename T>
void BTree<T>::rememberNodes(Node<T>* root, int level, std::stack<NodeDraw<T>>& stackNodeDraw)
{
   const int DIST_H_NODE = 1;
   if (root)
   {
      rememberNodes(root->Right(), level + DIST_H_NODE, stackNodeDraw);
      NodeDraw<T> node = NodeDraw<T>(level, root->Value());
      stackNodeDraw.push(node);
      rememberNodes(root->Left(), level + DIST_H_NODE, stackNodeDraw);
   }
}
