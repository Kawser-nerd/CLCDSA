#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_N = 100;
int N, K;
int X[MAX_N];
int main(){
scanf("%d", &N);
scanf("%d", &K);
for(int i = 0; i < N; ++i){
scanf("%d", X + i);
}
int ans = 0;
for(int i = 0; i < N; ++i){
int tmp = min(X[i], K - X[i]);
ans += tmp;
}
printf("%d\n", ans * 2);
return 0;
}