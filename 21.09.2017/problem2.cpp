#include <cstdio>

inline int f_ack(int a, int b) {
	if (a == 0)
		return b + 1;
	if (b == 0)
		return f_ack(a - 1, 1);
	return f_ack(a - 1, f_ack(a, b - 1));
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", f_ack(a, b));
	return 0;
}