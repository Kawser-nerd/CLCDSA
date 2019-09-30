#include<stdio.h>

int max(int a, int b){return a<b?b:a;}
long long int min(long long int a, long long int b){return a>b?b:a;}
long long int dif(long long int a, long long int b){return a<b?b-a:a-b;}

#define MIN -100000000000

int A, B, Q, i;
long long int s[100001], t[100001], x;
int a, b, c, d;
long long int now, Min;

int searchA(long long int k){
	int l=0;
	int r=A;
	int m;
	while(r>l+1){
		m = (l+r)>>1;
		if(s[m]>=k){
			r=m;
		}else{
			l=m;
		}
	}
	return r;
}

int searchB(long long int k){
	int l=0;
	int r=B;
	int m;
	while(r>l+1){
		m = (l+r)>>1;
		if(t[m]>=k){
			r=m;
		}else{
			l=m;
		}
	}
	return r;
}

int main(){
	scanf("%d%d%d", &A, &B, &Q);
	s[0] = MIN;
	for(i=1; i<=A; i++){
		scanf("%lld", s+i);
	}
	t[0] = MIN;
	for(i=1; i<=B; i++){
		scanf("%lld", t+i);
	}
	for(i=0; i<Q; i++){
		scanf("%lld", &x);
		a=searchA(x);
		b=searchB(x);
		c=max(0, a-1);
		d=max(0, b-1);
		Min = dif(x, s[a]) + dif(s[a], t[searchB(s[a])]);
		now = dif(x, s[a]) + dif(s[a], t[searchB(s[a])-1]);	Min=min(Min, now);
		now = dif(x, s[c]) + dif(s[c], t[searchB(s[c])]);	Min=min(Min, now);
		now = dif(x, s[c]) + dif(s[c], t[searchB(s[c])-1]);	Min=min(Min, now);
		now = dif(x, t[b]) + dif(t[b], s[searchA(t[b])]);	Min=min(Min, now);
		now = dif(x, t[b]) + dif(t[b], s[searchA(t[b])-1]);	Min=min(Min, now);
		now = dif(x, t[d]) + dif(t[d], s[searchA(t[d])]);	Min=min(Min, now);
		now = dif(x, t[d]) + dif(t[d], s[searchA(t[d])-1]);	Min=min(Min, now);
		printf("%lld\n", Min);
	}
} ./Main.c: In function ‘main’:
./Main.c:45:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &A, &B, &Q);
  ^
./Main.c:48:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", s+i);
   ^
./Main.c:52:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", t+i);
   ^
./Main.c:55:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &x);
   ^