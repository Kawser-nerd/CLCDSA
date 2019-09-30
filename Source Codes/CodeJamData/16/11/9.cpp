#include <cstdio>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int n;
char S[10000];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", S);
		int l = strlen(S);
		string s = "";
		s = s + S[0];
		for (int j = 1; j < l; j++)
			if (S[j] >= s[0])
				s = S[j] + s;
			else
				s = s + S[j];
		printf("Case #%d: ", i);
		cout << s << endl;
	}
}
