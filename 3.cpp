#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

// 将宝石列表转换为字符串，用于备忘录的键
string gemsToString(const vector<int>& gems) {
    string s;
    for(auto num : gems){
        s += to_string(num) + ",";
    }
    return s;
}

// 备忘录，用于存储已经计算过的宝石排列的最大幸运值
unordered_map<string, long long> memo;

// 递归函数，返回合并当前宝石列表后能获得的最大幸运值
long long dfs(vector<int>& gems, int K) {
    // 如果只剩下一个宝石，不需要合并，幸运值为0
    if(gems.size() == 1){
        return 0;
    }
    
    // 检查是否已经计算过当前宝石排列
    string key = gemsToString(gems);
    if(memo.find(key) != memo.end()){
        return memo[key];
    }
    
    long long maxLucky = -1; // 初始化为-1，表示如果无法合并则返回-1
    
    // 尝试所有可能的连续K个宝石进行合并
    for(int i=0; i + K <= gems.size(); ++i){
        // 计算当前K个宝石的能量和
        long long currentSum = 0;
        for(int j=i; j<i+K; ++j){
            currentSum += gems[j];
        }
        
        // 构造新的宝石列表
        vector<int> newGems;
        // 添加合并前的宝石
        for(int j=0; j<i; ++j){
            newGems.push_back(gems[j]);
        }
        // 添加合并后的新宝石
        newGems.push_back(currentSum);
        // 添加合并后的剩余宝石
        for(int j=i+K; j<gems.size(); ++j){
            newGems.push_back(gems[j]);
        }
        
        // 递归计算剩余宝石的最大幸运值
        long long subLucky = dfs(newGems, K);
        
        if(subLucky != -1){
            // 当前合并的幸运值 + 递归得到的子问题幸运值
            maxLucky = max(maxLucky, currentSum + subLucky);
        }
    }
    
    // 备忘录存储
    memo[key] = maxLucky;
    return maxLucky;
}

long long maxLuckyValue(int K, vector<int>& energy) {
    int M = energy.size();
    
    // 检查是否可以最终合并成一个宝石
    if((M-1) % (K-1) !=0){
        return -1;
    }
    
    // 清空备忘录
    memo.clear();
    
    // 调用递归函数
    return dfs(energy, K);
}

int main() {
    // 示例一
    vector<int> energy1 = {10, 7, 2, 6, 5, 11, 8};
    int K1 = 4;
    long long result1 = maxLuckyValue(K1, energy1);
    cout << "示例一 - 最大幸运值: " << result1 << endl;  // 输出79
    
    // 示例二
    vector<int> energy2 = {10, 7, 2, 6, 5, 11};
    int K2 = 3;
    long long result2 = maxLuckyValue(K2, energy2);
    cout << "示例二 - 最大幸运值: " << result2 << endl;  // 输出-1
    
    return 0;
}
