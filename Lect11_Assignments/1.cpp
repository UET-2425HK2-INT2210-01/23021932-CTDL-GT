#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const long long INF = 1000000000000000LL;

// Cấu trúc biểu diễn cạnh trong đồ thị
struct Edge {
    int from;
    int to;
    long long weight;
};

int main() {
    int totalCities, totalRoads, sourceCity, targetCity;
    cin >> totalCities >> totalRoads >> sourceCity >> targetCity;

    vector<Edge> roadList;
    roadList.reserve(totalRoads); // Tối ưu hóa cấp phát bộ nhớ

    // Nhập các cạnh của đồ thị
    for (int i = 0; i < totalRoads; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        roadList.push_back({u, v, w});
    }

    // Mảng lưu khoảng cách ngắn nhất từ sourceCity đến các đỉnh
    vector<long long> minDistance(totalCities + 1, INF);
    // Mảng lưu đỉnh trước đó để truy vết đường đi
    vector<int> predecessor(totalCities + 1, -1);

    minDistance[sourceCity] = 0; // Khoảng cách từ đỉnh xuất phát đến chính nó là 0

    // Bellman-Ford: Lặp tối đa (n - 1) lần
    for (int iteration = 1; iteration < totalCities; iteration++) {
        bool updated = false;
        for (const Edge& edge : roadList) {
            int u = edge.from;
            int v = edge.to;
            long long w = edge.weight;
            // Nếu có thể cập nhật khoảng cách ngắn hơn
            if (minDistance[u] < INF && minDistance[u] + w < minDistance[v]) {
                minDistance[v] = minDistance[u] + w;
                predecessor[v] = u;
                updated = true;
            }
        }
        if (!updated) break; // Nếu không có cập nhật nào thì dừng sớm
    }

    // Nếu không thể đến được targetCity
    if (minDistance[targetCity] >= INF / 2) {
        cout << "INF\n\n";
    } else {
        // In ra khoảng cách ngắn nhất từ sourceCity đến targetCity
        cout << minDistance[targetCity] << "\n";

        // Truy vết và in đường đi
        vector<int> path;
        int current = targetCity;
        while (current != -1) {
            path.push_back(current);
            current = predecessor[current];
        }
        reverse(path.begin(), path.end()); // Đảo ngược đường đi để đi từ source -> target

        for (int i = 0; i < (int)path.size(); i++) {
            if (i) cout << ' ';
            cout << path[i];
        }
        cout << "\n";
    }

    // Chuẩn bị cho thuật toán Floyd-Warshall
    vector<vector<long long>> allPairsDist(totalCities + 1,
                                            vector<long long>(totalCities + 1, INF));

    // Khoảng cách từ một đỉnh đến chính nó là 0
    for (int i = 1; i <= totalCities; i++) {
        allPairsDist[i][i] = 0;
    }

    // Cập nhật khoảng cách ban đầu từ các cạnh đã nhập
    for (const Edge& edge : roadList) {
        int u = edge.from;
        int v = edge.to;
        long long w = edge.weight;
        // Lưu trọng số nhỏ nhất nếu có nhiều cạnh giữa u và v
        if (w < allPairsDist[u][v]) {
            allPairsDist[u][v] = w;
        }
    }

    // Floyd-Warshall: Tính khoảng cách ngắn nhất giữa mọi cặp đỉnh
    for (int k = 1; k <= totalCities; k++) { // Đỉnh trung gian
        for (int i = 1; i <= totalCities; i++) { // Đỉnh xuất phát
            if (allPairsDist[i][k] >= INF) continue; // Không đi qua k được thì bỏ qua
            for (int j = 1; j <= totalCities; j++) { // Đỉnh đích
                if (allPairsDist[k][j] < INF &&
                    allPairsDist[i][k] + allPairsDist[k][j] < allPairsDist[i][j]) {
                    allPairsDist[i][j] = allPairsDist[i][k] + allPairsDist[k][j];
                }
            }
        }
    }

    // In ra ma trận khoảng cách giữa mọi cặp đỉnh
    for (int i = 1; i <= totalCities; i++) {
        for (int j = 1; j <= totalCities; j++) {
            if (allPairsDist[i][j] >= INF / 2) {
                cout << "INF";
            } else {
                cout << allPairsDist[i][j];
            }
            if (j < totalCities) cout << ' ';
        }
        cout << "\n";
    }

    return 0;
}
