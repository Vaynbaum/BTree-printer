# Binary tree printer

You can print a nice binary tree in the console.
***

# How to use

You need to create an instance of the `printer` class to be used (e.g. `ConsolePrinterBTree`). 
Then create an instance of the `BTree` class and pass the `printer` to it
(*by the way, you can add your own printers for different printing for the tree*).
Then add the values and print them.

(**File: BTree.cpp**)
```c++
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
```

<img width="200" alt="image" src="https://user-images.githubusercontent.com/78900834/182572101-e9625f55-80d7-41c2-8665-a07e664390df.png">
