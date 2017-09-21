#include <cstdio>

class Lst;

typedef Lst *pLst;

class Lst {
	private:
	int data, cnt;
	pLst prev, next;
	public:
	Lst() : data(0), cnt(1), prev(this), next(this) {}
	Lst(int data) : data(data), cnt(1), prev(this), next(this) {}
	private:
	void addnext(int x) {
		pLst t = new Lst(x);
		next->prev = t;
		t->next = next;
		t->prev = this;
		next = t;
		cnt++;
		t = this;
		for (int k(cnt); k; --k, t = t->next)
			t->cnt = cnt;
	}
	public:
	bool check(int x) {
		pLst t(this);
		for (int k(cnt); k; --k, t = t->next)
			if (t->data == x)
				return true;
		return false;
	}
	void addtwo(int a, int b, int x) {
		pLst t(this);
		for (; t->data != x; t = t->next);
		t->addnext(a);
		t = t->next;
		for (int k(cnt >> 1); k; --k, t = t->next);
		t->addnext(b);
	}
	void printlist() {
		pLst t(this);
		for (int k(cnt); k; --k, t = t->next)
			printf("%d ", t->data);
	}
};

int main() {
	pLst T;
	int cmd, a, b, x;
	printf("Possible commands:\n0\t-exit;\n-1 X\t-create new List with X (must be first cmd);\n");
	printf("1 X\t-check X in List;\n2 A B X\t-add A after X & B - diam-op A\n3\t-print List data\n");
	for (;;) {
		printf("Write cmd: ");
		scanf("%d", &cmd);
		switch(cmd) {
			case 0:
				return 0;
			case -1:
				scanf("%d", &x);
				T = new Lst(x);
				printf("List created\n");
				break;
			case 1:
				scanf("%d", &x);
				printf("%d %sincluded in List\n", x, T->check(x) ? "" : "not ");
				break;
			case 2:
				scanf("%d%d%d", &a, &b, &x);
				T->addtwo(a, b, x);
				break;
			case 3:
				printf("List data:\n");
				T->printlist();
				putchar('\n');
		}
	}
	return 0;
}
