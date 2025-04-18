#include <iostream> 

using namespace std;

int fibonacci(int n) {
    //nếu n là 0 hoặc 1, trả về giá trị tương ứng
    if (n <= 1) {
        return n;
    }
    // Bước đệ quy: tính số Fibonacci thứ n bằng tổng của hai số Fibonacci trước đó
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cin >> n;
    int result = fibonacci(n); // Gọi hàm fibonacci để tính số Fibonacci thứ n và lưu kết quả vào biến result
    cout << result << endl; // In ra kết quả
}