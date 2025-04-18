#include <iostream>
using namespace std;

// Hàm đệ quy sinh tất cả các hoán vị của các số từ 1 đến n
void generatePermutations(int arr[], bool used[], int n, int index) {
    // Điều kiện dừng: khi đã điền đủ n phần tử vào mảng hoán vị
    if (index == n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i];
        }
        cout << endl;
        return;
    }

    // Thử từng số từ 1 đến n cho vị trí hiện tại (index)
    for (int i = 1; i <= n; ++i) {
        // Kiểm tra xem số 'i' đã được sử dụng trong hoán vị hiện tại chưa
        if (!used[i]) {
            // Đánh dấu số 'i' là đã được sử dụng
            used[i] = true;
            // Gán số 'i' vào vị trí 'index' của mảng hoán vị
            arr[index] = i;

            // Gọi đệ quy để tạo hoán vị cho vị trí tiếp theo
            generatePermutations(arr, used, n, index + 1);

            // Bước backtracking: đánh dấu số 'i' là chưa được sử dụng để thử các hoán vị khác
            used[i] = false;
        }
    }
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n; // Nhập số n, xác định các số từ 1 đến n sẽ được hoán vị

    // Mảng để lưu trữ một hoán vị đang được xây dựng
    int arr[n];

    // Mảng boolean để theo dõi số nào đã được sử dụng trong hoán vị hiện tại
    bool used[n + 1]; // Sử dụng n+1 để index tương ứng với các số từ 1 đến n
    for (int i = 0; i <= n; ++i) {
        used[i] = false; // Khởi tạo tất cả các số là chưa được sử dụng
    }

    // Gọi hàm đệ quy để bắt đầu quá trình sinh hoán vị từ vị trí đầu tiên (index 0)
    generatePermutations(arr, used, n, 0);

    return 0;
}