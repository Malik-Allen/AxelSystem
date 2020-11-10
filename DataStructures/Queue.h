#ifndef QUEUE_H
#define QUEUE_H

#include "DList.h"

template <typename T>
class Queue
{
	DList<T> data;

public:
	
	void enqueue_front(const T& value)
	{
		data.push_front(value);
	}

	void enqueue_back(const T& value)
	{
		data.push_back(value);
	}

	void dequeue_front()
	{
		data.pop_front();
	}

	void dequeue_back()
	{
		data.pop_back();
	}

	T& front()
	{
		return data.front();
	}

	T& back()
	{
		return data.back();
	}

	bool empty() const
	{
		return data.empty();
	}

	size_t size() const
	{
		return data.size();
	}

	void clear()
	{
		data.clear();
	}
};

#endif
