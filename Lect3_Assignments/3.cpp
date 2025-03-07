#include <iostream>
#include <string>
using namespace std;

void enqueue(int *a, int x, int &countElement) {
    countElement += 1;
    a[countElement] = x;
}

void dequeue(int *a, int &countElement) {
    for (int i = 0; i < countElement; i++) {
        a[i] = a[i+1];
    }
    countElement--;
}

int main() {
    int n, a[10000], countElement = 0, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "enqueue") {
            cin >> x;
            enqueue(a, x, countElement);
        } else if (s == "dequeue") {
            dequeue(a, countElement);
        }
    }
    for (int i = 1; i <= countElement; i++) {
        cout << a[i] << " ";
    }
}

/*

MÃ GIẢ:

1. enqueue [ O(1) ]

enqueue(*a, x, &countElement) {
    countElement += 1
    a[countElement] = x
}

2. dequeue [ O(1) ]

dequeue(*a, &countElement) {
    for (int i = 0; i < countElement; i++):
        a[i] = a[i+1]
    
    countElement--;
}

*/