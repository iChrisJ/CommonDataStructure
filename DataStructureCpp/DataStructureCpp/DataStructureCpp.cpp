// DataStructureCpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "MaxHeap.h"
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	MaxHeap<int> maxheap = MaxHeap<int>(100);

	srand(time(NULL));
	for (int i = 0; i < 1; i++) {
		maxheap.insert(rand() % 100);
	}

	while (!maxheap.isEmpty())
		cout << maxheap.extractMax() << " ";
	cout << endl;

	return 0;
}

