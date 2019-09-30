#include<stdio.h>
#include<stdlib.h>
typedef long long ll;
int n;
int N[100001];

int min(int x, int y){
  return x < y ? x : y;
}

int main(){
  int i,count;
  ll ans = 0;
  
  scanf("%d",&n);
  for(i = 1; i <= n; i++){
    scanf("%d",&count);
    N[i] = count;
  }

  for(i = 1; i <= n; i++){
    int c = N[i]/2;
    ans += c;
    N[i] -= c*2;
    if(i+1 <= n && N[i] != 0 && N[i+1] != 0){
	N[i]--;
	N[i+1]--;
	ans++;
    }
  }
  printf("%lld\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&count);
     ^