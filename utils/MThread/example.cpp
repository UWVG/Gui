#include "MThread.h"

int main()
{
	MThread *a = new MThread;
	a->start();
	delete a;
	while (1);
	return 0;
}