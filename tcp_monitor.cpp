#include "tcp_monitor.h"

bool TCP_Monitor::createSocket()
{
    /*Try create socket and init it*/
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        std::cerr<<"Socket";
        return false;
    }
    dst_Addr.sin_family = AF_INET;
    dst_Addr.sin_port = htons(dst_Port);
    dst_Addr.sin_addr = *(reinterpret_cast<struct in_addr *>(dstHost->h_addr));
    bzero(&(dst_Addr.sin_zero), 8);
    return true;
}

uint16_t TCP_Monitor::get_Src_Port()
{
    /*get src socket by struct*/
    socklen_t addr_size = sizeof(dst_Addr);
    getsockname(sockfd, reinterpret_cast<struct sockaddr *>(&dst_Addr), &addr_size);
    return  ntohs(dst_Addr.sin_port);
}

TCP_Monitor::TCP_Monitor(const char *domain_Name_or_Ip , const uint16_t dstPort)
    :dst_Port(dstPort)
{
    //explicit constructor to avoid wrong usage
    //call gethostbyname to get Ip address if input domain name
    dstHost = gethostbyname(domain_Name_or_Ip);
}

bool TCP_Monitor::establish_Connection()
{
    if( !createSocket() )
    {
        //if can't create socket get out
        return false;
    }
    if (connect(sockfd, reinterpret_cast<struct sockaddr *>(&dst_Addr),
                sizeof(struct sockaddr)) == -1) {
        //if can't connect to server  get out ,too
        std::cerr<<"connect"<<std::endl;
        return false;
    }
    //generate massage
    std::string massage = std::to_string( get_Src_Port() ) + ">" + std::to_string(dst_Port);
    write_SysLog(massage.c_str());
    std::cout<<"Connect Successfully."<<std::endl;
    //close socket
    close(sockfd);
    return true;
}
