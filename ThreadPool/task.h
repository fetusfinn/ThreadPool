//
//
//
#pragma once

class CTask
{
private:

	int m_iData;

public:

	CTask() : m_iData(0)
	{
		
	}

	CTask(int _iData) : m_iData(_iData)
	{
		
	}

	~CTask()
	{
		
	}

	virtual void operator()()
	{
		DoWork();
	}

	virtual void DoWork()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds((rand() % 1000) + 200));

		printf("Task %i complete!\n", m_iData);
	}

};