#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "Wait.h"

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
}

