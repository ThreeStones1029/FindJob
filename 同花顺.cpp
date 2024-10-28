/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-10-23 20:03:51
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-10-23 20:06:04
 */
#include <iostream>
#include <vector>

int maxProfit(const std::vector<int>& prices) {
    int max_profit = 0;
    for (size_t i = 1; i < prices.size(); ++i) {
        if (prices[i] > prices[i - 1]) {
            max_profit += prices[i] - prices[i - 1];
        }
    }
    return max_profit;
}

int main() {
    std::vector<int> prices = {4, 4, 8, 6, 8};
    int result = maxProfit(prices);
    std::cout << "最大利润: " << result << std::endl; // 输出: 4
    return 0;
}
