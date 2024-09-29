#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int minMixingOperations(vector<int>& feature_value) {
    unordered_set<int> used;  // 记录已使用的特征值
    vector<int> duplicates;    // 存储重复的特征值
    int mix_count = 0;         // 混合次数计数

    for (int value : feature_value) {
        if (used.find(value) != used.end()) {
            duplicates.push_back(value);  // 如果特征值重复，加入重复列表
        } else {
            used.insert(value);            // 如果特征值未使用，加入集合
        }
    }

    // 处理重复特征值
    for (int value : duplicates) {
        // 从当前值开始寻找未被使用的特征值
        while (used.find(value) != used.end()) {
            ++value;   // 递增值以找到未使用的特征值
            ++mix_count;  // 每次递增视为一次混合操作
        }
        used.insert(value);  // 使用找到的未使用特征值
    }

    return mix_count;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> feature_value(n);
    for (int i = 0; i < n; ++i) {
        cin >> feature_value[i];  // 输入特征值
    }

    int result = minMixingOperations(feature_value);
    cout << result << endl;  // 输出最小混合次数

    return 0;
}
