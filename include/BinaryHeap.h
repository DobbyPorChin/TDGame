#pragma once

//=================================
// include guard
#ifndef __BINARY_HEAP_H_INCLUDED__
#define __BINARY_HEAP_H_INCLUDED__
//=================================
// forward declared dependencies

//=================================
// included dependencies
#include <vector>
//=================================
// the actual class
template <class T>
class BinaryHeap
{
public:
	BinaryHeap();
	~BinaryHeap();

	bool isEmpty() const;
	unsigned int getSize() const;
	T& getMin() const;
	
	int insert(T*);
	T* popMin();
	void clear();

	int shiftUp(int node);

private:
	std::vector<T*> heap_;

	int shiftDown(int node);
	
};

template <class T>
BinaryHeap<T>::BinaryHeap()
{
}

template <class T>
BinaryHeap<T>::~BinaryHeap()
{
}

template <class T>
bool BinaryHeap<T>::isEmpty() const
{
	return heap_.size() == 0;
}

template <class T>
unsigned int BinaryHeap<T>::getSize() const
{
	return heap_.size();
}

template <class T>
T& BinaryHeap<T>::getMin() const
{
	T* min = heap_.front();
	return *min;
}

template <class T>
int BinaryHeap<T>::insert(T* pointer)
{
	if (*pointer < 0)
		return -1;

	heap_.push_back(pointer);
    return shiftUp(heap_.size()-1);
}

template <class T>
T* BinaryHeap<T>::popMin()
{
	T* min = heap_.front();
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

template <class T>
int BinaryHeap<T>::shiftDown(int node)
{
	int target = node;
	int leftChild = (node * 2) + 1;
	int rightChild = (node * 2) + 2;
	
	if (heap_.size() > rightChild) {
		bool rightGreaterThanLeft = *heap_[leftChild] > *heap_[rightChild];
		bool targetGreaterThanRight = *heap_[target] > *heap_[rightChild];
		bool targetGreaterThanLeft = *heap_[target] > *heap_[leftChild];

		if (rightGreaterThanLeft && targetGreaterThanRight)
			target = rightChild;
		if (!rightGreaterThanLeft && targetGreaterThanLeft)
			target = leftChild;
	}
	else if (heap_.size() > leftChild) {
		if (*heap_[target] > *heap_[leftChild])
			target = leftChild;
	}

	if (target == node)
		return node;

	std::swap(heap_[node], heap_[target]);
	shiftDown(target);
}

template <class T>
int BinaryHeap<T>::shiftUp(int node)
{
	if (node == 0)
		return 0;
	
	int parent = (node-1)/2;

	if (*heap_[node] >= *heap_[parent])
		return node;

	std::swap(heap_[node], heap_[parent]);
	shiftUp(parent);
}

#endif // __BINARY_HEAP_H_INCLUDED__ 

