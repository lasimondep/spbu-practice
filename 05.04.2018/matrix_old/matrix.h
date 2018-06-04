#include <cstring>

template <typename T>
class matrix {
	public:
	T data[5][5];
//	template <typename>
//	friend class matrix;
	matrix();
	matrix(const matrix <T> &);
	~matrix();
};