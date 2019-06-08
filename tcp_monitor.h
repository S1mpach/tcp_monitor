#ifndef TCP_MONITOR_H
#define TCP_MONITOR_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include<iostream>

#include"logger.h"

class TCP_Monitor
{
private:
    struct hostent *dstHost;
    struct sockaddr_in dst_Addr;
    int sockfd;
    uint16_t src_Port;
    uint16_t dst_Port;
    TCP_Monitor( const TCP_Monitor& ) = delete;
    TCP_Monitor& operator=( TCP_Monitor& ) = delete;
    bool createSocket();
    uint16_t get_Src_Port();

public:
    explicit TCP_Monitor(const char *domain_Name_or_Ip , const uint16_t dstPort);
    ~TCP_Monitor() = default;
    bool establish_Connection();
};




#endif // TCP_MONITOR_H
