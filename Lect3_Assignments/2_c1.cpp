#include<iostream>
using namespace std;

// Do phuc tap: O(n)

int main() {
    long long n, result = 2;
    cin >> n;
    for (int i = 1; i < n; i++) {
        result *= 2;
    }
    cout << result;
}

/*

MÃ GIẢ:

main():
    n
    result = 2
    for i = 1 to n - 1:
        result = result * 2

*/