#include <iostream>
#include <unistd.h>

int main()
{
    pid_t pid = fork();

    if (pid == -1) 
    {
        // Error occurred
        std::cerr << "Failed to fork\n";
        return 1;
    }
    else if (pid == 0) // 创建的项目
    {
        // Child process
        std::cout << "Child process. PID: " << getpid() << ", Parent PID: " << getppid() << std::endl;
    }
    else
    {
        // Parent process
        std::cout << "Parent process. PID: " << getpid() << ", Child PID: " << pid << std::endl;
    }

    return 0;
}
