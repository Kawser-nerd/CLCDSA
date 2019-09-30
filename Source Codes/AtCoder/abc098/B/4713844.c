#include<stdio.h>
char max(char a, char b){return a<b?b:a;}
short n, i;
char s[101];
char l[26], r[26], now, ans;
int main(void){
	scanf("%d\n", &n);
	register char c;
	c=getchar()-'a';
	s[0]=c;
	l[c]++;
	for(i=1; i<n; i++){
		c=getchar()-'a';
		s[i]=c;
		r[c]++;
	}
	if(r[s[0]]>0){ans=now=1;}
	for(i=1; i<n; i++){
		c=s[i];
		now+=(l[c]==0);
		l[c]++;
		r[c]--;
		now-=(r[c]==0);
		ans=max(ans, now);
	}
	printf("%d\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:7:8: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘short int *’ [-Wformat=]
  scanf("%d\n", &n);
        ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d\n", &n);
  ^