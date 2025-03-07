#include<iostream>
using namespace  std;

struct node {
    int data;
    node *next;
    node *prev;
};

struct douList {
    node *head;
    node *tail;
};

douList *createList(int x){
	douList *l = new douList;
	l->head = new node;
	l->head->data = x;
	l->head->prev = NULL;
	l->head->next = NULL;
	l->tail = l->head;
	return l;
}

douList *addTail(douList *l, int x){
	node *temp = new node;
	temp->data = x;
	temp->next = NULL;
	temp->prev = l->tail;
	l->tail->next = temp;
	l->tail = temp;
	return l;
}

douList *deleteHead(douList *l){
	node *p = l->head->next;
	node *temp = l->head;
	p->prev = NULL;
	l->head = p;
	delete(temp);
	return l;
}

void printList(douList *l){
	node *p = l->head;
	while (p != NULL){
		cout << p->data << " ";
		p = p->next;
	}
}

int main() {
    int n, x, count = 0;
    string s;
    douList *p = NULL;
    douList *l;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s.compare("enqueue") == 0) {
            cin >> x;
            if (count == 0) {
                l = createList(x);
            } else {
                l = addTail(l, x);
            }
            count++;
        } else {
            l = deleteHead(l);
            count--;
        }
    }
    printList(l);
}

/*

MÃ GIẢ:

1. enqueue [ O(1) ]

enqueue(*l, x):
	*temp = new node
	temp->data = x
	temp->next = NULL
	temp->prev = l->tail
	l->tail->next = temp
	l->tail = temp
	return l

2. dequeue [ O(1) ]

dequeue(*l):
    *p = l->head->next
	*temp = l->head
	p->prev = NULL
	l->head = p
	delete(temp)
	return l

*/