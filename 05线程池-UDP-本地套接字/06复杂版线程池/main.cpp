#include <unistd.h>
#include <string.h>

#include "ThreadLoop.h"

using namespace std;

void proc(
	const pthread_t& thrId,
	const TaskId& tskId,
	void* const& arg)
{
	char buf[128] = { 0 };

	sprintf(buf, "%u[%u]\n", thrId, tskId);
	write(STDOUT_FILENO, buf, strlen(buf));
	
	sleep(2);
}

int main()
{
	ThreadLoop tl;

	for (int i = 0; i < 20; i++)
	{
		tl.addTsk(proc, NULL);
	}
	cout << "add completed" << endl;
	sleep(10);
	for (int i = 0; i < 10; i++)
	{
		tl.addTsk(proc, NULL);
	}
	cout << "add completed" << endl;
	while (true)
	{

	}

	return 0;
}