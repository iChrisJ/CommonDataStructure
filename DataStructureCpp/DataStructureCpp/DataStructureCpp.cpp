// DataStructureCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "MaxHeap.h"
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <vector>

#include "FileOps.h"
#include "BST.h"
#include "SequenceST.h"

using namespace std;

int main()
{

#pragma region MaxHeap test
	/*
	MaxHeap<int> maxheap = MaxHeap<int>(100);

	srand(time(NULL));
	for (int i = 0; i < 1; i++) {
		maxheap.insert(rand() % 100);
	}

	while (!maxheap.isEmpty())
		cout << maxheap.extractMax() << " ";
	cout << endl;
	*/

#pragma endregion MaxHeap test

#pragma region Binary search test
	/*
	string filename = "bible.txt";
	vector<string> words;
	if (FileOps::readFile(filename, words))
	{
		cout << "There are totally " << words.size() << " words in " << filename << endl;
		cout << endl;

		// test BST
		time_t startTime = clock();
		BST<string, int> bst = BST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++)
		{
			int *res = bst.search(*iter);
			if (res == NULL)
				bst.insert(*iter, 1);
			else
				(*res)++;
		}

		cout << "'god' : " << *bst.search("god") << endl;
		time_t endTime = clock();
		cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
		cout << endl;

		// test SST
		startTime = clock();
		SequenceST<string, int> sst = SequenceST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++)
		{
			int *res = sst.search(*iter);
			if (res == NULL)
				sst.insert(*iter, 1);
			else
				(*res)++;
		}

		cout << "'god' : " << *sst.search("god") << endl;

		endTime = clock();
		cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
	}
	*/
#pragma endregion Binary search test

#pragma region Tree Traverse


#pragma endregion Tree Traverse

	return 0;
}

