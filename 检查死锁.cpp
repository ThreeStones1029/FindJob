/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-10-03 17:24:52
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-10-03 17:38:39
 */
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtxA;
mutex mtxB;

void taskA() {
    lock_guard<mutex> lockA(mtxA);
    cout << "Thread A get Lock A!" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    lock_guard<mutex> lockB(mtxB);
    cout << "Thread A get Lock A and B!" << endl;
    cout << "Thread A relese all source!" << endl;
}

void taskB() {
    lock_guard<mutex> lockB(mtxB);
    cout << "Thread B get Lock B!" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    lock_guard<mutex> lockA(mtxA);
    cout << "Thread B get Lock B and A!" << endl;
    cout << "Thread B relese all source!" << endl;
}

int main() {

    thread t1(taskA);
    thread t2(taskB);
    t1.join();
    t2.join();
    return 0;
}


