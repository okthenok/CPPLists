#include "DLList.h"



DLList::DLList()
{
}

void DLList::AddToFront(int value)
{
	if (head == nullptr)
	{
		head = make_shared<DLNode>(value);
		head->Next = move(head);
		head->Previous = move(head);
		return;
	}
	shared_ptr<DLNode> insert = make_shared<DLNode>(value);
	insert->Next = head;
	head->Previous->Next = insert;
	insert->Previous = head->Previous;
	head->Previous = insert;
	head = insert;

}

void DLList::AddToEnd(int value)
{
	if (head == nullptr)
	{
		head = make_shared<DLNode>(value);
		head->Next = head;
		head->Previous = head;
		return;
	}
	shared_ptr<DLNode> insert = make_shared<DLNode>(value);
	head->Previous->Next = insert;
	head->Previous->Next->Previous = head->Previous;
	head->Previous = insert;
	head->Previous->Next = head;
}

void DLList::AddAt(int pos, int value)
{
	if (head == nullptr)
	{
		head = make_shared<DLNode>(value);
		head->Next = move(head);
		head->Previous = move(head);
		return;
	}
	shared_ptr<DLNode> insert = make_shared<DLNode>(value);
	auto temp = head;
	for (int i = 0; i < pos; i++)
	{
		temp = head->Next;
	}
	temp->Next->Next->Previous = insert;
	insert->Next = temp->Next->Next;
	temp->Next = insert;
	insert->Previous = temp;
}

bool DLList::RemoveFromFront()
{
	if (head == nullptr)
	{
		return false;
	}
	if (head->Next == head)
	{
		head = nullptr;
		return true;
	}
	head->Previous->Next = head->Next;
	head->Next->Previous = head->Previous;
	head = head->Next;
	return true;
}

bool DLList::RemoveFromEnd()
{
	if (head == nullptr)
	{
		return false;
	}
	if (head->Next == head)
	{
		head == nullptr;
		return true;
	}
	head->Previous->Previous->Next = head;
	head->Previous = head->Previous->Previous;
	return true;
}

bool DLList::RemoveAt(int pos)
{
	if (pos == 1)
	{
		RemoveFromFront();
	}
	if (pos == Count())
	{
		RemoveFromEnd();
	}
	auto temp = head;
	for (int i = 0; i < pos; i++)
	{
		temp = temp->Next;
	}
	temp->Next->Next->Previous = temp;
	temp->Next = temp->Next->Next;

}

bool DLList::IsEmpty()
{
	if (head == nullptr)
	{
		return true;
	}
	return false;
}

int DLList::Count()
{
	int num = 0;
	auto temp = head;
	while (head->Next != head)
	{
		temp = head;
		num++;
	}
	return num;
}