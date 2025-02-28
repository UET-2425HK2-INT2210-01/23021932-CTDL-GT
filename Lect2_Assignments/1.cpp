#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node *createNode(int x) {
    node *temp = new node;
    temp -> data = x;
    temp -> next = NULL;
    return temp;
}

node *addElement(node *p, int x) {
    node *temp = createNode(x);
    p -> next = temp;
    return temp;
}

int countPairs(node *p) {
    int count = 0;
    node *l = p, *n = p;
    while (l != NULL) {
        n = l -> next;
        while (n != NULL) {
            if (l -> data == n -> data) {
                count++;
            }
            n = n -> next;
        }
        l = l -> next;
    }
    return count;
}

int main() {
    int n, x;
    cin >> n >> x;
    node *l = createNode(x);
    node *p = l;
    for (int i = 1; i < n; i++) {
        cin >> x;
        p = addElement(p, x);
    }

    cout << countPairs(l);
}