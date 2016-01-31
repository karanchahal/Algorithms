#pragma once
#include<vector>

using namespace std;

class Sort
{

	public:
		void mergeSort(std::vector<int> &array,int start,int end);
		void InsertionSort();
	private:
		void merge(std::vector<int> &array, int start1, int end1, int start2, int end2);

};
