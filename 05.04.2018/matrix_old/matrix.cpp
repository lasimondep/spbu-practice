#include <cstring>
#include "matrix.h"

template <typename T>
matrix<T>::matrix() {
	memset(data, 0, sizeof data);
}

template <typename T>
matrix<T>::matrix(const matrix<T> &t) {
	memcpy(data, t.data, sizeof t.data);
}

/*template <typename T, size_t M, size_t N>
matrix<T, M, N>::matrix(T value) {
	for (size_t i(0); i < M; ++i)
		for (size_t j(0); j < N; ++j)
			data[i][j] = value;
}*/

template <typename T>
matrix<T>::~matrix() {
	delete data;
}