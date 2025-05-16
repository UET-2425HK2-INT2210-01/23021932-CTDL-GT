#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Hàm BFS để tính khoảng cách từ đỉnh start đến các đỉnh còn lại
void bfs(int n, vector<vector<int>>& adj, int start, vector<int>& dist) {
    // Khởi tạo khoảng cách ban đầu của tất cả các đỉnh là -1 (chưa thăm)
    for (int i = 1; i <= n; ++i) {
        dist[i] = -1;
    }

    dist[start] = 0; // Khoảng cách từ start đến chính nó là 0

    queue<int> q;
    q.push(start); // Đưa đỉnh bắt đầu vào hàng đợi

    // Vòng lặp BFS
    while (!q.empty()) {
        int u = q.front(); // Lấy đỉnh đầu hàng đợi
        q.pop();

        // Duyệt các đỉnh kề với u
        for (int v : adj[u]) {
            if (dist[v] == -1) { // Nếu đỉnh v chưa được thăm
                dist[v] = dist[u] + 1; // Cập nhật khoảng cách
                q.push(v); // Đưa v vào hàng đợi để tiếp tục duyệt
            }
        }
    }
}

// Hàm tính đường đi ngắn nhất từ đỉnh start đến đỉnh end bằng BFS
int shortestPath(int n, vector<vector<int>>& adj, int start, int end) {
    vector<int> dist(n + 1); // Mảng lưu khoảng cách từ start đến các đỉnh
    bfs(n, adj, start, dist); // Gọi BFS để tính khoảng cách
    return dist[end]; // Trả về khoảng cách từ start đến end (nếu không reachable thì là -1)
}

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y; // Nhập số đỉnh, số cạnh, đỉnh bắt đầu và đỉnh kết thúc

    vector<vector<int>> adj(n + 1); // Khởi tạo danh sách kề (đánh số đỉnh từ 1 đến n)

    // Nhập các cạnh của đồ thị có hướng
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Thêm cạnh từ u đến v (đồ thị có hướng)
    }

    // In ra độ dài đường đi ngắn nhất từ x đến y
    cout << shortestPath(n, adj, x, y) << endl;

    return 0;
}
