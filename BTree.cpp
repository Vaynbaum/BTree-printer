#include "BTree.h"
#include "ConsolePrinterBTree.h"

int main()
{
   int arr[] = { 7,5,6,8,2,9 };
   int len = sizeof(arr) / sizeof(int);
   PrinterBTree<int>* printer = new ConsolePrinterBTree<int>();
   BTree<int> tree = BTree<int>(printer);
   for (int i = 0; i < len; i++)
   {
      tree.AddNode(arr[i]);
   }
   tree.Print();
}
