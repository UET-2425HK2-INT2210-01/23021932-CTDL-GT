#include <iostream>

using namespace std;

int power(int x, int n) {
    // Trường hợp cơ sở: nếu n bằng 0, x^0 = 1
    if (n == 0) {
        return 1;
    }
    // Bước đệ quy: x^n = x * x^(n-1)
    return x * power(x, n - 1);
}

int main() {
    int x;
    int n;
    cin >> x >> n;
    int result = power(x, n);
    cout << result;
    return 0;
}