#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ProcessClient.h>
#include "Renice.h"
#include "sys/renice.h"

Renice::Renice(int argc, char **argv): POSIXApplication(argc, argv)
{
    parser().setDescription("Changes priority level");
    parser().registerFlag('n', "level", "change priority level");
    parser().registerPositional("PID", "level");
    parser().registerPositional("LEVEL", "desired priority level");
}

//exec() function
Renice::Result Renice::exec()
{
    if(arguments().get("level")) {
        ProcessID pid = (atoi(arguments().get("PID")));
        int level = (atoi(arguments().get("LEVEL")));

        ProcessClient::Info info;
        const ProcessClient::Result result = process.processInfo(pid, info);

        if(level < 5 || level > 1) {
            if(renicepid(pid, level, 0, 0) == -1) {
                ERROR("invalid PID`" << arguments().get("PID") << "'");
                return InvalidArgument;
            }
            else {
                return Success;
            }
        }
        else {
            ERROR("Invalid priority " << pid)
            return InvalidArgument;
        }
    }

    return Success;
}