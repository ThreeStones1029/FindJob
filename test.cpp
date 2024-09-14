#include <iostream>
#include <iomanip>  // 包含控制输出格式的头文件
#include <cmath>    // 包含 sqrt 函数

int main() {
    double num = 16.5;
    
    // sqrt 默认返回 double
    double result = sqrt(num);

    // 强制显示小数点后的一位
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "The square root of " << num << " is " << result << std::endl;
    return 0;
}
