//
//	pool.h
//
#pragma once

#include <vector>
#include <atomic>
#include <thread>

#include "safe_queue.h"
#include "task.h"

class CThreadPool
{
private:

	std::vector<std::thread> m_arrThreads;
	CSafeQueue<CTask>	m_arrTaskQueue;

	std::atomic_bool	m_bFinished;
	std::atomic_int		m_iTasksProcessed;
	unsigned int		m_iNumThreads;

	void WorkerThread();

public:

	CThreadPool();
	~CThreadPool();

	void Submit(CTask _rTask);
	void Stop();

	int TasksProcessed();

};
