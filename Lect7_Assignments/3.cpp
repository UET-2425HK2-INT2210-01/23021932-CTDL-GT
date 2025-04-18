#include <iostream>
using namespace std;

// Hàm đệ quy tìm ước chung lớn nhất (UCLN)
int gcd(int x, int y) {
    if (y == 0)
        return x;			// Trường hợp cơ sở: nếu y = 0, UCLN là x.
    return gcd(y, x % y); // Gọi đệ quy với y và phần dư của x chia y.
}

int main() {
    int x, y;
    cout << "Nhập X và Y: ";
    cin >> x >> y;			// Nhập hai số nguyên x và y từ người dùng.
    if (x < 0) x = -x;		// Chuyển x thành giá trị tuyệt đối nếu x âm.
    if (y < 0) y = -y;		// Chuyển y thành giá trị tuyệt đối nếu y âm.
    int result = gcd(x, y); // Gọi hàm gcd để tính UCLN của x và y.
    cout << "GCD: " << result << endl; // In ra kết quả UCLN.
    return 0;
}