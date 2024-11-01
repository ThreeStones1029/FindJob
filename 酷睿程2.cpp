// 找到最少的传递次数从第一个路由器传递到最后一个路由器

#include <iostream>
#include <vector>
#include <climits> // 用于INT_MAX

int minRelay(std::vector<int>& distances) {
    int n = distances.size();
    std::vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (distances[j] >= i - j) {
                dp[i] = std::min(dp[i], dp[j] + 1);
            }
        }
    }

    return dp[n-1] == INT_MAX ? -1 : dp[n-1];
}

int main() {
    std::vector<int> distances1 = {2, 3, 1, 2, 1};
    std::cout << "Output for example 1: " << minRelay(distances1) << std::endl;

    std::vector<int> distances2 = {1, 1, 2, 1, 1};
    std::cout << "Output for example 2: " << minRelay(distances2) << std::endl;

    return 0;
}