#include <iostream>
#include "VectorCycleBuffer.h"
#include "LinkedCycleBuffer.h"

bool isEven(int value) { return value % 2 == 0; }

bool IsEven(int value)
{
	return !(value & 1);
}

int Partition(int arr[], int low, int high, int pivot)
{
	int i = low;
	int j = low;

	while (i <= high)
	{
		if (arr[i] > pivot)
			i++;
		else
		{
			std::swap(arr[i], arr[j]);
			i++;
			j++;
		}
	}

	return j - 1;
}



void QuickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pivot = arr[high];
		int pos = Partition(arr, low, high, pivot);

		QuickSort(arr, low, pos - 1);
		QuickSort(arr, pos + 1, high);
	}
}

void Sort(int* arr, int count)
{
	QuickSort(arr, 0, count - 1);
}

int main()
{
	int n = 210000;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = rand();

	Sort(arr, n);

	return 0;
}