/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-09-24 17:06:04
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-09-24 22:16:56
 */

// 读写锁
// #include <iostream>
// #include <thread>
// #include <shared_mutex>

// std::shared_mutex rw_lock;
// int shared_data = 0;

// void read_data() {
//     rw_lock.lock_shared(); // 获取读锁
//     std::cout << "Reading shared data: " << shared_data << std::endl;
//     rw_lock.unlock_shared(); // 释放读锁
// }

// void write_data(int value) {
//     rw_lock.lock(); // 获取写锁
//     shared_data = value;
//     std::cout << "Writing shared data: " << shared_data << std::endl;
//     rw_lock.unlock(); // 释放写锁
// }

// int main() {
//     std::thread writer1(write_data, 10);
//     std::thread reader1(read_data);
//     std::thread reader2(read_data);
//     std::thread writer2(write_data, 20);

//     writer1.join();
//     reader1.join();
//     reader2.join();
//     writer2.join();

//     return 0;
// }



// 互斥锁
// #include <iostream>
// #include <thread>
// #include <mutex>

// std::mutex mtx;
// int counter = 0;

// void increment_counter() {
//     mtx.lock(); // 获取锁
//     ++counter;
//     std::cout << "Counter: " << counter << std::endl;
//     mtx.unlock(); // 释放锁
// }

// int main() {
//     std::thread t1(increment_counter);
//     std::thread t2(increment_counter);
//     std::thread t3(increment_counter);

//     t1.join();
//     t2.join();
//     t3.join();

//     return 0;
// }


// 条件变量
// #include <iostream>
// #include <thread>
// #include <mutex>
// #include <condition_variable>

// std::mutex mtx;
// std::condition_variable cv;
// bool ready = false;

// void print_message(int id) {
//     std::unique_lock<std::mutex> lock(mtx);
//     cv.wait(lock, []{ return ready; }); // 等待条件
//     std::cout << "Thread " << id << " is executing\n";
// }

// void set_ready() {
//     std::this_thread::sleep_for(std::chrono::seconds(1));
//     std::lock_guard<std::mutex> lock(mtx);
//     ready = true;
//     cv.notify_all(); // 唤醒所有等待的线程
// }

// int main() {
//     std::thread t1(print_message, 1);
//     std::thread t2(print_message, 2);

//     std::thread notifier(set_ready);

//     t1.join();
//     t2.join();
//     notifier.join();
//     return 0;
// }


// 自旋锁

#include <iostream>
#include <thread>
#include <atomic>

std::atomic_flag spin_lock_flag = ATOMIC_FLAG_INIT;

void spin_lock() {
    while (spin_lock_flag.test_and_set(std::memory_order_acquire)); // 自旋等待
}

void spin_unlock() {
    spin_lock_flag.clear(std::memory_order_release); // 释放锁
}

int counter = 0;

void increment_counter() {
    spin_lock(); // 获取自旋锁
    ++counter;
    std::cout << "Counter: " << counter << std::endl;
    spin_unlock(); // 释放自旋锁
}

int main() {
    std::thread t1(increment_counter);
    std::thread t2(increment_counter);

    t1.join();
    t2.join();

    return 0;
}