#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool test = false;

void insertionSort(int arr[], int high)
{
	int index1;
	int index2;
	int key;
	
	for (index1 = 1; index1 < high; index1++)
	{
		key = arr[index1];
		index2 = index1 - 1;
		while (index2 >= 0 && arr[index2] > key)
		{
			arr[index2 + 1] = arr[index2];
			arr[index2] = key;
			index2--;
		}
	}
}


int main()
{
	int caseNum = 0;
	ifstream din;
	if (test)
	{
		din.open("input.txt");
		din >> caseNum;
		//din.ignore();
	}
	else
	{
		cin >> caseNum;
		//cin.ignore();
	}
	for (int i = 0; i < caseNum; i++)
	{
		int relNum = 0;
		if (test)
			din >> relNum;
		else
			cin >> relNum;
		string line;
		int streetArr[5001] = { 0 };

		int size = 0;
		for (int j = 0; j < relNum; j++)
		{
			if (test)
				din >> streetArr[j];
			else
				cin >> streetArr[j];
			size++;
		}

		int median = size / 2;
		insertionSort(streetArr, size);

		int distance = 0;
		for (int j = 0; j < size; j++)
		{
			if (j != median)
			{
				distance += abs(streetArr[median] - streetArr[j]);
			}
		}

		cout << distance << endl;
		//for (int j = 0; j < relNum; j++)
		//{
		//	cout << streetArr[j] << endl;
		//	//streetArr[j-1] = line[j];
		//}
		//cout << endl;
	}

	return 0;
}