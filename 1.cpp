#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 反转两个连续数字
void reverseTwo(vector<int>& arr, int i) {
    swap(arr[i], arr[i + 1]);
}

// 反转三个连续数字
void reverseThree(vector<int>& arr, int i) {
    reverse(arr.begin() + i, arr.begin() + i + 3);
}

// 使用贪心策略排序并尽量减少反转两个元素的操作
vector<pair<string, int>> sortWithMinTwoOperations(vector<int>& arr) {
    int n = arr.size();
    vector<pair<string, int>> operations;
    
    // 建立目标位置的索引映射
    vector<int> indexMap(n);
    for (int i = 0; i < n; ++i) {
        indexMap[arr[i] - 1] = i;
    }

    // 贪心策略：优先使用三元素反转
    for (int i = 0; i < n - 2; ++i) {
        while (arr[i] != i + 1) {
            int targetIndex = indexMap[i]; // 获取目标位置的索引
            if (targetIndex >= i + 2) { // 确保可以使用三元素反转
                reverseThree(arr, i);
                operations.push_back({"reverse_three", i});
                
                // 更新目标位置的索引映射
                indexMap[arr[i] - 1] = i;
                indexMap[arr[i + 1] - 1] = i + 1;
                indexMap[arr[i + 2] - 1] = i + 2;
            } else {
                reverseTwo(arr, i);
                operations.push_back({"reverse_two", i});
                
                // 更新目标位置的索引映射
                indexMap[arr[i] - 1] = i;
                indexMap[arr[i + 1] - 1] = i + 1;
            }
        }
    }

    // 最后的调整（确保排序完全）
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            reverseTwo(arr, i);
            operations.push_back({"reverse_two", i});
        }
    }

    return operations;
}

int main() {
    vector<int> arr = {1, 2, 5, 4, 3}; // 示例输入
    vector<pair<string, int>> operations = sortWithMinTwoOperations(arr);

    cout << "排序后的数组: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "操作序列:" << endl;
    for (const auto& op : operations) {
        cout << op.first << " at index " << op.second << endl;
    }

    return 0;
}
