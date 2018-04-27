#include <cstdlib>
#include <cstdio>
#include <ctime>

class foo {
	private:
	int a, b;
	char c;
	double d;
	public:
	foo() {}
	foo(int _a, int _b, char _c, double _d) : a(_a), b(_b), c(_c), d(_d) {}
	void print() {
		printf("%d %d '%c' %.5lf\n", a, b, c, d);
	}
};

const size_t FOO_SIZE(sizeof(foo));
const size_t BUF_SIZE(1e5);

void saving() {
	srand(time(NULL));
	size_t n;
	printf("Print size of array: ");
	scanf("%d", &n);
	foo *bar[n];
	char cmd;
	for (;;) {
		for (size_t i(0); i < n; ++i)
			bar[i] = new foo(rand(), rand(), 'A' + rand() % ('Z' - 'A'), rand() * 1.0 / rand());
		for (auto x: bar)
			x->print();
		printf("Save this array? [Y]/N: ");
		getchar();
		cmd = getchar();
		if (cmd == 'Y' || cmd == 'y' || cmd == '\n')
			break;
	}
	char *filename(new char);
	printf("Type filename for save: ");
	scanf("%s", filename);
	FILE *out(fopen(filename, "wb"));
	for (auto x: bar)
		fwrite(reinterpret_cast<char*>(x), 1, FOO_SIZE, out);
	fclose(out);
	printf("Array saved in file '%s'", filename);
}

void loading() {
	static char buf[BUF_SIZE];
	char *filename(new char);
	printf("Type filename for load: ");
	scanf("%s", filename);
	FILE *in(fopen(filename, "rb"));
	size_t n(fread(buf, 1, BUF_SIZE, in));
	for (size_t i(0); i < n; i += FOO_SIZE)
		reinterpret_cast<foo*>(buf + i)->print();
	fclose(in);
}

int main() {
	printf("What do you want?\n0::\tquit\n1::\tgenerate & save data\n2::\tload data\n");
	int cmd;
	scanf("%d", &cmd);
	switch (cmd) {
		case 0:
			return 0;
		case 1:
			saving();
			break;
		case 2:
			loading();
	}
	return 0;
}