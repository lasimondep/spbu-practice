#include <algorithm>
#include <cstdio>

const int MAXN(1e5);

using namespace std;

struct heap {
	int size;
	pair <int, int> data[MAXN]; //time, id
	heap() : size(0) {}
	void shift_up(int v) {
		while (v > 0 && data[v] < data[(v - 1) >> 1]) {
			swap(data[v], data[(v - 1) >> 1]);
			v = (v - 1) >> 1;
		}
	}
	void shift_down(int v) {
		int to;
		while ((v << 1) + 1 < size) {
			to = (v << 1) + 1;
			if ((v << 1) + 2 < size && data[(v << 1) + 2] < data[(v << 1) + 1])
				to = (v << 1) + 2;
			if (data[v] <= data[to])
				break;
			swap(data[v], data[to]);
			v = to;
		}
	}
	int get_size() {
		return size;
	}
	pair <int, int> get_min() {
		return data[0];
	}
	void extract_min() {
		data[0] = data[--size];
		shift_down(0);
	}
	void insert(int x, int id) {
		data[size] = make_pair(x, id);
		shift_up(size++);
	}
};

int main() {
	int id(0), tick(0), c, t;
	heap h;
	puts("Type \"0\" for exit\nType \"1 t\" for add event of duration = t\nType \"2\" for print all active events\nType \"3 t\" for add t ticks");
	for (;;) {
		printf("[Tick = %d]\n", tick);
		scanf("%d", &c);
		switch (c) {
			case 0:
				return 0;
			case 1:
				scanf("%d", &t);
				h.insert(tick + t, ++id);
				break;
			case 2:
				printf(h.get_size() ? "Active events:\n" : "No active events");
				for (int i(0); i < h.get_size(); ++i)
					printf("%d ", h.data[i].second);
				printf("\n");
				break;
			case 3:
				scanf("%d", &t);
				tick += t;
				while (h.get_size() > 0 && h.get_min().first <= tick) {
					printf("Event #%d is complete\n", h.get_min().second);
					h.extract_min();
				}
		}
		printf("\n");
	}
	return 0;
}