#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
	int T, cs=0;
	scanf("%d", &T);
	for(cs=1;cs<=T;cs++){
		long long n;
		int pd, pg;
		scanf("%lld%d%d", &n, &pd, &pg);
		int a = 100, b = 100;
		int g = __gcd(pd, a);
		string ret;
		if (pg==0 && pd>0 || pg==100 && pd<100)
			ret = "Broken";
		else {
			a/=g;
			pd/=g;
			if (a <= n)
				ret = "Possible";
			else
				ret = "Broken";
		}
		printf("Case #%d: %s\n", cs, ret.c_str());
		fprintf(stderr, "Case #%d: %s\n", cs, ret.c_str());
	}
	return 0;
}
