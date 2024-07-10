#include <iostream>
#include <thread>
#include <string>

void download(std::string file) {
    for (int i = 0; i < 10; i++) {
        std::cout << "Downloading " << file
                  << " (" << i * 10 << "%)..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
    std::cout << "Download complete: " << file << std::endl;
}

void interact() {
    std::string name;
    std::cin >> name;
    std::cout << "Hi, " << name << std::endl;
}

void myfunc() {
    std::thread t1([&] {
        download("hello.zip");
    });
    t1.join();
    // 在函数里面去进行多线程操作,就要注意这一点,有可能导致出现特殊的问题
    // 退出函数体时，会销毁 t1 线程的句柄！
}

int main() {
    myfunc();
    interact();
    return 0;
}
