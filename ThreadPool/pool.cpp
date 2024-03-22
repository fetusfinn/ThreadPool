//
//	pool.cpp
//
#include "pool.h"

CThreadPool::CThreadPool() : m_iNumThreads(std::thread::hardware_concurrency()), m_iTasksProcessed(0)
{
	for (int i = 0; i < m_iNumThreads; i++)
	{
		m_arrThreads.push_back(std::thread(&CThreadPool::WorkerThread, this));
	}
}

CThreadPool::~CThreadPool()
{
	Stop();
}

//
//
//
void CThreadPool::Submit(CTask _rTask)
{
	m_arrTaskQueue.Push(_rTask);
}

//
//
//
void CThreadPool::Stop()
{
	m_bFinished = true;

	m_arrTaskQueue.UnblockAll();

	for (int i = 0; i < m_iNumThreads; i++)
	{
		if (m_arrThreads.at(i).joinable())
		{
			m_arrThreads.at(i).join();
		}
	}
}

//
//
//
int CThreadPool::TasksProcessed()
{
	return m_iTasksProcessed;
}

//
//
//
void CThreadPool::WorkerThread()
{
	CTask rTask;
	while (!m_bFinished)
	{
		if (m_arrTaskQueue.Pop(rTask))
		{
			rTask.DoWork();
			m_iTasksProcessed++;
		}
	}
}
