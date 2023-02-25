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
	parser().setDescription("waits for a background process to complete"); // setting description
	parser().registerPositional("PID", "wait for the process associated with the given PID"); //description for pid argument
}

Wait::~Wait()
{
}

Wait::Result Wait::exec()
{
	ProcessID pid = (atoi(arguments().get("PID"))); //gathers input after wait as PID argument
	int statloc; //initialize status location
	//if waitpid does not run prompt an error
	if(waitpid(pid, &statloc, 0) == -1) { //waitpid structure is according to parameters given from wait.h (PID, Status Location, Optional Flags)
		ERROR("invalid PID`" << arguments().get("PID") << "'"); //gets the pid and prompts an error saying that it is invalid
		return InvalidArgument;
	}
	else { //otherwise return success
		return Success; 
	}

	
}

