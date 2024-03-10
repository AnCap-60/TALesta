#pragma once

template <typename T>
class CycleBuffer
{
public:	
	virtual void Add(T item) = 0;
	virtual T Pop() = 0;

	virtual void Reset() = 0;

	virtual int GetCount() = 0;

protected:
};

