#include<stdio.h>
#include<string.h>

#define MAXN 256

int dfs(int a[MAXN][MAXN],int m1[],int m2[],int n,int k,int b[]) {
	int i;
	b[k]=1;
	for(i=0;i<n;i++) if (a[k][i]) {
		if (m2[i]<0 || !b[m2[i]] && dfs(a,m1,m2,n,m2[i],b)) {
			m1[k]=i,m2[i]=k;
			return 1;
		}
	}
	return 0;
}

int match(int a[MAXN][MAXN],int n,int m1[],int m2[]) {
	int i,b[MAXN],ret=0;
	for(i=0;i<n;i++) m1[i]=m2[i]=-1,b[i]=0;
	for(i=0;i<n;i++) if (m1[i]<0) {
		memset(b,0,sizeof(b));
		ret+=dfs(a,m1,m2,n,i,b);
	}
	return ret;
}

int a1[MAXN][MAXN],a2[MAXN][MAXN];
int m11[MAXN],m12[MAXN],m21[MAXN],m22[MAXN];
int a[MAXN][MAXN],b[MAXN][MAXN];
int ret[MAXN*3][2];
char ss[]=".x+o";

int main() {
	int N,cs=0,i,j,r,c,m,rr,ans,k,n;
	char str[4];
	for(scanf("%d",&N);N--;) {
		scanf("%d %d",&n,&m);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(i=0;i<m;i++) {
			scanf("%s %d %d",str,&r,&c);
			r--,c--;
			for(j=0;j<4;j++) if (ss[j]==str[0]) a[r][c]=j;
		}
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		for(i=0;i<n;i++) for(j=0;j<n;j++) {
			a1[i][j]=1;
			a2[i+j][i-j+n-1]=1;
		}
		for(rr=i=0;i<n;i++) for(j=0;j<n;j++) {
			if (a[i][j]&1) {
				for(k=0;k<n;k++) a1[i][k]=a1[k][j]=0;
				rr++;
			}
			if (a[i][j]&2) {
				rr++;
				for(k=0;k<n;k++) if (i+j-k>=0 && i+j-k<n) {
					a2[i+j][k+k-i-j+n-1]=0;
				}
				for(k=0;k<n;k++) if (k+j-i>=0 && k+j-i<n) {
					a2[k+k+j-i][i-j+n-1]=0;
				}
			}
			b[i][j]=a[i][j];
		}
		rr+=match(a1,n,m11,m12)+match(a2,n+n-1,m21,m22);
		for(i=0;i<n;i++) if (m11[i]>=0) b[i][m11[i]]|=1;
		for(i=0;i<n+n-1;i++) if (m21[i]>=0) {
			r=(i+m21[i]-n+1)/2,c=(i-m21[i]+n-1)/2;
			b[r][c]|=2;
		}
		for(ans=i=0;i<n;i++) for(j=0;j<n;j++) if (a[i][j]!=b[i][j]) {
			ret[ans][0]=i,ret[ans][1]=j,ans++;
		}
		printf("Case #%d: %d %d\n",++cs,rr,ans);
		for(i=0;i<ans;i++) printf("%c %d %d\n",ss[b[ret[i][0]][ret[i][1]]],ret[i][0]+1,ret[i][1]+1);
	}
	return 0;
}