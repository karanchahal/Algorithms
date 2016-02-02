#include "sort.h"

int Sort::mergeSort(vector<int> &array, int start, int end)
{
	if (start == end)
	{
		return 0;
	}


	int temp = (start + end) / 2;

	int one = mergeSort(array, start, temp);
	int two = mergeSort(array, temp + 1, end);
	int three = merge(array, start, temp, temp + 1, end);

	return one + two + three;

}

int Sort::merge(vector<int> &array, int start1, int end1, int start2, int end2)
{
	vector<int> C;
	int count = 0;
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
			count += end1 - start1 + 1;
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


	return count;
}


void Sort::InsertionSort()
{

}