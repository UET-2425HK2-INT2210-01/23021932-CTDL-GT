#include <iostream>

using namespace std;

// Hàm đệ quy để đảo ngược một số nguyên dương n
int reverseNum(int n, int reversedNum) {
    // Trường hợp cơ sở: nếu n bằng 0, trả về số đã đảo ngược
    if (n == 0) {
        return reversedNum;
    }
    // Lấy chữ số cuối cùng của n
    int remainder = n % 10;
    // Cập nhật số đã đảo ngược bằng cách thêm chữ số cuối cùng vào vị trí hàng đơn vị
    reversedNum = reversedNum * 10 + remainder;
    // Gọi đệ quy với phần còn lại của n (sau khi đã bỏ chữ số cuối cùng) và số đã đảo ngược
    return reverseNum(n / 10, reversedNum);
}

int main() {
    int n;
    cin >> n;
    int reversedNumber = reverseNum(n, 0);
    cout << reversedNumber;
}