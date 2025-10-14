//
// Created by L00711689 on 10/13/2025.
//

#include "Deque.hpp"
#include <iostream>
#include <deque>

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

		/*for (int j = 0; j < size; j++)
		{
			biggerDeque[j] = theDeque[(tail-j) % size];
		}*/
		if (i <= afterTail)
		{
			biggerDeque[i] = theDeque[(head+i) % size];
		}
		else
		{
			biggerDeque[i] = theDeque[i-afterTail+1];
		}
	}
	delete[] theDeque;
	theDeque = biggerDeque;
	head = -1, tail = count;
	size *= 2;
}

std::string Deque::listQueue()
{
	int afterTail = count - tail;
	for (int i = 0; i < count; i++)
	{

		/*for (int j = 0; j < size; j++)
		{
			biggerDeque[j] = theDeque[(tail-j) % size];
		}*/
		if (i <= afterTail)
		{
			std::cout << theDeque[(head+i) % size];
		}
		else
		{
			std::cout << theDeque[i-afterTail+1];
		}
	}
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

}

int Deque::removeTail()
{
	return 7;
}

void Deque::solveThink(int *values, int numValues)
{

}
