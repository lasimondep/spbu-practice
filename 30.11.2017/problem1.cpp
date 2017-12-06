#include <cstdio>
#include <algorithm>

int MAXN(1e5);

struct node;
typedef node* pnode;

struct node {
	unsigned key;
	pnode left, right;
	node() {}
	node(unsigned _key) : key(_key), left(NULL), right(NULL) {}
	~node() {
		if (left)
			delete left;
		if (right)
			delete right;
	}
	pnode find(unsigned k) {
		pnode t(this);
		while (t)
			if (t->key == k)
				return t;
			else
				t = t->key > k ? t->left : t->right;
		return NULL;
	}
};

pnode make(int l, int r, unsigned a[]) {
	if (l > r)
		return NULL;
	pnode t(new node(a[(l + r) >> 1]));
	t->left = make(l, ((l + r) >> 1) - 1, a), t->right = make(((l + r) >> 1) + 1, r, a);
	return t;
}

inline unsigned toIp(unsigned a, unsigned b, unsigned c, unsigned d) {
	return (1 << 24) * a + (1 << 16) * b + (1 << 8) * c + d;
}

int main() {
	int n, m;
	scanf("%d", &n);
	unsigned a, b, c, d, A[MAXN];
	for (int i(0); i < n; ++i) {
		scanf("%u.%u.%u.%u", &a, &b, &c, &d);
		A[i] = toIp(a, b, c, d);
	}
	std::sort(A, A + n);
	pnode root(make(0, n - 1, A));
	scanf("%d", &m);
	for (int i(0); i < m; ++i) {
		scanf("%u.%u.%u.%u", &a, &b, &c, &d);
		puts(root->find(toIp(a, b, c, d)) ? "YES" : "NO");
	}
	return 0;
}