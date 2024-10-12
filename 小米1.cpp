/*
 * @Description: 给定数列，需要操作数字，每次操作连续的两个数字取反，可以操作任意次，同一个数字也可以操作多次，求操作后最大的数组和
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-10-12 17:31:55
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-10-12 17:32:59
 */
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int N;
    std::cin >> N;
    int a;
    std::vector<int> array;
    for (int i = 0; i < N; i++) {
        std::cin >> a;
        array.push_back(a);
    }
    
    // 先判断负数个数，负数为偶数，则全部转为正数即可
    // 为奇数，则将绝对值最小的变为负数即可，其余均变为正数
    int num = 0;
    for (int i = 0; i < N; i++) {
        if (array[i] < 0) {
            num++;
        }
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (array[i] < 0) {
            sum += -1 * array[i];
        } else {
            sum += array[i];
        }
    }
    int min = array[0] > 0 ? array[0] : array[0] * -1;
    if (num % 2 == 0) {
        std::cout << sum << std::endl;
    }
    if (num % 2 == 1) {
        for (int i = 0; i < N; i++) {
            if (array[i] < 0) {
                if (array[i] * -1 < min) {
                    min = array[i] * -1;
                } 
            } else {
                if (array[i] < min) {
                    min = array[i];
                } 
            }
        }

        sum = sum - 2 * min;
        std::cout << sum << std::endl;
    }
}