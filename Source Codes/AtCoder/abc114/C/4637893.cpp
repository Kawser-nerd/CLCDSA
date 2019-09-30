#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>

using namespace std;
int ans = 0;
void _dfs(unsigned long& n,unsigned long now, int x3, int x5, int x7){
	if(now <= n){
		ans += x3 > 0 and x5 > 0 and x7 > 0;
		_dfs(n, now*10+3, x3+1, x5,x7);
		_dfs(n, now*10+5, x3, x5+1, x7);
		_dfs(n, now*10+7, x3, x5, x7+1);
	}
}

int main(){
	unsigned long n;
	scanf("%d", &n);
	_dfs(n, 0, 0, 0, 0);
	printf("%d",ans);
	return 0;
	

	
	
} ./Main.cpp:20:14: warning: format specifies type 'int *' but the argument has type 'unsigned long *' [-Wformat]
        scanf("%d", &n);
               ~~   ^~
               %ld
1 warning generated.