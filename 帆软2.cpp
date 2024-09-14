/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-09-11 21:36:40
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-09-11 22:43:22
 */
/*
给定一个正整数N，求一个数组，使得数组的元素三次方之和等于N,返回最短的数组，例如：给定42,返回[2,2,2,2,2,1,1]
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

// 使用动态规划找出最短的立方和数组
std::vector<int> findMinCubicSum(int N) {
    // dp[i] 表示和为 i 时最短数组的元素数量
    std::vector<int> dp(N + 1, std::numeric_limits<int>::max());
    std::vector<int> previous(N + 1, -1); // 记录用于生成 dp[i] 的立方数
    
    dp[0] = 0; // 和为 0 的时候，元素个数为 0
    
    // 遍历所有可能的和
    for (int i = 1; i <= N; ++i) {
        // 尝试每个立方数
        for (int k = 1; k * k * k <= i; ++k) {
            int cube = k * k * k;
            if (dp[i - cube] + 1 < dp[i]) {
                dp[i] = dp[i - cube] + 1;
                previous[i] = k; // 记录选择的立方数 k
            }
        }
    }
    
    // 还原结果数组
    std::vector<int> result;
    int current = N;
    while (current > 0) {
        int k = previous[current]; // 找到选择的立方数
        result.push_back(k);
        current -= k * k * k;
    }
    
    return result;
}

int main() {
    int N = 43114564;  // 你可以将 N 改为任意你想要的数字
    std::vector<int> result = findMinCubicSum(N);
    std::reverse(result.begin(), result.end());
    std::cout << "最短结果数组: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
