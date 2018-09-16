#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "DLNode.h"
using namespace std;

class DLList
{
public:
	DLList();
	shared_ptr<DLNode> head;
	void AddToEnd(int value);
	void AddToFront(int value);
	void AddAt(int pos, int value);
	bool RemoveFromFront();
	bool RemoveFromEnd();
	bool RemoveAt(int pos);
	bool IsEmpty();
	int Count();
};

