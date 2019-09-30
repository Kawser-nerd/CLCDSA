#include<stdio.h>

char s[100001],t[100001];
long sn[100000][2],tn[100000][2];

int main(int argc, char const *argv[]){
	long q,i,a,b,c,d,an,bn,cn;
	scanf("%s",s);
	scanf("%s",t);
	scanf("%ld",&q);
	if(s[0]=='A') sn[0][0]=1;
	else sn[0][1]=1;
	if(t[0]=='A') tn[0][0]=1;
	else tn[0][1]=1;
	for(i=1;s[i]!='\0';i++){
		sn[i][0]=sn[i-1][0];
		sn[i][1]=sn[i-1][1];
		if(s[i]=='A') sn[i][0]++;
		else sn[i][1]++;
	}
	for(i=1;t[i]!='\0';i++){
		tn[i][0]=tn[i-1][0];
		tn[i][1]=tn[i-1][1];
		if(t[i]=='A') tn[i][0]++;
		else tn[i][1]++;
	}
	for(i=0;i<q;i++){
		scanf("%ld %ld %ld %ld",&a,&b,&c,&d);
		a-=2;
		b--;
		c-=2;
		d--;
		an=sn[b][0]-((a<0)?0:sn[a][0])+300000;
		bn=sn[b][1]-((a<0)?0:sn[a][1]);
		cn=(an-bn)%3;
		an=tn[d][0]-((c<0)?0:tn[c][0])+300000;
		bn=tn[d][1]-((c<0)?0:tn[c][1]);
		if(cn==(an-bn)%3) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",t);
  ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld",&q);
  ^
./Main.c:28:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld %ld %ld",&a,&b,&c,&d);
   ^