#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream input("matrix.txt");		// Mở file input để đọc ma trận.
    ofstream output("matrix.out");		// Mở file output để ghi kết quả.

    int m, n;
    input >> m >> n; // Đọc số hàng và số cột của ma trận.

    int a[100][100];
    int sum[100][100] = {0}; // Khởi tạo ma trận tổng tiền tố.

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            input >> a[i][j]; // Đọc các phần tử của ma trận.

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]; // Tính tổng tiền tố.
        }
    }

    int maxSum = a[1][1]; // Khởi tạo tổng lớn nhất.
    int r1 = 1, c1 = 1, r2 = 1, c2 = 1;

    for (int i1 = 1; i1 <= m; ++i1) {
        for (int j1 = 1; j1 <= n; ++j1) {
            for (int i2 = i1; i2 <= m; ++i2) {
                for (int j2 = j1; j2 <= n; ++j2) {
                    int s = sum[i2][j2] - sum[i1 - 1][j2] - sum[i2][j1 - 1] + sum[i1 - 1][j1 - 1]; // Tính tổng submatrix.
                    if (s > maxSum) { // So sánh với tổng lớn nhất hiện tại.
                        maxSum = s;   // Cập nhật tổng lớn nhất.
                        r1 = i1; c1 = j1; r2 = i2; c2 = j2; // Lưu tọa độ submatrix lớn nhất.
                    }
                }
            }
        }
    }

    cout << r1 << " " << c1 << " " << r2 << " " << c2 << " " << maxSum << endl; // In kết quả.
    output << r1 << " " << c1 << " " << r2 << " " << c2 << " " << maxSum << endl; // Ghi kết quả vào file.

    input.close();
    output.close();

    return 0;
}