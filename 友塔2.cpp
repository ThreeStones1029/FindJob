#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 深度优先搜索，标记所有被污染的区域
void dfs(int x, int y, int n, vector<vector<bool>>& visited, vector<vector<set<pair<int, int>>>>& adj) {
    visited[x][y] = true;
    for (auto& neighbor : adj[x][y]) {
        int nx = neighbor.first;
        int ny = neighbor.second;
        if (!visited[nx][ny]) {
            dfs(nx, ny, n, visited, adj);
        }
    }
}

int main() {
    int n, a;
    cin >> n >> a;

    // 地图表示，使用邻接表
    vector<vector<set<pair<int, int>>>> adj(n + 1, vector<set<pair<int, int>>>(n + 1));

    // 读取门的信息，并建立区域的连接关系
    for (int i = 0; i < a; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        adj[x1][y1].insert({x2, y2});
        adj[x2][y2].insert({x1, y1});
    }

    // 标记被污染的区域
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));

    // 从所有 y = 1 的区域出发，使用 DFS 进行污染扩散
    for (int i = 1; i <= n; i++) {
        if (!visited[i][1]) {
            dfs(i, 1, n, visited, adj);
        }
    }

    // 统计安全区域
    int safeCount = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!visited[i][j]) {
                safeCount++;
            }
        }
    }

    // 输出安全区域的个数
    cout << safeCount << endl;

    return 0;
}