#include"syslogreader.h"

void findLogs_dstPort(const int dst_Port)
{
    /*open file and search needed dst port*/
    std::ifstream log_File ;
    log_File.open("/var/log/syslog");
    std::string readLine;
    while(std::getline (log_File , readLine))
    {
        if (readLine.find("TCP_Monitor")!=std::string::npos)
        {
            if (readLine.find(">") !=std::string::npos)
            {
                if(dst_Port == atoi(readLine.substr( readLine.find(">")+1,readLine.size()-1).c_str()))
                {
                    std::cout<<readLine<<std::endl;
                }
            }
        }
    }
}
