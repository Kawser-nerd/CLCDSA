// Ver19.03
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 1 << 29
#define LLINF 4545454545454545454
#define MOD 1000000007
#define ll long long
#define ull unsigned long long
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int upll(const void *a, const void *b) { return *(ll *)a < *(ll *)b ? -1 : *(ll *)a > *(ll *)b ? 1 : 0; }
int downll(const void *a, const void *b) { return *(ll *)a < *(ll *)b ? 1 : *(ll *)a > *(ll *)b ? -1 : 0; }
void sortup(ll *a, int n) { qsort(a, n, sizeof(ll), upll); }
void sortdown(ll *a, int n) { qsort(a, n, sizeof(ll), downll); }

ll a[100002];
int main()
{
  ll n,ans=0,crr=1;
  scanf("%lld",&n);
  for(int i=1;i<=n;i++){
    scanf("%lld",&a[i]);
  }
  while(crr!=2&&crr!=-1){
    ll tmp=a[crr];
    a[crr]=-1;
    crr=tmp;
    ans++;
  }
  printf("%lld\n",crr==2?ans:-1);
} ./Main.c: In function ‘main’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&n);
   ^
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&a[i]);
     ^