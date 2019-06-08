
#include<fstream>
#include"syslogreader.h"
#include"tcp_monitor.h"
using namespace std;


int main(int argc, char *argv[])
{
    /*choose task by parsing argc*/
    if(argc == 3 && strcmp(argv[1],"-s") ==0 )
    {
        /*run parser that find all logs with dst_Port*/
        int dst_Port = atoi(argv[2]);
        findLogs_dstPort(dst_Port);
    }else if(argc == 4 && strcmp(argv[1],"-r") == 0)
    {
        /*run client that will connect to server*/
        TCP_Monitor Monitor_TCP( argv[2] , atoi(argv[3]) );
        while (!Monitor_TCP.establish_Connection())
        {
            /*repeate if connection fail*/
            sleep(1);
        }
    }
    return 0;
}

