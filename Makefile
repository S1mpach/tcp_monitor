all:
	g++ -std=c++11 main.cpp logger.cpp logger.h syslogreader.cpp syslogreader.h tcp_monitor.cpp tcp_monitor.h  -o TCP_Monitor
