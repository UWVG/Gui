#ifndef M_THREAD_H_
#define M_THREAD_H_

#include <Windows.h>

class MThread 
{
public:
	MThread()
	{
		hThread = nullptr;
		hMutex = CreateMutex(NULL, false,NULL);
	};
	~MThread()
	{
		if (hThread)
		{
			CloseHandle(hThread);
		}
		if (hMutex)
		{
			CloseHandle(hMutex);
		}
	};

	static DWORD WINAPI mrun(LPVOID lpParameter)
	{
		return ((MThread*)lpParameter)->run(lpParameter);
	}

	void start()
	{
		hThread = CreateThread(NULL, 0, mrun, (LPVOID)this, 0, NULL);
	}

	virtual  DWORD WINAPI run(LPVOID lpParameter)
	{
		return 0;
	};

private:
	HANDLE hThread;
	HANDLE hMutex;
};

#endif

