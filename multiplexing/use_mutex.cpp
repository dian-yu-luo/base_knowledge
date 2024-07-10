#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
// 在这里需要加锁,锁使用方法也比较统一
/* 
定义锁
锁上,临界区工作
 */

int main() {
    std::vector<int> arr;
    std::mutex mtx;
    std::thread t1([&] {
        for (int i = 0; i < 1000; i++) {
            mtx.lock();
            arr.push_back(1);
            mtx.unlock();
        }
    });
    std::thread t2([&] {
        for (int i = 0; i < 1000; i++) {
            mtx.lock();
            arr.push_back(2);
            mtx.unlock();
        }
    });
    t1.join();
    t2.join();
    return 0;
}
