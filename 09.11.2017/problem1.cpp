#include <cstdio>

struct node {
	int data;
	node *next;
	node() : next(NULL) {}
	node(int x, node *n) : data(x), next(n) {}
};

struct Stack {
	node *top;
	Stack() : top(NULL) {}
	~Stack() {
		while (top != NULL)
			this->pop();
	}
	int front() {
		if (top == NULL) {
			puts("Stack is empty!");
			return -1;
		}
		return top->data;
	}
	void push(int x) {
		top = new node(x, top);
	}
	int pop() {
		if (top == NULL) {
			puts("Stack is empty!");
			return -1;
		}
		node *temp(top);
		int t(top->data);
		top = top->next;
		delete temp;
		return t;
	}
};

int main() {
	Stack *s = new Stack();
	int c, x;
	puts("type \"-1\" for exit\n\"1 x\" for push(x)\n\"2\" for pop()\n\"3\" for front()");
	for (;;) {
		scanf("%d", &c);
		if (c < 0)
			return 0;
		switch (c) {
			case 1:
				scanf("%d", &x);
				s->push(x);
				break;
			case 2:
				s->pop();
				break;
			case 3:
				printf("%d\n", s->front());
		}			
	}
	return 0;
}