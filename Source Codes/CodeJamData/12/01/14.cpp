#ifdef DEBUG
	#define D(x...) fprintf(stderr,x);
#else
	#define D(x...) 0
#endif
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

char* trans_to = "yhesocvxduiglbkrztnwjpfmaq";

int main() {
	int nTests;
	scanf("%d ",&nTests);
	for (int test=1;test<=nTests;test++) {
		if (1) fprintf(stderr,"Case %d/%d\n",test,nTests);
		
		char* s;
		scanf("%a[^\n]\n",&s);
		for (int i = 0; i < strlen(s); i++) {
			if (s[i] == ' ') continue;
			s[i] = trans_to[s[i]-'a'];
		}
		
		printf("Case #%d: %s\n",test,s);
	}
}
