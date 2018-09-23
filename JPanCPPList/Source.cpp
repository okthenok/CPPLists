#include <iostream>
#include "DLList.h"
#include "DLNode.h"
using namespace std;

int main()
{
	DLList<int> list;
	list.AddToFront(1);
	list.AddToEnd(2);
	list.AddToEnd(3);
	list.AddToEnd(4);
	list.AddToFront(0);
	list.AddToFront(-1);
	list.RemoveFromEnd();
	list.RemoveAt(3);
	list.RemoveFromFront();
	list.AddAt(1, 6);
	/*bool running = true;
	while (running)
	{
		cout << "1. Add to front" << endl;
	}*/
	system("PAUSE");
	return 0;
}