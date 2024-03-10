#pragma once
#include "CycleBuffer.h"

template <typename T>
class LinkedCycleBuffer : public CycleBuffer<T>
{
public:

	LinkedCycleBuffer(int capacity)
	{
		Node* curNode, * lastNode = nullptr;
		for (int i = 0; i < capacity; i++)
		{
			curNode = new Node;
			curNode->val = T();

			if (start == nullptr)
				start = curNode;

			if (lastNode != nullptr)
				lastNode->next = curNode;

			lastNode = curNode;
		}
		end = lastNode;
		end->next = start;

		first = last = start;
	}

	virtual void Add(T item) override
	{
		if (last == first && count != 0)
		{
			throw std::exception("Buffer is full already");
		}
		last->val = item;
		last = last->next;

		++count;
	}

	virtual T Pop() override
	{
		if (count == 0)
		{
			throw std::exception("Buffer is empty");
		}
		T item = first->val;
		first = first->next;
		--count;

		return item;
	}

	virtual T operator[](unsigned index) const override
	{
		if (index >= count)
			throw std::exception("Wrong index");

		Node* curNode = first;
		for (int i = 0; i < index; i++)
			curNode = curNode->next;

		return curNode->val;
	}

	virtual void PrintAllMemory()
	{
		Node* curNode = first;
		while (curNode != last)
		{
			std::cout << curNode->val << " ";
			curNode = curNode->next;
		}

		std::cout << std::endl;
	}

	virtual int GetCount() override { return count; }

	virtual void Reset() override
	{
		first = start;
		last = start;
		count = 0;
	}

protected:
	struct Node
	{
		Node* next;
		T val;
	};

	Node* start = nullptr;
	Node* end = nullptr;

	Node* first = nullptr;
	Node* last = nullptr;

	int count = 0;
};

