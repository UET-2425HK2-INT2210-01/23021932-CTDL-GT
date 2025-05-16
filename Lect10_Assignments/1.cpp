#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10000; // Số lượng đỉnh tối đa

vector<int> adj[MAXN]; // Danh sách kề để biểu diễn đồ thị
bool visited[MAXN];    // Mảng đánh dấu các đỉnh đã được thăm

// Hàm DFS để duyệt đồ thị từ đỉnh u
void dfs(int u) {
    visited[u] = true; // Đánh dấu đỉnh u đã được thăm

    // Duyệt tất cả các đỉnh kề với u
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v); // Gọi đệ quy với đỉnh chưa được thăm
        }
    }
}

int main() {
    int n, m; // n: số đỉnh, m: số cạnh
    cin >> n >> m;

    // Đọc m cạnh và xây dựng danh sách kề
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // Thêm cạnh từ x đến y
        adj[y].push_back(x); // Thêm cạnh từ y đến x (vì đồ thị vô hướng)
    }

    int connectedComponents = 0; // Đếm số thành phần liên thông

    // Duyệt qua tất cả các đỉnh
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) { // Nếu đỉnh i chưa được thăm
            ++connectedComponents; // Tìm thấy một thành phần liên thông mới
            dfs(i); // Gọi DFS để đánh dấu tất cả các đỉnh trong thành phần đó
        }
    }

    cout << connectedComponents << endl;

    return 0;
}
