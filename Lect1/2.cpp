#include<iostream>
#include<iomanip>
using namespace std;

class Point {
    public:
        int x, y;

        void import() {
        cin >> x >> y;
        }
};

// y = ax + b

class Line {
    public:
        Point node1, node2;
        float a, b;
        void calc() {
            a = (node1.y - node2.y)/(node1.x - node2.x);
            b = node1.y - (a*node1.x);
        }
};

int main() {
    Point A, B, C, D;
    A.import();
    B.import();
    C.import();
    D.import();
    Line AB, CD;
    AB.node1 = A;
    AB.node2 = B;
    CD.node1 = C;
    CD.node2 = D;
    AB.calc();
    CD.calc();
    if (AB.a == CD.a) {
        if (AB.b == CD.b) {
            cout << "MANY";
        } else {
            cout << "NO";
        }
    } else {
        float x = (CD.b - AB.b)/(AB.a - CD.a);
        float y = AB.a*x + AB.b;
        cout << fixed << setprecision(2) << x << " " << y;
    }
}