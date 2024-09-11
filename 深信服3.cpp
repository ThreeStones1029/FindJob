/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-09-11 15:40:20
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-09-11 15:40:25
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// 计算将字符串 str1 转换为 str2 所需的最少操作次数
int minEditDistance(const std::string& str1, const std::string& str2) {
    int len1 = str1.length();
    int len2 = str2.length();
    
    // 创建 dp 数组，大小为 (len1 + 1) x (len2 + 1)
    std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1, 0));

    // 初始化边界条件
    for (int i = 0; i <= len1; ++i) {
        dp[i][0] = i;  // str1 的前 i 个字符删除以变为空字符串
    }
    for (int j = 0; j <= len2; ++j) {
        dp[0][j] = j;  // 空字符串插入 j 个字符变为 str2 的前 j 个字符
    }

    // 填充 dp 数组
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // 字符相同，不需要操作
            } else {
                dp[i][j] = std::min({ dp[i - 1][j] + 1,    // 删除
                                      dp[i][j - 1] + 1,    // 插入
                                      dp[i - 1][j - 1] + 1 // 替换
                                    });
            }
        }
    }

    // 返回最终结果：将 str1 转换为 str2 所需的最少操作次数
    return dp[len1][len2];
}

int main() {
    std::string str1 = "AGCT";
    std::string str2 = "GCTA";
    
    int result = minEditDistance(str1, str2);
    std::cout << "将字符串1变为字符串2的最少操作次数: " << result << std::endl;

    return 0;
}
