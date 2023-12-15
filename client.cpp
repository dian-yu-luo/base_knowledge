#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: client <server_ip>:<server_port>" << std::endl;
        return 1;
    }

    // 解析服务器IP和端口
    char* serverIp = strtok(argv[1], ":");
    char* serverPortStr = strtok(nullptr, ":");
    if (serverIp == nullptr || serverPortStr == nullptr)
    {
        std::cerr << "Invalid server address" << std::endl;
        return 1;
    }

    int serverPort = std::stoi(serverPortStr);

    // 创建套接字
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0)
    {
        std::cerr << "socket failed" << std::endl;
        return 1;
    }

    // 连接服务器
    sockaddr_in serverAddr = { 0 };
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(serverIp);
    serverAddr.sin_port = htons(serverPort);

    int result = connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    if (result < 0)
    {
        std::cerr << "connect failed" << std::endl;
        close(clientSocket);
        return 1;
    }

    std::cout << "Connected to server: " << inet_ntoa(serverAddr.sin_addr) << ":" << ntohs(serverAddr.sin_port) << std::endl;

    // 发送数据到服务器并接收回复
    char buffer[1024] = "你好!";
    ssize_t sendLen = send(clientSocket, buffer, strlen(buffer), 0);
    if (sendLen < 0)
    {
        std::cerr << "send failed" << std::endl;
        close(clientSocket);
        return 1;
    }

    ssize_t recvLen = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (recvLen > 0)
    {
        std::cout << "Received data from server: " << buffer << std::endl;
    }

    // 关闭套接字
    close(clientSocket);

    return 0;
}
