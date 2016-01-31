#include "sort.h"

void Sort::mergeSort(vector<int> &array, int start, int end)
{
	if (start - end <= 1)
	{
		if (array[start] > array[end])
		{
			int temp = array[start];
			array[start] = array[end];
			array[end] = temp;
		}
		return;
	}


	int temp = (start + end) / 2;

	mergeSort(array, start, temp);
	mergeSort(array, temp + 1, end);
	merge(array, start, temp, temp + 1, end);

}

void Sort::merge(vector<int> &array, int start1, int end1, int start2, int end2)
{
	vector<int> C;
	int start = start1;
	int end = end2;

	while (start1 <= end1 && start2 <= end2)
	{

		if (array[start1] <= array[start2])
		{
			C.push_back(array[start1]);
			start1++;
		}
		else
		{
			C.push_back(array[start2]);
			start2++;
		}
	}

	while (start1 <= end1)
	{
		C.push_back(array[start1]);
		start1++;
	}

	while (start2 <= end2)
	{
		C.push_back(array[start2]);
		start2++;
	}

	int j = 0;

	for (int i = start; i <= end; i++)
	{
		array[i] = C[j];
		j++;
	}

}


void Sort::InsertionSort()
{

}