#pragma once
#include <iostream>
#include <stack>
#include <windows.h>
#include "PrinterBTree.h"
#include "NodeDraw.h"
template<typename T>
class ConsolePrinterBTree :public  PrinterBTree<T>
{
public:
   void Print(std::stack<NodeDraw<T>>& stack) override
   {
      const int DIST_W_NODE = 3;
      int coordX = 0;
      int maxHeight = 0;

      system("cls");
      // ��������� �� ����� ������� � ���������� ��� �� ������
      while (!stack.empty())
      {
         NodeDraw<T> node = stack.top();
         stack.pop();
         // ���������� ������������ ���������� y � �������
         if (maxHeight < node.Level())
            maxHeight = node.Level();

         // ������ ������� ������� � �������
         gotoXY(coordX, node.Level());
         std::cout << node.Value();
         coordX += DIST_W_NODE;
      }
      gotoXY(0, maxHeight + 1);
   }

private:
   void gotoXY(int x, int y)
   {
      // ���������� ���������� ���������
      HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      // ��������� ��� ���������� ������
      COORD posCur = { x,y };
      // ������ ������� �������
      SetConsoleCursorPosition(hStdOut, posCur);
   }
};