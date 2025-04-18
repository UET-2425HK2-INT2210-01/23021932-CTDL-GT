#include<iostream>
using namespace std;

int sum1toN(int n) {
    // Điều kiện dừng của đệ quy: nếu n lớn hơn 0
    if (n > 0) {
        // Trả về tổng của n và tổng các số từ 1 đến n-1 (bước đệ quy)
        return n + sum1toN(n-1);
    }
    // nếu n không lớn hơn 0 (n <= 0), tổng là 0
    return 0;
}

int main() {
    int n;
    cin >> n;
    cout << sum1toN(n);
}
