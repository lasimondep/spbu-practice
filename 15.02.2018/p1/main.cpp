#include <cstdio>
#include "pair_vectors.h"

int main() {
	pair_vectors p;
	FILE *fin(fopen("in.txt", "r")), *fout(fopen("out.txt", "w"));
	fscanf(fin, "%d%d%d%d", &p.a, &p.b, &p.c, &p.d);
	fprintf(fout, "dp: %d\ncp: %d\n", p.dot_product(), p.cross_product());
	fprintf(fout, "%d %d %d %d", p.a, p.b, p.c, p.d);
	fclose(fin), fclose(fout);
	return 0;
}