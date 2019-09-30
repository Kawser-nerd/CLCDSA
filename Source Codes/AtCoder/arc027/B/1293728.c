#include<stdio.h>
char s[2][20];
int g(char a){return '0'<=a&&a<='9'?1:0;}
void f(char a,char b){
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;s[0][j];j++){
			if(s[i][j]==a)s[i][j]=b;
		}
	}
}
int main(){
	long long c=1,i,j;
	scanf("%*d %s %s",s[0],s[1]);
	for(i=0;i<26;i++){
		for(j=0;s[0][j];j++){
			if(s[0][j]==s[1][j])continue;
			if(g(s[0][j]))f(s[1][j],s[0][j]);
			else          f(s[0][j],s[1][j]);
		}
	}//printf("%s %s\n",s[0],s[1]);
	for(i=0;s[0][i];i++){
		if(g(s[0][i]))continue;
		c*=i?10:9;
		f(s[0][i],'0');
	}
	printf("%lld\n",c);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%*d %s %s",s[0],s[1]);
  ^