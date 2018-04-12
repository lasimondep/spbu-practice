#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

ifstream fin;
ofstream fout;

string s;
map <string, size_t> words;
map <char, size_t> symb;

int main() {
	fin.open("text.txt");
	while (fin >> s) {
		for (auto &c: s) {
			symb[c]++;
			c = toupper(c);
		}
		s.erase(remove_if(s.begin(), s.end(), [](const char &C){return C != '-' && C != '`' && ispunct(C);}), s.end());
		words[s]++;
	}
	fin.close();

	fout.open("words.txt");
	for (auto it: words)
		fout << it.first << ' ' << it.second << '\n';
	fout.close();

	fout.open("symbols.txt");
	for (auto it: symb)
		fout << it.first << ' ' << it.second << '\n';
	fout.close();

	cout << "Print command num:\n0::\tquit\n1::\twords frequency\n2::\tsymbols frequency\n";
	int cmd;
	for (;;) {
		cin >> cmd;
		if (cmd)
			cin >> s;
		else
			break;
		switch (cmd) {
			case 1:
				for (auto &c: s)
					c = toupper(c);
				cout << "Word " << s << " is printed " << words[s] << " times\n";
				break;
			case 2:
				cout << "Symbol '" << s << "' is printed " << symb[*s.c_str()] << " times\n";
		}
	}
	return 0;
}