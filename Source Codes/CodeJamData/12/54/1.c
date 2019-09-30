#include<stdio.h>
#include<string.h>

int a[42][42];
char str[1024];
int b[1024];
int n,m;
int c[42][2];
int v[42];
char t1[4],t2[4];
char na[10];
int d[42];
int e[42];

int trans(char s) {
	if (s>='a') return s-'a'; else return s-'0'+26;
}

void dfs(int k,int idx) {
	int i;
	v[k]=1;
	for(i=0;i<42;i++) if ((a[k][i] || a[i][k]) && !v[i]) dfs(i,idx);
	if (d[k]>0) c[idx][0]+=d[k]; else if (d[k]<0) c[idx][1]-=d[k];
}

int main() {
	int N,cs=0,i,j,k;
	na[0]='o',na[1]='i',na[3]='e',na[4]='a',na[5]='s',na[7]='t',na[8]='b',na[9]='g';
	for(scanf("%d",&N);N--;) {
		scanf("%d",&m);
		scanf("%s",str);
		n=strlen(str);
		memset(a,0,sizeof(a));
		for(i=0;i<n-1;i++) {
			int m1=0,m2=0;
			t1[m1++]=str[i];
			for(j=0;j<10;j++) if (na[j]==str[i]) t1[m1++]='0'+j;
			t2[m2++]=str[i+1];
			for(j=0;j<10;j++) if (na[j]==str[i+1]) t2[m2++]='0'+j;
			for(j=0;j<m1;j++) for(k=0;k<m2;k++) {
				int tt1=trans(t1[j]),tt2=trans(t2[k]);
				a[tt1][tt2]=1;
			}
		}
		memset(v,0,sizeof(v));
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		for(i=0;i<42;i++) for(j=0;j<42;j++) if (a[i][j]) d[i]++,d[j]--,e[i]=1;
		memset(c,0,sizeof(c));
		for(j=i=0;i<42;i++) if (e[i] && !v[i]) {
			dfs(i,j);
			j++;
		}
		if (j>1) {
			for(i=0;i<j;i++) if (!c[i][0]) c[i][0]=c[i][1]=1;
		}
		int mm1=0,mm2=0;
		for(i=0;i<j;i++) mm1+=c[i][0],mm2+=c[i][1];
		if (mm1<mm2) k=mm2-1; else k=mm1-1;
		if (k<0) k=0;
		for(i=0;i<42;i++) for(j=0;j<42;j++) if (a[i][j]) k++;
		printf("Case #%d: %d\n",++cs,k+1);
	}
	return 0;
}
