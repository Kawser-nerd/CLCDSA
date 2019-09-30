#include <cstdio>
#include <algorithm>
#include <cmath>
#define maxn 500005

using namespace std;

struct node{
	long long pos, num;
}a[maxn];

long long n, s, ans = 0;

bool cmp(node x, node y){ return (x.pos < y.pos); }

int main(){
	scanf("%lld%lld", &n, &s);
	
	for (long long i = 1; i <= n; i++) scanf("%lld%lld", &a[i].pos, &a[i].num);
	sort(a + 1, a + n + 1, cmp);
	
	long long left = 1, right = n;
	
	while (left <= right){
		if (a[right].pos <= s){
			ans += (s - a[left].pos);
			break;
		}
		if (a[left].pos >= s){
			ans += (a[right].pos - s);
			break;
		}
		
		ans += (a[right].pos - a[left].pos);
		if (a[left].num >= a[right].num){
			while (left < right && a[left].num >= a[right].num) a[left].num += a[right--].num;
		}
		else{
			while (left < right && a[right].num > a[left].num) a[right].num += a[left++].num;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}