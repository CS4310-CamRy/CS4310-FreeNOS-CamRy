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
	parser().setDescription("wait");
	parser().registerPositional("PID", "wait");
}

Wait::~Wait()
{
}

Wait::Result Wait::exec()
{
	//get the pid with ProcessClient
	ProcessClient process;
	ProcessID pid = (atoi(arguments().get("PID"))); //gathers input as PID argument
	int statloc;
	//if pid does not run prompt an error, waitpid structure is according to parameters given from wait.h (PID, Status Location, Optional Flags)
	if(waitpid(pid, &statloc, 0) == -1) { 
		ERROR("invalid PID`" << arguments().get("PID") << "'");
		return InvalidArgument;
	}
	else { //otherwiser return success
		return Success; 
	}

	
}

