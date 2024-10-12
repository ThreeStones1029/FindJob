/*
 * @Description: 
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-10-11 21:35:23
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-10-11 21:37:11
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// 结构体表示货物任务
struct Cargo {
    int start, end, extra;
};

// 比较函数用于按结束位置排序货物任务
bool compare(Cargo& a, Cargo& b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;

    vector<Cargo> cargos;
    int start, end, extra;
    
    // 读取输入数据
    while (cin >> start >> end >> extra) {
        cargos.push_back({start, end, extra});
    }

    // 按照结束时间排序
    sort(cargos.begin(), cargos.end(), compare);

    // 使用map记录最大元宝数
    map<int, long long> dp;
    dp[0] = 0; // 基础情况，无任务时元宝数为0

    long long maxGold = 0;
    
    for (auto &cargo : cargos) {
        // 寻找不与当前任务冲突的最近的任务
        auto it = dp.lower_bound(cargo.start);
        if (it != dp.begin()) {
            --it;
        }
        
        // 计算当前任务的元宝数
        long long currentReward = (cargo.end - cargo.start) + cargo.extra + it->second;
        
        // 更新最大元宝数
        if (currentReward > dp[cargo.end]) {
            dp[cargo.end] = currentReward;
            maxGold = max(maxGold, currentReward);
        }
    }

    // 输出最大元宝数
    cout << maxGold << endl;

    return 0;
}