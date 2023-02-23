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
	ProcessClient::Info info; 
	ProcessClient::Result res = process.processInfo(pid,info); //using given pid to gather info on the processs, also allows us to know if the pid is found

	if(res == ProcessClient::Success) { //if the PID is found using the result codes from ProcessClient
		//call waitpid here
		//waitpid has 3 parameters: pid, int, int
		waitpid(pid, 0, 0); //according to parameters given from wait.h (PID, Status Location, Optional Flags)
	}
	else { //prompt user with error
		//if the pid does not exist, return an error message
		ERROR("invalid PID`" << arguments().get("PID") << "'");
		return InvalidArgument;
	}

	return Success;
}

