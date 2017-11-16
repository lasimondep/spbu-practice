#include <cstdio>

struct node {
	int data;
	node *next, *prev;
	node() : next(NULL), prev(NULL) {}
	node(int x, node *n, node *p) : data(x), next(n), prev(p) {}
};

struct Deque {
	node *head, *tail;
	Deque() : head(NULL), tail(NULL) {}
	~Deque() {
		while (tail != NULL)
			this->pop_back();
	}
	int back() {
		if (tail == NULL) {
			puts("Deque is empty!");
			return -1;
		}
		return tail->data;
	}
	int front() {
		if (head == NULL) {
			puts("Deque is empty!");
			return -1;
		}		
		return head->data;
	}
	void push_back(int x) {
		tail = new node(x, tail, NULL);
		if (head == NULL)
			head = tail;
		if (tail->next != NULL)
			tail->next->prev = tail;
	}
	void push_front(int x) {
		head = new node(x, NULL, head);
		if (tail == NULL)
			tail = head;
		if (head->prev != NULL)
			head->prev->next = head;
	}
	int pop_back() {
		if (tail == NULL) {
			puts("Deque is empty!");
			return -1;
		}		
		int t(tail->data);
		if (tail->next != NULL) {
			tail = tail->next;
			delete tail->prev;
			tail->prev = NULL;
		} else {
			delete tail;
			tail = head = NULL;
		}
		return t;
	}
	int pop_front() {
		if (head == NULL) {
			puts("Deque is empty!");
			return -1;
		}		
		int t(head->data);
		if (head->prev != NULL) {
			head = head->prev;
			delete head->next;
			head->next = NULL;
		} else {
			delete head;
			head = tail = NULL;
		}
		return t;
	}
};

int main() {
	Deque *d = new Deque();
	int c, x;
	puts("type \"-1\" for exit\n\"1 x\" for push_back(x)\n\"2 x\" for push_front()\n\"3\" for back()\n\"4\" for front()\n\"5\" for pop_back()\n\"6\" for pop_front()");
	for (;;) {
		scanf("%d", &c);
		if (c < 0)
			return 0;
		switch (c) {
			case 1:
				scanf("%d", &x);
				d->push_back(x);
				break;
			case 2:
				scanf("%d", &x);
				d->push_front(x);
				break;
			case 3:
				printf("%d\n", d->back());
				break;
			case 4:
				printf("%d\n", d->front());
				break;
			case 5:
				d->pop_back();
				break;
			case 6:
				d->pop_front();
		}			
	}
	return 0;
}