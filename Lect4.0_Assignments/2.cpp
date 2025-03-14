#include <iostream>
using namespace std;

struct node {
    int data;
    int priority;
    node *next;
    node *prev;
};

struct douList {
    node *head;
    node *tail;
};

douList *createList() {
    douList *l = new douList;
    l->head = nullptr;
    l->tail = nullptr;
    return l;
}

void enqueue(douList *l, int x, int p) {
    node *temp = new node;
    temp->data = x;
    temp->priority = p;
    temp->next = nullptr;
    temp->prev = nullptr;

    if (!l->head) {
        l->head = l->tail = temp;
        return;
    }

    if (p > l->head->priority) {
        temp->next = l->head;
        l->head->prev = temp;
        l->head = temp;
        return;
    }

    node *cur = l->head;
    while (cur) {
        if (p > cur->priority) {
            temp->prev = cur->prev;
            temp->next = cur;
            if (cur->prev) cur->prev->next = temp;
            cur->prev = temp;
            if (cur == l->head) l->head = temp;
            return;
        }
        cur = cur->next;
    }

    temp->prev = l->tail;
    l->tail->next = temp;
    l->tail = temp;
}

void dequeue(douList *l) {
    if (!l->head) return;

    node *temp = l->head;
    if (l->head == l->tail) {
        l->head = l->tail = nullptr;
    } else {
        l->head = l->head->next;
        l->head->prev = nullptr;
    }
    delete temp;
}

void printQueue(douList *l) {
    node *p = l->head;
    while (p) {
        cout << "(" << p->data << "," << p->priority << "); ";
        p = p->next;
    }
    cout << "\n";
}

int main() {
    int n;
    cin >> n;

    douList *l = createList();

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        if (cmd.compare("enqueue") == 0) {
            int x, p;
            cin >> x >> p;
            enqueue(l, x, p);
        } else if (cmd.compare("dequeue") == 0) {
            dequeue(l);
        }
    }
    printQueue(l);
}
