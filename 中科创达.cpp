/*
 * @Description:
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-10-26 16:34:28
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-10-26 16:37:27
 */
// #include<iostream>
// #include<functional>

// int a=10;

// std::function<void()> GetFunc() {
//     int a = 20;
//     auto func = [&a]() {
//         std::cout << a << std::endl;
//     };
//     return func;
// }

// int main() {
//     a++;
//     GetFunc()();
// }


#include <iostream>

class Base {
public:
Base() {
    std::cout << 1 << std::endl;
}

Base(Base&& other) {
    std::cout << 2 << std::endl;
}

Base(const Base& other) {
    std::cout << 3 << std::endl;
}

Base& operator=(Base&& other) {
    std::cout << 4 << std::endl;
    return *this;
}

Base& operator=(const Base& other) {
    std::cout << 5 << std::endl;
    return *this;
}
};

int main() {
    Base base1;
    Base base2 = base1;
    Base base3(base2);
    Base base4(std::move(base3));
    Base base5;
    base5 = base4;
    Base base6;
    base6 = std::move(base5);
    return 0;
}