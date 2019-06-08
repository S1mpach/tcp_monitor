#include"logger.h"

const char* getCurrentTime()
{
    /*make format of ISO 8601 */
    auto start = std::chrono::system_clock::now();
    time_t time =  std::chrono::system_clock::to_time_t(start);
    char *buffer = new char[80];
    struct tm * timeinfo;
    timeinfo = localtime (&time);
    strftime (buffer, 80,"%Y-%m-%d %H:%M:%S",timeinfo);
    return buffer;

}

void write_SysLog(const char *massage)
{
    /*open and write to syslog*/
    openlog("TCP_Monitor", 0, LOG_USER);
    syslog(LOG_NOTICE, "[%s] %s", getCurrentTime() , massage);
    closelog();
}
