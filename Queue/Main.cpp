#include <iostream>
#include "queue.h"

int main()
{
	queue<int> int_queue1(20);
	queue<int> int_queue2(20);

	int_queue1.push(20);
	int_queue1.push(40);
	int_queue1.push(50);
	int_queue1.push(80);

	int_queue2.push(100);
	int_queue2.push(120);
	int_queue2.push(150);

	queue<int> int_queue3 = int_queue1.merge(int_queue2);
	// int_queue1.resize(2); // Throws an exception
	while (!int_queue3.empty())
	{
		std::cout << int_queue3.front() << std::endl;
		int_queue3.pop();
	}
}