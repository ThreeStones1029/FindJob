/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-09-11 21:36:28
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-09-11 22:37:23
 */
// 题目：
/*
给定字符串，对于子字符串，可以选择删除字符，求最长的回文子字符串长度。例如：bbabc 返回3
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


int longestPalindromeSubsequence(const std::string& s) {
    int n = s.size();
    // dp[i][j]表示子串s[i..j]的最长回文子串长度
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    // 所有长度为1的子串的回文长度是1
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    // 从长度为2开始计算到n
    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    // 返回整个字符串的最长回文子串长度
    return dp[0][n - 1];
}

int main() {
    std::string s = "bbbabggbaffffsddsffffcccccddeebbsssvvv";
    std::cout << "最长回文子字符串长度: " << longestPalindromeSubsequence(s) << std::endl;

    return 0;
}
