/*
 * @Description: 给定三个参数，我需要对一个数列重新调整顺序，数列有n个数，分别从1到n。我输入的参数有a,b,op，其中a,b为数字，表示需要操作的数字，op为0的时候将a放在b前面，当为1时放在b后面。cpp代码怎么实现
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2024-10-12 17:27:58
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2024-10-12 17:29:02
 */
#include <iostream>
#include <vector>
#include <algorithm>


// 调整数列中 a 和 b 的位置，根据 op 确定 a 是在 b 前还是在 b 后
void reorder(std::vector<int>& sequence, int a, int b, int op) {
    // 找到 a 和 b 在序列中的位置
    auto it_a = std::find(sequence.begin(), sequence.end(), a);
    auto it_b = std::find(sequence.begin(), sequence.end(), b);

    if (it_a == sequence.end() || it_b == sequence.end()) {
        std::cerr << "a 或 b 不在序列中，操作无效。" << std::endl;
        return;
    }

    // 删除 a 以便稍后插入
    int value_a = *it_a;
    sequence.erase(it_a);

    // 决定插入 a 的位置
    if (op == 0) {
        // 插入到 b 的前面
        it_b = std::find(sequence.begin(), sequence.end(), b);
        sequence.insert(it_b, value_a);
    } else if (op == 1) {
        // 插入到 b 的后面
        it_b = std::find(sequence.begin(), sequence.end(), b);
        sequence.insert(it_b + 1, value_a);
    }
}

int main() {
    int n, q, a, b, op;
    std::cin >> n >> q;

    // 初始化数列为 1 到 n
    std::vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        sequence[i] = i + 1;
    }
    while (q--) {
        std::cin >> a >> b >> op;
        // 调整数列顺序
        reorder(sequence, a, b, op);
    }
    // 输出调整后的数列
    for (int num : sequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
