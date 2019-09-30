#include <cstdio>
using namespace std;
using ll = long;
const ll N = 200010;
ll a[N], n, k, pos;
int main()
{
	scanf("%lld%lld", &n, &k);
	for (ll i = 1; i <= n; i++)
		scanf("%lld", a + i);
	for (ll i = 1; i < n; i++)
		if (a[i] + a[i + 1] >= k)
		{
			pos = i;
			break;
		}
	if (pos == 0)
		return puts("Impossible"), 0;
	puts("Possible");
	for (ll i = 1; i < pos; i++)
		printf("%lld\n", i);
	for (ll i = n -1; i > pos ; i--)
		printf("%lld\n", i);
	printf("%lld", pos);
} ./Main.cpp:8:20: warning: format specifies type 'long long *' but the argument has type 'll *' (aka 'long *') [-Wformat]
        scanf("%lld%lld", &n, &k);
               ~~~~       ^~
               %ld
./Main.cpp:8:24: warning: format specifies type 'long long *' but the argument has type 'll *' (aka 'long *') [-Wformat]
        scanf("%lld%lld", &n, &k);
                   ~~~~       ^~
                   %ld
./Main.cpp:10:17: warning: format specifies type 'long long *' but the argument has type 'll *' (aka 'long *') [-Wformat]
                scanf("%lld", a + i);
                       ~~~~   ^~~~~
                       %ld
./Main.cpp:21:20: warning: format specifies type 'long long' but the argument has type 'll' (aka 'long') [-Wformat]
                printf("%lld\n", i);
                        ~~~~     ^
                        %ld
./Main.cpp:23:20: warning: format specifies type 'long long' but the argument has type 'll' (aka 'long') [-Wformat]
                printf("%lld\n", i);
                ...