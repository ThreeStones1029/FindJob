/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-10-17 11:51:35
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-10-17 11:52:55
 */

// 这道题目是关于将一个仅由数字 0 到 9 组成的字符串进行划分的问题。具体来说，给定一个长度为 n 的字符串 S ，要求将这个字符串划分为 k 个（ k > 0 ）较小的字符串 p_1, p_2, ..., p_k ，同时满足以下两个条件：
// 1. 这些较小的字符串连接起来应该能够还原成原始字符串 S ，即 S = p_1 + p_2 + ... + p_k 。
// 2. 对于任意的 i （ 2 ≤ i ≤ k ），在 p_{i-1} 和 p_i 之间，至少存在一个数字，它在这两个字符串中出现的次数都是大于0且相等的。
// 例如：
//  010 和 3200 是合法的划分，因为数字 0 在两个字符串中都出现了两次。
//  12345666 和 6668 是合法的划分，因为数字 6 在两个字符串中都至少出现了三次。
//  456 和 6660 是不合法的划分，因为没有任何数字在两个字符串中出现的次数是相等的。
// 目标是找出最多的划分数 k 。
// 这个问题可以通过动态规划或者贪心算法来解决，关键在于如何高效地检查两个字符串之间是否存在至少一个数字出现次数相等，并且如何利用这一条件来划分字符串。
// 对于输入输出的描述：
// 输入：一个长度为 n 的字符串 S ，由数字 0 到 9 组成。
// 输出：最多可以将字符串 S 划分为几个字符串，输出这个最大划分数 k 。
// 这个问题的难点在于如何高效地检查和利用两个字符串之间的公共数字，以及如何设计算法来找到最多的划分数。这可能涉及到字符串处理和搜索算法的结合使用。

#include <iostream>
#include <vector>
#include <string>
#include <array>
using namespace std;

// 判断两个子字符串之间是否可以形成合法的划分
bool canPartition(const array<int, 10>& left_count, const array<int, 10>& right_count) {
    for (int i = 0; i < 10; ++i) {
        if (left_count[i] == right_count[i] && left_count[i] > 0) {
            return true;
        }
    }
    return false;
}

// 获取最大划分数
int maxPartitions(const string& s) {
    int n = s.size();
    
    // 前缀计数数组
    vector<array<int, 10>> prefix_count(n + 1);
    for (int i = 0; i <= n; ++i) {
        prefix_count[i].fill(0);
    }

    // 填充前缀计数数组
    for (int i = 1; i <= n; ++i) {
        int digit = s[i - 1] - '0';
        prefix_count[i] = prefix_count[i - 1];
        prefix_count[i][digit]++;
    }

    int start = 0;
    int partition_count = 0;

    // 尝试划分字符串
    for (int end = 1; end <= n; ++end) {
        // 比较从 start 到 mid 和 mid+1 到 end 是否满足条件
        if (start < end - 1 && canPartition(prefix_count[start], prefix_count[end])) {
            partition_count++;
            start = end;
        }
    }

    // 计入最后一段
    return partition_count + 1;
}

int main() {
    string s;
    cout << "请输入数字字符串: ";
    cin >> s;

    int max_partitions = maxPartitions(s);
    cout << "最大划分数: " << max_partitions << endl;

    return 0;
}
