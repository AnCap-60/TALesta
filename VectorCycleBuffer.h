#pragma once

#include <iostream>
#include "CycleBuffer.h"

template <typename T>
class VectorCycleBuffer : public CycleBuffer<T>
{
public:
	virtual ~VectorCycleBuffer()
	{
		free(instance);
	}

	VectorCycleBuffer() : VectorCycleBuffer(4) {}
	VectorCycleBuffer(int capacity)
	{
		this->capacity = capacity;
		this->count = 0;

		instance = (T*)calloc(capacity, sizeof(T));
	}

	virtual void Add(T item) override
	{
		if (this->count >= capacity)
		{
			std::cerr << "Buffer is full already" << std::endl;
			return;
		}
		++count;
		lastInd = (lastInd + 1) % capacity;
		instance[lastInd] = item;
	}

	virtual T Pop() override
	{
		T item = instance[firstInd];
		instance[firstInd] = 0;
		firstInd = (firstInd + 1) % capacity;
		--count;

		return item;
	}

	virtual T operator[](unsigned index) const override
	{
		if (index >= count)
			throw std::exception("Wrong index");

		return instance[(firstInd + index) % capacity];
	}

	virtual void Reset()
	{
		firstInd = 0;
		lastInd = -1;
		count = 0;
		memset(instance, 0, capacity * sizeof(T));
	}

	virtual int GetCount() override { return count; }

	int GetCapacity() { return capacity; }

	void PrintAllMemory()
	{
		for (int i = 0; i < capacity; i++)
		{
			std::cout << instance[i] << ' ';
		}
		std::cout << std::endl;
	}

protected:
	int count = 0;

	int capacity;

	T* instance;

	int firstInd = 0;
	int lastInd = -1;
};

