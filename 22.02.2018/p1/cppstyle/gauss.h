#include "const.h"

class gauss {
	private:
	double a[MAXN][MAXN], x[MAXN];
	int n, m, v[MAXN];
	int calc();
	public:
	void read(int po);
	void write_ans();	
};