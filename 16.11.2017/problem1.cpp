#include <cstdio>
#include <algorithm>

struct node {
	int data;
	node *next;
	node() : next(NULL) {}
	node(int x, node *n) : data(x), next(n) {}
};

struct List {
	node *tail;
	List() : tail(NULL) {}
	~List() {
		node *temp;
		while (tail != NULL) {
			temp = tail;
			tail = tail->next;
			delete temp;
		}
	}
	void insert(int x) {
		tail = new node(x, tail);
	}
	void Sort() {
		for (node *i(tail); i != NULL; i = i->next)
			for (node *j(tail); j != NULL; j = j->next)
				if (j->next != NULL && j->data > j->next->data)
					std::swap(j->data, j->next->data);
	}
};

int main() {
	int n, x;
	scanf("%d", &n);
	List *l = new List();
	for (int i(0); i < n; ++i) {
		scanf("%d", &x);
		l->insert(x);
	}
	l->Sort();
	for (node *i(l->tail); i != NULL; i = i->next)
		printf("%d ", i->data);
	return 0;
}