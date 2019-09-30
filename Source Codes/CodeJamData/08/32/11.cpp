// 3B

#include <stdio.h>
#include <string.h>
#define N 64

typedef unsigned long long LL;
char s[N];
int M2[N][N],M3[N][N],M5[N][N],M7[N][N];
LL d[N][2][3][5][7];
int L;

int gmod(int bg,int ed,int mod){
	int r=0;
	int i;
	for (i=bg;i<ed;i++)
		r=(r*10+s[i]-'0')%mod;
	return r;
}

void solve(int cas){
	int i,j,k,l,p;
	int j2,j3,j5,j7;
	int k2,k3,k5,k7;
	LL res;
	scanf("%s",s);
	L=strlen(s);
	for (i=0;i<L;i++) for (j=i+1;j<=L;j++){
		M2[i][j]=gmod(i,j,2);
		M3[i][j]=gmod(i,j,3);
		M5[i][j]=gmod(i,j,5);
		M7[i][j]=gmod(i,j,7);
	}
	memset(d,0,sizeof(d));
	d[0][0][0][0][0]=1;
	for (l=0;l<L;l++){
		for (p=l+1;p<=L;p++){
			for (j2=0;j2<2;j2++) for (j3=0;j3<3;j3++) for (j5=0;j5<5;j5++) for (j7=0;j7<7;j7++){
				k2=(j2+M2[l][p])%2;
				k3=(j3+M3[l][p])%3;
				k5=(j5+M5[l][p])%5;
				k7=(j7+M7[l][p])%7;
				d[p][k2][k3][k5][k7]+=d[l][j2][j3][j5][j7];
				if (l>0){
					k2=(j2-M2[l][p]+2)%2;
					k3=(j3-M3[l][p]+3)%3;
					k5=(j5-M5[l][p]+5)%5;
					k7=(j7-M7[l][p]+7)%7;
					d[p][k2][k3][k5][k7]+=d[l][j2][j3][j5][j7];
				}
			} 
		}
	}
	res=0;
	for (j2=0;j2<2;j2++) for (j3=0;j3<3;j3++) for (j5=0;j5<5;j5++) for (j7=0;j7<7;j7++){
		if (j2*j3*j5*j7==0) res+=d[L][j2][j3][j5][j7];
	}
	printf("Case #%d: %I64u\n",cas,res);
}

int main(){
	int t,cas;
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	scanf("%d",&t);
	for (cas=1;cas<=t;cas++)
		solve(cas);
	return 0;
}
