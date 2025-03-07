#include <iostream>
#include <string>
using namespace std;

void push(int *a, int x, int &countElement) {
    countElement += 1;
    a[countElement] = x;
}

void pop(int *a, int &countElement) {
    countElement--;
}

int main() {
    int n, a[10000], countElement = 0, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "push") {
            cin >> x;
            push(a, x, countElement);
        } else if (s == "pop") {
            pop(a, countElement);
        }
    }
    for (int i = 1; i <= countElement; i++) {
        cout << a[i] << " ";
    }
}

/*

MÃ GIẢ:

1. push [ O(1) ]

push(*a, x, &countElement):
    countElement += 1
    a[countElement] = x

2. pop [ O(1) ]

pop(int *a, int &countElement):
    countElement--

*/