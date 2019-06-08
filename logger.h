#ifndef LOGGER_H
#define LOGGER_H

#include "syslog.h"
#include <chrono>

const char* getCurrentTime();
void write_SysLog(const char *massage);

#endif // LOGGER_H
