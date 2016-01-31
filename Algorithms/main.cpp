#include<iostream>
#include<vector>
#include "src/Sorting/sort.h"

using namespace std;


int main()
{
	vector<int> array = {1,1,1,1, 1,-1};

	Sort S;
	S.mergeSort(array, 0, array.size() - 1);

	for (int i : array)
	{
		cout << i << " ";
	}
	cout << endl;

	system("PAUSE");
	return 0;
}