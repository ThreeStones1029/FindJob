/*
 * @Description: 有一本书n页，这本书的知识量为a1，到an，有m分钟阅读这本书，1）每一分钟只能读一页，获取知识量a，
 2）一分钟读连续的两页，则可以获取知识量为这两页之和的一半，如何才能获取最大的知识量？cpp代码实现
 * @version: 
 * @Author: ThreeStones1029 2320218115@qq.com
 * @Date: 2025-03-09 15:11:08
 * @LastEditors: ShuaiLei
 * @LastEditTime: 2025-03-09 15:11:12
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double maxKnowledge(int n, int m, vector<double>& a) {
    // 使用一维数组优化空间复杂度
    vector<double> dp(n + 1, 0.0);
    vector<double> prev(n + 1, 0.0);

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // 选择1：只读第 j 页
            dp[j] = prev[j-1] + a[j-1];

            // 选择2：读第 j-1 页和第 j 页
            if (j >= 2) {
                dp[j] = max(dp[j], prev[j-2] + (a[j-2] + a[j-1]) / 2.0);
            }
        }
        prev = dp;
    }

    return dp[n];
}

int main() {
    int n, m;
    cout << "请输入书的页数 n 和阅读时间 m: ";
    cin >> n >> m;

    vector<double> a(n);
    cout << "请输入每页的知识量: ";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    double result = maxKnowledge(n, m, a);
    cout << "最大知识量为: " << result << endl;

    return 0;
}