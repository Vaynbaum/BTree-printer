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
      // Считываем из стека элемент и отображаем его на экране
      while (!stack.empty())
      {
         NodeDraw<T> node = stack.top();
         stack.pop();
         // Запоминаем максимальную координату y в консоли
         if (maxHeight < node.Level())
            maxHeight = node.Level();

         // Задаем позицию курсора в консоли
         gotoXY(coordX, node.Level());
         std::cout << node.Value();
         coordX += DIST_W_NODE;
      }
      gotoXY(0, maxHeight + 1);
   }

private:
   void gotoXY(int x, int y)
   {
      // Дескриптор консольной программы
      HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      // Структура для координаты курсор
      COORD posCur = { x,y };
      // Задаем позицию курсора
      SetConsoleCursorPosition(hStdOut, posCur);
   }
};