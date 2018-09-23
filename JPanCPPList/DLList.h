#pragma once
#include <memory>
#include "DLNode.h"
using std::shared_ptr;

template <typename T>
class DLList
{
public:
	DLList();
	shared_ptr<DLNode<T>> head;
	void AddToEnd(T value);
	void AddToFront(T value);
	void AddAt(int pos, T value);
	bool RemoveFromFront();
	bool RemoveFromEnd();
	bool RemoveAt(int pos);
	bool IsEmpty();
	int Count();
};

template <typename T>
DLList<T>::DLList()
{
}

template <typename T>
void DLList<T>::AddToFront(T value)
{
	if (head == nullptr)
	{
		head = make_shared<DLNode<T>>(value);
		head->Next = head;
		head->Previous = head;
		return;
	}
	shared_ptr<DLNode<T>> insert = make_shared<DLNode<T>>(value);
	insert->Next = head;
	head->Previous->Next = insert;
	insert->Previous = head->Previous;
	head->Previous = insert;
	head = insert;
}

template <typename T>
void DLList<T>::AddToEnd(T value)
{
	if (head == nullptr)
	{
		head = make_shared<DLNode<T>>(value);
		head->Next = head;
		head->Previous = head;
		return;
	}
	shared_ptr<DLNode<T>> insert = make_shared<DLNode<T>>(value);
	head->Previous->Next = insert;
	head->Previous->Next->Previous = head->Previous;
	head->Previous = insert;
	head->Previous->Next = head;
}

template <typename T>
void DLList<T>::AddAt(int pos, T value)
{
	if (head == nullptr)
	{
		head = make_shared<DLNode<T>>(value);
		head->Next = head;
		head->Previous = head;
		return;
	}
	if (pos <= 0)
	{
		AddToFront(value);
		return;
	}
	if (pos >= Count())
	{
		AddToEnd(value);
		return;
	}
	shared_ptr<DLNode<T>> insert = make_shared<DLNode<T>>(value);
	auto temp = head;
	for (int i = 0; i < pos - 1; i++)
	{
		temp = head->Next;
	}
	temp->Next->Previous = insert;
	insert->Next = temp->Next;
	temp->Next = insert;
	insert->Previous = temp;
}

template <typename T>
bool DLList<T>::RemoveFromFront()
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

template <typename T>
bool DLList<T>::RemoveFromEnd()
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

template <typename T>
bool DLList<T>::RemoveAt(int pos)
{
	if (pos <= 1)
	{
		return RemoveFromFront();
	}
	if (pos >= Count())
	{
		return RemoveFromEnd();
	}
	auto temp = head;
	for (int i = 0; i < pos; i++)
	{
		temp = temp->Next;
	}
	temp->Next->Next->Previous = temp;
	temp->Next = temp->Next->Next;
	return true;
}

template <typename T>
bool DLList<T>::IsEmpty()
{
	if (head == nullptr)
	{
		return true;
	}
	return false;
}

template <typename T>
int DLList<T>::Count()
{
	int num = 0;
	auto temp = head;	
	while (temp->Next != head)
	{
		temp = temp->Next;
		num++;
	}
	return num;
}