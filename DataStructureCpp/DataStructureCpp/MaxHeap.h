#pragma once

#include <iostream>
#include <cassert>

using namespace std;

template<typename Item>
class MaxHeap
{
private:
	Item * data;
	int count;
	int capacity;

#pragma region Private Methods

	void shiftUp(int index)
	{
		while (index > 0 && data[(index - 1) / 2] < data[index])
		{
			swap(data[(index - 1) / 2], data[index]);
			index = (index - 1) / 2;
		}
	}

	void shiftDown(int index)
	{
		while (index * 2 + 1 < this->count)
		{
			int k = index * 2 + 1;
			// data[k] is the larger one between data[index * 2 + 1] and data[index * 2 + 2]
			if (k + 1 < this->count && data[k] < data[k + 1])
				k += 1;

			if (data[k] < data[index])
				break;

			// If data[index] is smaller than its children, swap it with the larger child and continue the loop.
			swap(data[index], data[k]);
			index = k;
		}
	}

#pragma endregion Private Methods

public:
#pragma region Construction and Deconstruction

	MaxHeap(int capacity)
	{
		data = new Item[capacity];
		count = 0;
		this->capacity = capacity;
	}

	~MaxHeap()
	{
		delete[] data;
	}

#pragma endregion Construction and Deconstruction

#pragma region Public Methods

	int size()
	{
		return this->count;
	}

	bool isEmpty()
	{
		return this->count == 0;
	}

	void insert(Item item)
	{
		assert(count + 1 <= capacity);

		data[count] = item;
		this->count++;
		this->shiftUp(count - 1);
	}

	Item extractMax()
	{
		assert(this->count > 0);

		Item ret = data[0];
		swap(data[0], data[this->count - 1]);
		this->count--;

		this->shiftDown(0);

		return ret;
	}

	Item getMax()
	{
		return this->count == 0 ? NULL : data[0];
	}
#pragma endregion Methods

};
