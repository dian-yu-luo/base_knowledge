#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>

int main() {
    std::vector<int> arr;
    std::mutex mtx;
    std::thread t1([&] {
        for (int i = 0; i < 1000; i++) {
            /* lock_guard 的写法,直接在作用域中完成锁的任务,会自动析构的 */
            std::lock_guard grd(mtx);
            arr.push_back(1);
        }
    });
    std::thread t2([&] {
        for (int i = 0; i < 1000; i++) {
            std::lock_guard grd(mtx);
            arr.push_back(2);
        }
    });
    t1.join();
    t2.join();
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout<<arr[i]<<" ";
    }
    
    return 0;
}
