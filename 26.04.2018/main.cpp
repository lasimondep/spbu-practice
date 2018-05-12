#include <cstring>
#include <cstdio>
#include <regex>

using namespace std;

int main() {
	freopen("url_in.txt", "r", stdin), freopen("url_out.txt", "w", stdout);
	char *s(new char);
	regex r("http://");
	while (gets(s))
		puts(regex_replace(s, r, "https://").c_str());
	return 0;
}