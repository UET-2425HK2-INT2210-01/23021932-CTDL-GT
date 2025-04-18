#include <iostream>
using namespace std;

// Hàm đệ quy sinh tất cả các chuỗi nhị phân độ dài n bằng backtracking
void generateBinary(int n, string &current, int index) {
    // Điều kiện dừng: khi đã xây dựng xong chuỗi có độ dài n
    if (index == n) {
        cout << current << endl; // In ra chuỗi nhị phân hoàn chỉnh
        return;
    }
    // Thử gán '0' vào vị trí hiện tại
    current[index] = '0';
    generateBinary(n, current, index + 1); // Gọi đệ quy để tiếp tục xây dựng chuỗi

    // Thử gán '1' vào vị trí hiện tại
    current[index] = '1';
    generateBinary(n, current, index + 1); // Gọi đệ quy để tiếp tục xây dựng chuỗi
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n; // Nhập độ dài n của chuỗi nhị phân từ người dùng

    // Khởi tạo chuỗi 'current' có độ dài n, ban đầu tất cả các ký tự là '0'
    string current(n, '0');

    // Gọi hàm đệ quy để bắt đầu quá trình sinh các chuỗi nhị phân
    generateBinary(n, current, 0);

    return 0;
}