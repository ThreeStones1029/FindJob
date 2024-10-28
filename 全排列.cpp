#include <iostream>
#include <vector>

// 不重复， 全排列遍历
void backtracing(std::vector<std::vector<int>>& results, std::vector<int>& path, std::vector<bool>& used, std::vector<int>& array, int n) {
    if (path.size() == n) {
        results.push_back(path);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (used[i] == true) continue;
        path.push_back(array[i]);
        used[i] = true;
        backtracing(results, path, used, array, n);
        path.pop_back();
        used[i] = false;
    }
}


int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> results;
    std::vector<int> path;
    std::vector<int> array;
    std::vector<bool> used(n, false);
    for (int i = 0; i < n; i++) {
        array.push_back(i + 1);
    }
    backtracing(results, path, used, array, n);
    for (int i = 0; i < results.size(); i++) {
        for (int j = 0; j < n; j++) {
            std::cout << results[i][j] << " ";
        }
        std::cout << std::endl;
    }
}