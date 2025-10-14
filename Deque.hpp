//
// Created by L00711689 on 10/13/2025.
//

#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <string>

class Deque
{
	const static int SIZE = 20;
	int size;
	int count;
	int head;
	int tail;
	int * theDeque;
public:
	Deque(int size = SIZE);
	~Deque();
	void addTail(int value);
	int removeHead();
	std::string dumpArray();
	void resize();
	std::string listQueue();
	bool isEmpty();

	// Advanced Methods
	void addHead(int value);
	int removeTail();

	// Thinking Problem
	void solveThink(int* values, int numValues);
};

#endif //DEQUE_HPP
