#include<iostream>
#include<vector>
#include "src/Sorting/sort.h"

using namespace std;


int main()
{
	vector<int> array = { 5, 4,3,1,2};

	Sort s;
	int numberOfInversions = s.mergeSort(array, 0, array.size() - 1);

	cout << "Number Of Inversions are: "<<numberOfInversions << endl;

	cout << "Sorted Array is: " << endl;

	for (int i : array)
	{
		cout << i << " ";
	}

	cout << endl;


	system("PAUSE");
	return 0;
}