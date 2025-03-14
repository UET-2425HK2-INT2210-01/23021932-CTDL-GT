#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node *createNode(int x) {
    node *temp = new node;
    temp->data = x;
    temp->next = nullptr;
    return temp;
}

node *append(node *p, int x) {
    node *temp = createNode(x);
    p->next = temp;
    return temp;
}

void search(node *p, int x) {
    int ans = -1, temp = 0;
    node *l = p;
    while (l != nullptr) {
        if (l->data == x) {
            ans = temp;
            break;
        }
        temp++;
        l = l->next;
    }
    if (ans == -1) {
        cout << "NO" << endl;
    } else {
        cout << ans << endl;
    }
}

node* reverse(node* head) {
    node* prev = nullptr;
    node* curr = head;
    node* next = nullptr;
    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(node *l) {
    node *p = l;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int n, x, count = 0;
    string s;
    node *p = nullptr;
    node *l = p;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s.compare("append") == 0) {
            cin >> x;
            if (count == 0) {
                l = createNode(x);
                p = l;
                count++;
            }
            else {
                p = append(p, x);
                count++;
            }
        } else if (s.compare("search") == 0) {
            cin >> x;
            search(l, x);
        } else {
            l = reverse(l);
            printList(l);
        }
    }
}
