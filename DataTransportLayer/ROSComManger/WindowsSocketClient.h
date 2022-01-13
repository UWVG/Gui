/**********************************************************************
**File name:WindowsSocketClient.h
**Author:hexiao<hexiao.hrbeu.edu.cn>    Version:1.0    Date:2020.12.24
**Description:Windows socket class 
**GPL-3.0 License Usage
**********************************************************************/
#ifndef WINDOWS_SOCKET_CLIENT_H_
#define WINDOWS_SOCKET_CLIENT_H_
extern "C"
{
    #include <stdint.h>
}
class WindowsSocketClient
{
public:
        WindowsSocketClient();
        WindowsSocketClient(int port, char *addr);
        ~WindowsSocketClient();

        int init();
        int read();
        void write(const unsigned char *data,int length);
        void set_port(int port);
        void set_addr(char* addr);
        unsigned long time();

private:
        unsigned int    socketClient;
        int             port;
        char            *addr;

};


#endif
