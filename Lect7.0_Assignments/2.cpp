#include<iostream>
using namespace std;

int giaiThua(int n) {
    // Điều kiện dừng của đệ quy: nếu n lớn hơn 1
    if (n > 1) {
        // Trả về tích của n và giai thừa của n-1 (bước đệ quy)
        return n * giaiThua(n-1);
    }
    //nếu n không lớn hơn 1 (n = 0 hoặc n = 1), giai thừa là 1
    return 1;
}

int main() {
    int n;
    cin >> n;
    cout << giaiThua(n);
}
