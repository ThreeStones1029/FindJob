#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>

// 找到所有符合 a*b*c = k 的组合，利用对称性
std::vector<std::tuple<int, int, int>> findABC(int k) {
    std::vector<std::tuple<int, int, int>> results;

    // 遍历 a，从 1 到 k 的三次方根
    for (int a = 1; a <= std::cbrt(k); ++a) {
        if (k % a == 0) {
            // 遍历 b，从 a 开始，避免重复
            for (int b = a; b <= std::sqrt(k / a); ++b) {
                if ((k / a) % b == 0) {
                    int c = k / (a * b);
                    if (a * b * c == k && b <= c) { // 确保 b <= c，避免重复
                        results.emplace_back(a, b, c);
                    }
                }
            }
        }
    }

    return results;
}

int main() {
    int k = 37; // 示例整数

    std::vector<std::tuple<int, int, int>> results = findABC(k);

    std::cout << "k = " << k << " 的分解结果为:\n";
    for (const auto& result : results) {
        int a, b, c;
        std::tie(a, b, c) = result;  // C++11 使用 std::tie 解构 tuple
        std::cout << a << " * " << b << " * " << c << " = " << k << std::endl;
    }

    return 0;
}
