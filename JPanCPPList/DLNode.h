#pragma once
#include <memory>
using std::shared_ptr;

template <typename T>
class DLNode
{
public:
	DLNode(T value);
	shared_ptr<DLNode<T>> Next;
	shared_ptr<DLNode<T>> Previous;
	T Value;
};

template <typename T>
DLNode<T>::DLNode(T value)
{
	Value = value;
}