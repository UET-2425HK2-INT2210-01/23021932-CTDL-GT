#include <iostream>

using namespace std;

int sumOfDigits(int n) {
    // Trường hợp cơ sở: nếu n bằng 0, tổng các chữ số là 0
    if (n == 0) {
        return 0;
    }
    // Bước đệ quy: lấy chữ số cuối cùng (n % 10), cộng với tổng các chữ số của phần còn lại (n / 10)
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int n;
    cin >> n;
    int sum = sumOfDigits(n);
    cout << sum;
}