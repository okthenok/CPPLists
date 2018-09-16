#pragma once
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class DLNode
{
public:
	DLNode(int value);
	shared_ptr<DLNode> Next;
	shared_ptr<DLNode> Previous;
	int Value;
};

