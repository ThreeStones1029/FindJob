/*
 * @Description: 
 * @version: 
 * @Author: 帅磊240108 2158097607@xiaomi.com
 * @Date: 2024-08-31 19:28:17
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-08-31 19:34:09
 */
// alignas 生效的情况
#include <iostream>


struct Info {
  uint8_t a;
  uint16_t b;
  uint8_t c;
};

struct alignas(4) Info2 {
  uint8_t a;
  uint16_t b;
  uint8_t c;
};


int main() {
    Info info;
    std::cout << "Info:" << std::endl;
    std::cout << sizeof(Info) << std::endl;   // 6  2 + 2 + 2
    std::cout << sizeof(info.a) << std::endl; // 1
    std::cout << sizeof(info.b) << std::endl; // 2
    std::cout << sizeof(info.c) << std::endl; // 1
    std::cout << alignof(Info) << std::endl;  // 2
    std::cout << "Info2:" << std::endl;
    Info2 info2;
    std::cout << sizeof(Info2) << std::endl;   // 8  2 + 2 + 2 + 2
    std::cout << sizeof(info2.a) << std::endl; // 1
    std::cout << sizeof(info2.b) << std::endl; // 2
    std::cout << sizeof(info2.c) << std::endl; // 1
    std::cout << alignof(Info2) << std::endl;  // 4
    return 0;
}