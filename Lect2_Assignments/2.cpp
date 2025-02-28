/* #include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *createNode (int x) {
    node *temp = new node;
    temp -> data = x;
    temp -> next = NULL;
    return temp;
}

node *addElement(node *l, int x) {
    node *temp = createNode(x);
    l -> next = temp;
    return temp;
}

void printList(node *l) {
    node *p = l;
    while (p != NULL) {
        cout << p -> data << " ";
        p = p -> next;
    }
}

node *addAt(node *l, int k, int x){
	node *p = l;
	for (int i = 0; i < k-1; i++){
		p = p->next;
	}
	node *temp = new node;
	temp->data = x;
	temp->next = p->next;
	p->next = temp;
	return l;
}

node *deleteAt(node *l, int k){
	node *p = l;
	for (int i = 0; i < k-1; i++){
		p = p->next;
	}
	node *temp = p->next;
	p->next = p->next->next;
	delete(temp);
	return l;
}

node *addHead(node *l, int x) {
    node *temp = new node;
    temp -> data = x;
    temp -> next = l;
    l = temp;
    return l;
}

node *addTail(node *l, int x) {
    node *p = l;
    while (p -> next != NULL) {
        p = p -> next;
    }
    node *temp = new node;
    temp -> data = x;
    temp -> next = NULL;
    p -> next = temp;
    return l;
}

int main() {
    int n, x, k, count = 0;
    string s;
    cin >> n;
    node *p = NULL;
    node *l = p;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s.compare("insert") == 0) {
            cin >> k >> x;
            if (count == 0) {
                l = createNode(x);
            }    
            else {
                cin >> k >> x;
                if (k == count) {
                    l = addTail(l, x);
                } else if (k == 0) {
                    l = addHead(l, x);
                } else {
                    l = addAt(l, k, x);
                }
            }
            printList(l);
            count++;
        } else {
            cin >> k;
            l = deleteAt(l, k);
            printList(l);
            count--;
        }
    }
    printList(p);
}
*/
#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *createNode (int x) {
    node *temp = new node;
    temp -> data = x;
    temp -> next = NULL;
    return temp;
}

node *addElement(node *l, int x) {
    node *temp = createNode(x);
    l -> next = temp;
    return temp;
}

void printList(node *l) {
    node *p = l;
    while (p != NULL) {
        cout << p -> data << " ";
        p = p -> next;
    }
}

node *addAt(node *l, int k, int x){
    node *p = l;
    for (int i = 0; i < k-1; i++){
        p = p->next;
    }
    node *temp = new node;
    temp->data = x;
    temp->next = p->next;
    p->next = temp;
    return l;
}

node *deleteAt(node *l, int k){
    node *p = l;
    for (int i = 0; i < k-1; i++){
        p = p->next;
    }
    node *temp = p->next;
    p->next = p->next->next;
    delete(temp);
    return l;
}

node *addHead(node *l, int x) {
    node *temp = new node;
    temp -> data = x;
    temp -> next = l;
    l = temp;
    return l;
}

node *addTail(node *l, int x) {
    node *p = l;
    while (p -> next != NULL) {
        p = p -> next;
    }
    node *temp = new node;
    temp -> data = x;
    temp -> next = NULL;
    p -> next = temp;
    return l;
}

int main() {
    int n, x, k, count = 0;
    string s;
    cin >> n;
    node *p = NULL;
    node *l = p;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s.compare("insert") == 0) {
            cin >> k >> x;
            if (count == 0) {
                l = createNode(x);
                count++;
            }
            else {
                if (k == count) {
                    l = addTail(l, x);
                } else if (k == 0) {
                    l = addHead(l, x);
                } else {
                    l = addAt(l, k, x);
                }
                count++;
            }
        } else {
            cin >> k;
            l = deleteAt(l, k);
            count--;
        }
    }
    printList(l);
}
