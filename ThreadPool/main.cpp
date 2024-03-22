//
//
//
#include <iostream>

#include "pool.h"

int main()
{
	int num_threads = std::thread::hardware_concurrency();

	std::cout << "Num threads : " << num_threads << "\n";

	const int totalTasks = 50;

	CThreadPool rPool;

	for (int i = 0; i < totalTasks; i++)
	{
		rPool.Submit(CTask(i));
	}

	std::cout << "\n\n";

	while (rPool.TasksProcessed() < totalTasks)
	{
		
	}

	rPool.Stop();

	std::cout << "Done!\n";

	return 0;
}