#include<iostream>
using namespace std;
int main() {
    int a[5];
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }
    int min = a[0], max = a[0];
    for (int i = 1; i < 5; i++) {
        if (min > a[i]) min = a[i];
        if (max < a[i]) max = a[i];
    }
    cout << max + min;
}