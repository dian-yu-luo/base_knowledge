#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    // 创建套接字
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
    {
        std::cerr << "socket failed" << std::endl;
        return 1;
    }

    // 绑定地址和端口
    sockaddr_in serverAddr = { 0 };
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8888);

    int result = bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    if (result < 0)
    {
        std::cerr << "bind failed" << std::endl;
        close(serverSocket);
        return 1;
    }

    // 监听连接
    result = listen(serverSocket, 5);
    if (result < 0)
    {
        std::cerr << "listen failed" << std::endl;
        close(serverSocket);
        return 1;
    }

    std::cout << "Server listening on port 8888..." << std::endl;

    // 接受客户端连接
    sockaddr_in clientAddr = { 0 };
    socklen_t clientAddrLen = sizeof(clientAddr);
    int clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientAddrLen);
    if (clientSocket < 0)
    {
        std::cerr << "accept failed" << std::endl;
        close(serverSocket);
        return 1;
    }

    std::cout << "Client connected: " << inet_ntoa(clientAddr.sin_addr) << ":" << ntohs(clientAddr.sin_port) << std::endl;

    // 接收数据并回复客户端
    char buffer[1024];
    ssize_t recvLen = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (recvLen > 0)
    {
        std::cout << "Received data from client: " << buffer << std::endl;

        ssize_t sendLen = send(clientSocket, buffer, recvLen, 0);
        if (sendLen < 0)
        {
            std::cerr << "send failed" << std::endl;
        }
    }

    // 关闭套接字
    close(clientSocket);
    close(serverSocket);

    return 0;
}
