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
	head = move(insert);
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
	head->Previous->Next = move(insert);
	cout << head->Previous->Next->Value << endl;
	head->Previous = move(insert);
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
}

//bool DLList::RemoveFromFront()
//{
//
//}
//
//bool DLList::RemoveFromEnd()
//{
//
//}
//
//bool DLList::RemoveAt(int pos)
//{
//
//}
//
//bool DLList::IsEmpty()
//{
//
//}
//
//int DLList::Count()
//{
//
//}