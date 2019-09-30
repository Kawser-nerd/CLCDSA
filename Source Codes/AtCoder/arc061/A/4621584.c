#include<stdio.h>
int max(int a, int b){return a<b?b:a;}
char S[11], s, c, j;
long long int n, i;
long long int now, ans, f;

int main(){
	while((c=getchar())!=10){S[s++]=c-'0';}
	n = 1<<s-1;
	for(i=0; i<n; i++){
		now=0; f=0;
		for(j=0; j<s; j++){
			f=f*10+S[j];
			if((i>>j)&1){
				now+=f; f=0;
			}
		}
		now+=f;
		ans += now;
	}
	printf("%lld\n", ans);
}