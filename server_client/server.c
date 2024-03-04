// Server side C/C++ program to demonstrate Socket
// programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080 // 指定默认端口
// 这里是所有的服务器要完成的内容
int main(int argc, char const *argv[])
{
	int server_fd, new_socket;	// 指定socket 是一个文件,有对应的文件描述符 server_fd
	ssize_t valread;			// 实际读取到的字符数
	struct sockaddr_in address; // 指定地址
	int opt = 1;
	socklen_t addrlen = sizeof(address); // 地址长度
	char buffer[1024] = {0};			 // 网络中的字符缓冲区
	char *hello = "Hello from server";	 // 要发送的信息

	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) // 优秀的写法,能够同时返回值和进行判断
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	// Forcefully attaching socket to the port 8080
	// socket 的信息
	if (setsockopt(server_fd, SOL_SOCKET,
				   SO_REUSEADDR | 15, &opt,
				   sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	// 设置地址,地址和socket是两回事,两件事,没有先后次序要求
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Forcefully attaching socket to the port 8080
	// 把地址和对应的socket 练习起来
	if (bind(server_fd, (struct sockaddr *)&address,
			 sizeof(address)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	// 开始阻塞监听
	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
							 &addrlen)) < 0)
	{
		perror("accept");
		exit(EXIT_FAILURE);
	}
	valread = read(new_socket, buffer,
				   1024 - 1); // subtract 1 for the null
							  // terminator at the end
	printf("%s\n", buffer);
	send(new_socket, hello, strlen(hello), 0);
	printf("Hello message sent\n");

	// closing the connected socket
	close(new_socket);
	// closing the listening socket
	close(server_fd);
	return 0;
}
