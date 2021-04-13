#pragma once
#include "MThread.h"
#include <vector>

class MThreadManager
{
	MThreadManager()
	{};
	~MThreadManager()
	{};
private:
	std::vector<MThread*> mThreadPool;
};

