#pragma once
#include <stack>
#include "NodeDraw.h"
template<typename T>
class PrinterBTree
{
public:
   virtual void Print(std::stack<NodeDraw<T>>& stack) = 0;
};
