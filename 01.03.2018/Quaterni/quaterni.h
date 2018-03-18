class quaterni {
	private:
	double a, b, c, d;
	public:
	quaterni() : a(0), b(0), c(0), d(0) {}
	quaterni(double _a, double _b, double _c, double _d) : a(_a), b(_b), c(_c), d(_d) {}
	quaterni &operator+=(const quaterni &x);
	quaterni &operator*=(const quaterni &x);
	quaterni &operator*=(const double x);
	quaterni operator-();
	quaterni &operator-=(const quaterni &x);
	quaterni operator!();
	double norm();
	quaterni &operator/=(const quaterni &x);
	void print(const char msg[]);
};
