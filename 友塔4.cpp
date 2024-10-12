/*
 * @Description: ubn
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-10-11 21:50:42
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-10-11 21:52:33
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> rearrangeBoxes(vector<int>& boxes) {
    // 统计每个编号的出现次数
    unordered_map<int, int> counts;
    for (int box : boxes) {
        counts[box]++;
    }

    // 使用最大堆来存储编号及其出现次数，优先处理出现次数多的编号
    priority_queue<pair<int, int>> maxHeap;
    for (auto& entry : counts) {
        maxHeap.push({entry.second, entry.first});
    }

    // 用于保存重排后的结果
    vector<int> result;
    pair<int, int> prev = {-1, 0}; // 存储上一个被安排的编号及其剩余次数

    // 重排盒子
    while (!maxHeap.empty()) {
        auto current = maxHeap.top();
        maxHeap.pop();
        result.push_back(current.second);

        // 如果上一个编号还有剩余次数，重新放回堆中
        if (prev.first > 0) {
            maxHeap.push(prev);
        }

        // 更新当前编号的次数，成为新的prev
        current.first--;
        prev = current;
    }

    // 如果没有成功地排满所有盒子，则返回空数组
    if (result.size() != boxes.size()) {
        return {};
    }

    return result;
}

int main() {
    vector<int> boxes = {1, 1, 1, 2, 2, 2};
    
    vector<int> result = rearrangeBoxes(boxes);

    if (result.empty()) {
        cout << "[]" << endl;
    } else {
        for (int box : result) {
            cout << box << " ";
        }
        cout << endl;
    }

    return 0;
}