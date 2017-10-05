#include <cstdio>
#include <cstring>

class String {
	private:
	char *data;
	int len;
	public:
	String() {}
	String(const char *s) : data(new char[strlen(s) + 1]), len(strlen(s)) {
		memcpy(data, s, len + 1);
	}
	~String() {
		delete[] data;
	}
	String(const String &s) : data(new char[s.len + 1]), len(s.len) {
		memcpy(data, s.data, len + 1);
	}
	void print() {
		printf("%s\n", data);
	}
	int getlen() {
		return len;
	}
	String operator=(const String &s) {
		delete[] data;
		data = new char[s.len + 1], len = s.len;
		memcpy(data, s.data, len + 1);
		return *this;
	}
	char &operator[](const int id) {
		return data[id];
	}
};

int main() {
	String s("Hello");
	String d = "World!";
	printf("Len(s) = %d, s = ", s.getlen());
	s.print();
	printf("Len(d) = %d, d = ", d.getlen());
	d.print();
	d = s;
	printf("d = ");
	d.print();
	printf("d[0] = %c\n", d[0]);
	d[0] = 'P';
	printf("d[0] = %c\n", d[0]);
	return 0;
}