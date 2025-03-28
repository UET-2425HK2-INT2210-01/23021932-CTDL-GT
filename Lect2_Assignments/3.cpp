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

douList *addHead(douList *l, int x){
	node *temp = new node;
	temp->data = x;
	temp->prev = NULL;
	temp->next = l->head;
	l->head->prev = temp;
	l->head = temp;
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
void printList(douList *l){
	node *p = l->head;
	while (p != NULL){
		cout << p->data << " ";
		p = p->next;
	}
}

int main() {
    int n, x, count = 0;
    cin >> n >> x;
    douList *p = createList(x);
    douList *l = p;
    for (int i = 1; i < n; i++) {
        cin >> x;
        l = addTail(l, x);
    }
    node *temp = l->head;
    temp = temp->next;
    while (temp->next != NULL) {
        int sum = temp->data + temp->prev->data + temp->next->data;
        if (sum == 0) count++;
        temp = temp -> next;
    }
    cout << count;
}