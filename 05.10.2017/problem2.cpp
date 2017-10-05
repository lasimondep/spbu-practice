#include <cstdio>

class complex {
    private:
	double re, im;
	public:
	complex() {}
	complex(double Re, double Im) : re(Re), im(Im) {}
	complex(const complex &t) : re(t.re), im(t.im) {}
	double abs2() {
		return re * re + im * im;
	}
	void print(const char *text) {
		printf("%s%.2f + %.2fi\n", text, re, im);
	}
	complex operator=(const complex &t) {
		re = t.re, im = t.im;
		return *this;
	}
	complex operator+(const complex &t) {
		return complex(re + t.re, im + t.im);
	}
	complex operator*(const complex &t) {
		return complex(re * t.re - im * t.im, re * t.im + im * t.re);
	}
	double get_re() {
		return re;
	}
	double get_im() {
		return im;
	}
};

int main() {
	complex a(1, 1), b(2, 2);
	a.print("a = ");
	b.print("b = ");
	(a + b).print("a + b = ");
	(a * b).print("a * b = ");
	return 0;
}