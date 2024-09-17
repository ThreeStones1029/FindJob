/*
 * @Description:
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-09-17 22:27:59
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-09-17 22:33:54
 */
#include <iostream>

int main() {
    struct T {};
    std::cout <<sizeof(struct T) << std::endl;

    char str[] = "glad to test something";
    char *p = str;
    p++;
    int *p1 = reinterpret_cast<int*>(p);
    p1++;
    p = reinterpret_cast<char*>(p1);
    std::cout << p << std::endl;
}