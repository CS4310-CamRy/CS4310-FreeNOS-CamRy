#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <ProcessClient.h> //check system headers
#include <sys/wait.h>
#include "Wait.h" //in the same directory

Wait::Wait(int argc, char **argv)
	: POSIXApplication(argc, argv)
{
	parser().set Description("wait");
	parser().registerPositional("PID", "wait");
}

Wait::~Wait()
{
}

Wait::Result Wait::exec()
{
	//get the pid with ProcessClient
	ProcessClient process;
	ProcessID pid;

	if() {
		//call waitpid here
		//waitpid has 3 parameters: pid, int, int
		waitpid(pid, 0, 0);
	}
	else {
		//if the pid does not exist, return an error message
		return InvalidArgument;
	}

	return Success;
}

