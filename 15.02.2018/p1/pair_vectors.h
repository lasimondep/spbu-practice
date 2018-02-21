struct pair_vectors {
	int a, b, c, d;
	int dot_product() {
		return a * c + b * d;
	}
	int cross_product() {
		return a * d - b * c;
	}
};