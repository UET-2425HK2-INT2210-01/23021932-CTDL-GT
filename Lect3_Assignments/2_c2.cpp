#include <iostream>
using namespace std;

// Do phuc tap: O(logn)

long long powerOfTwo(int n) {
    if (n == 0) return 1;
    long long half = powerOfTwo(n / 2);
    if (n % 2 == 0) {
        return half * half;
    } else {
        return half * half * 2;
    }
}

int main() {
    int n;
    cin >> n;
    long long result = powerOfTwo(n);
    cout << result;
}


/*

MÃ GIẢ:

powerOfTwo(n):
    if n == 0:
        return 1
    half = powerOfTwo(n / 2)
    if n % 2 == 0:
        return half * half
    else:
        return half * half * 2

main():
    n
    ans = powerOfTwo(n)

*/