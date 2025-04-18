#include <iostream>

using namespace std;

int countDigits(int n) {
    // Trường hợp cơ sở: nếu n bằng 0, số chữ số là 0
    if (n == 0) {
        return 0;
    }
    // Bước đệ quy: loại bỏ chữ số cuối cùng và đếm số chữ số của phần còn lại, sau đó cộng thêm 1
    return 1 + countDigits(n / 10);
}

int main() {
    int n;
    cin >> n;
    int numDigits = countDigits(n);
    cout << numDigits;
}