//
// Created by L00711689 on 10/13/2025.
//

#include "Deque.hpp"
#include <iostream>


Deque::Deque(int size) : size(size), count(0), head(-1), tail(-1)
{
	theDeque = new int [size];
}

Deque::~Deque()
{
	delete[] theDeque;
}

void Deque::addTail(int value)
{
	if (count >= size)
	{
		resize();
	}
	tail++;
	tail %= size;
	count++;
	theDeque[tail] = value;

}

int Deque::removeHead()
{
	if (count == 0)
	{
		throw std::out_of_range("Array is empty in removeHead");
	}
	head++;
	count--;
	head %= size;
	return theDeque[head];


}

std::string Deque::dumpArray()
{
	for (int i = 0; i < count; i++)
	{
		std::cout << theDeque[i] << " ";
	}
	return "";
}

void Deque::resize()
{
	int* biggerDeque = new int[size*2];
	int afterTail = count - tail;
	for (int i = 0; i < count; i++)
	{
		if (i <= afterTail)
		{
			biggerDeque[i] = theDeque[(head+i+1) % size];
		}
		else
		{
			biggerDeque[i] = theDeque[i-afterTail+1];
		}
	}
	delete[] theDeque;
	theDeque = biggerDeque;
	head = -1, tail = count-1;
	size *= 2;
}

std::string Deque::listQueue()
{
	int afterTail = count - tail;
	for (int i = 0; i < count; i++)
	{
		if (i <= afterTail)
		{
			std::cout << theDeque[(head+i+1) % size] << " ";
		}
		else
		{
			std::cout << theDeque[i-afterTail+1] << " ";
		}
	}
	return "";
}

bool Deque::isEmpty()
{
	if (tail == head && count == 0)
	{
		head, tail = 0;
		return true;
	}
	return false;
}

void Deque::addHead(int value)
{
	if (count >= size)
	{
		resize();
	}

	if (head <0)
	{
		head = size-1;
	}

	count++;
	theDeque[head] = value;
	head--;
}

int Deque::removeTail()
{
	if (count == 0)
	{
		throw std::out_of_range("Array is empty in removeTail");
	}
	count--;
	if (tail <0)
	{
		tail = size-1;
	}
	int value = theDeque[tail];
	tail--;
	return value;
}

void Deque::solveThink(int *values, int numValues)
{
	Deque sorter[numValues];
	for (int i= 0; i < numValues; i++)
	{
		sorter->addTail(values[i]);
	}
	for(int j = 0; j < numValues; j++)
	{
		 theDeque[j] = sorter->removeTail();
	}
	count = 5;
}
