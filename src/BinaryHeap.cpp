#include "BinaryHeap.h"

template <class T>
BinaryHeap<T>::BinaryHeap()
{
}

template <class T>
BinaryHeap<T>::BinaryHeap(unsigned int size)
{
	heap_.reserve(size);
}

template <class T>
BinaryHeap<T>::~BinaryHeap()
{
}

template <class T>
unsigned int BinaryHeap<T>::getSize() const
{
	return heap_.size();
}

template <class T>
bool BinaryHeap<T>::isEmpty() const
{
	return heap_.size() == 0;
}

template <class T>
void BinaryHeap<T>::insert(const T& value)
{
	heap_.push_back(value);
    shiftUp(heap_.size()-1);
}

template <class T>
T& BinaryHeap<T>::getMin() const
{
	return heap_.front();
}

template <class T>
T BinaryHeap<T>::popMin()
{
	T min = heap_.front();
	heap_.front() = heap_.back();
	heap_.pop_back();
	shiftDown(0);
	return min;
}

template <class T>
void BinaryHeap<T>::clear()
{
	heap_.clear();
}

//template <class T>
//void BinaryHeap<T>::buildHeap()
//{
//}

template <class T>
void BinaryHeap<T>::shiftDown(int node)
{
	int target = node;
	int leftChild = (node * 2) + 1;
	int rightChild = (node * 2) + 2;
	
	if (heap_.size() > rightChild) {
		bool rightGreaterThanLeft = heap_[leftChild] > heap_[rightChild];
		bool targetGreaterThanRight = heap_[target] > heap_[rightChild];
		bool targetGreaterThanLeft = heap_[target] > heap_[leftChild];

		if (rightGreaterThanLeft && targetGreaterThanRight)
			target = rightChild;
		if (!rightGreaterThanLeft && targetGreaterThanLeft)
			target = leftChild;
	}
	else if (heap_.size() > leftChild) {
		if (heap_[target] > heap_[leftChild])
			target = leftChild;
	}

	if (target == node)
		return;

	std::swap(heap_[node], heap_[target]);
	shiftDown(target);
}

template <class T>
void BinaryHeap<T>::shiftUp(int node)
{
	if (node == 0)
		return;
	
	int parent = (node-1)/2;

	if (heap_[node] > heap_[parent])
		return;

	std::swap(heap_[node], heap_[parent]);
	shiftUp(parent);
}