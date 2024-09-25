/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-09-25 15:27:26
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-09-25 15:41:54
 */
#include <iostream>
#include <string>
#include <sstream>

// 数字字符串如何转为数字
int str_to_number(std::string str) {
    int number = std::stoi(str);
    return number;
}


// 获取一行字符串，其中单个字符串以","隔开
void get_single_str_from_string(std::string operator_and_operand) {
    std::istringstream str(operator_and_operand);
    std::string single_str;
    while (std::getline(str, single_str, ',')) {
        std::cout << single_str << std::endl;
    }
}


int main() {
    int number = str_to_number("102");
    std::cout << number << std::endl;
    get_single_str_from_string("1,2,/,3,4,*,-,+");
    return 0;
}
