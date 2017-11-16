#include <cstdio>

struct node {
	int data;
	node *next;
	node() : next(NULL) {}
	node(int x, node *n) : data(x), next(n) {}
};

struct Queue {
	node *tail;
	Queue() : tail(NULL) {}
	~Queue() {
		while (tail != NULL)
			this->pop();
	}
	int front() {
		if (tail == NULL) {
			puts("Queue is empty!");
			return -1;
		}
		node *temp(tail);
		while (temp->next != NULL)
			temp = temp->next;
		return temp->data;
	}
	void push(int x) {
		tail = new node(x, tail);
	}
	int pop() {
		if (tail == NULL) {
			puts("Queue is empty!");
			return -1;
		}
		if (tail->next == NULL) {
			int t(tail->data);
			delete tail;
			tail = NULL;
			return t;
		}
		node *temp(tail);
		while (temp->next->next != NULL)
			temp = temp->next;
		int t(temp->next->data);
		delete temp->next;
		temp->next = NULL;
		return t;
	}
};

int main() {
	Queue *q = new Queue();
	int c, x;
	puts("type \"-1\" for exit\n\"1 x\" for push(x)\n\"2\" for pop()\n\"3\" for front()");
	for (;;) {
		scanf("%d", &c);
		if (c < 0)
			return 0;
		switch (c) {
			case 1:
				scanf("%d", &x);
				q->push(x);
				break;
			case 2:
				q->pop();
				break;
			case 3:
				printf("%d\n", q->front());
		}			
	}
	return 0;
}