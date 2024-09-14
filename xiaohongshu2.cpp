/*
 * @Description: 
 * @version: 
 * @Author: 帅磊240108 2158097607@xiaomi.com
 * @Date: 2024-09-01 16:01:53
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-09-12 22:51:20
 */
#include <iostream>
#include <vector>
#include <algorithm>


int minimizeUnpleasantness(std::vector<int>& categories, std::vector<int>& movable) {
    int n = categories.size();
    
    // 保存结果数组
    std::vector<int> result(n, 0);
    
    // 统计类别1和类别2的物品数量
    std::vector<int> category1, category2;
    for (int i = 0; i < n; ++i) {
        if (movable[i] == 1) {
            if (categories[i] == 1) category1.push_back(i);
            else category2.push_back(i);
        } else {
            result[i] = categories[i];  // 将不可移动的物品直接放入结果中
        }
    }

    // 尝试通过贪心策略最小化不美观
    int unpleasantness = 0;
    for (int i = 1; i < n; ++i) {
        if (result[i-1] != 0) {  // 检查不可移动的物品后面的位置
            if (result[i] == 0) { // 可移动位置
                if (!category1.empty() && result[i-1] == 2) {
                    result[i] = 1;
                    category1.pop_back();
                } else if (!category2.empty() && result[i-1] == 1) {
                    result[i] = 2;
                    category2.pop_back();
                }
            }
        }
    }

    // 如果还有剩余的可移动物品，则按顺序填充
    for (int i = 0; i < n; ++i) {
        if (result[i] == 0) {
            if (!category1.empty()) {
                result[i] = 1;
                category1.pop_back();
            } else if (!category2.empty()) {
                result[i] = 2;
                category2.pop_back();
            }
        }
    }

    // 计算不美观
    for (int i = 1; i < n; ++i) {
        if (result[i] != result[i-1]) {
            unpleasantness++;
        }
    }

    return unpleasantness;
}

int main() {
    std::vector<int> categories = {1, 2, 1, 2, 1};
    std::vector<int> movable = {1, 1, 0, 1, 1};

    int result = minimizeUnpleasantness(categories, movable);
    std::cout << "The minimum unpleasantness is: " << result << std::endl;

    return 0;
}
