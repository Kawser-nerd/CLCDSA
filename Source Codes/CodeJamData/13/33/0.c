#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int a[1000000][4];
int d[1<<22][2];
int n,m;
int x[1<<21];
int px;

int cmp(const void *a,const void *b) {
	return *(int *)a-*(int *)b;
}

int unique(int x[],int n) {
	int i,j;
	if (!n) return 0;
	qsort(x,n,sizeof(x[0]),cmp);
	for(i=j=1;i<n;i++) {
		if (x[i]!=x[j-1]) x[j++]=x[i];
	}
	return j;
}

int bf(int x[],int n,int val) {
	int l=0,r=n;
	while(l<r) {
		if (x[(l+r)/2]<val) l=(l+r)/2+1; else r=(l+r)/2;
	}
	return l;
}

int query(int t,int l,int r,int a,int b) {
//	fprintf(stderr,"Q %d %d %d %d %d %d %d\n",t,l,r,a,b,d[t][0],d[t][1]);
	if (l==a && r==b) return d[t][0];
	if (d[t][1]>0) {
		if (d[t][1]>d[t<<1][1]) {
			d[t<<1][1]=d[t][1];
			if (d[t][1]>d[t<<1][0]) d[t<<1][0]=d[t][1];
		}
		if (d[t][1]>d[t<<1|1][1]) {
			d[t<<1|1][1]=d[t][1];
			if (d[t][1]>d[t<<1|1][0]) d[t<<1|1][0]=d[t][1];
		}
		d[t][1]=0;
	}
	if (b<=(l+r)/2) return query(t<<1,l,(l+r)/2,a,b);
	if (a>=(l+r)/2) return query(t<<1|1,(l+r)/2,r,a,b);
	int t1=query(t<<1,l,(l+r)/2,a,(l+r)/2);
	int t2=query(t<<1|1,(l+r)/2,r,(l+r)/2,b);
	if (t1<t2) return t1; else return t2;
}

void update(int t,int l,int r,int a,int b,int val) {
//	fprintf(stderr,"U %d %d %d %d %d %d %d %d\n",t,l,r,a,b,val,d[t][0],d[t][1]);
	if (l==a && r==b) {
		if (d[t][1]<val) d[t][1]=val;
		if (val>d[t][0]) d[t][0]=val;
		return ;
	}
	if (d[t][1]>0) {
		if (d[t][1]>d[t<<1][1]) {
			d[t<<1][1]=d[t][1];
			if (d[t][1]>d[t<<1][0]) d[t<<1][0]=d[t][1];
		}
		if (d[t<<1|1][1]<d[t][1]) {
			d[t<<1|1][1]=d[t][1];
			if (d[t<<1|1][0]<d[t][1]) d[t<<1|1][0]=d[t][1];
		}
		d[t][1]=0;
	}
	if (b<=(l+r)/2) update(t<<1,l,(l+r)/2,a,b,val);
	else if (a>=(l+r)/2) update(t<<1|1,(l+r)/2,r,a,b,val);
	else {
		update(t<<1,l,(l+r)/2,a,(l+r)/2,val);
		update(t<<1|1,(l+r)/2,r,(l+r)/2,b,val);
	}
	if (d[t<<1][0]<d[t<<1|1][0]) d[t][0]=d[t<<1][0]; else d[t][0]=d[t<<1|1][0];
}

int main() {
	int N,cs=0,i,j,ret;
	for(scanf("%d",&N);N--;) {
		for(n=0,scanf("%d",&m);m--;) {
			int d,n1,w,e,s,dd,dp,ds;
			scanf("%d %d %d %d %d %d %d %d",&d,&n1,&w,&e,&s,&dd,&dp,&ds);
			for(i=0;i<n1;i++) {
				a[n][0]=d+dd*i;
				a[n][1]=w+dp*i;
				a[n][2]=e+dp*i;
				a[n][3]=s+ds*i;
				x[n*2]=a[n][1];
				x[n*2+1]=a[n][2];
				n++;
			}
		}
		memset(d,0,sizeof(d));
		px=unique(x,n*2);
		qsort(a,n,sizeof(a[0]),cmp);
		for(ret=i=j=0;i<n;i=j) {
			for(;j<n && a[j][0]==a[i][0];j++) {
				a[j][1]=bf(x,px,a[j][1]);
				a[j][2]=bf(x,px,a[j][2]);
				int mn=query(1,0,px,a[j][1],a[j][2]);
				if (mn<a[j][3]) ret++;
//				fprintf(stderr,"%d %d %d %d %d %d\n",a[j][0],x[a[j][1]],x[a[j][2]],a[j][3],mn,ret);
			}
			for(j=i;j<n && a[j][0]==a[i][0];j++) {
				update(1,0,px,a[j][1],a[j][2],a[j][3]);
			}
		}
		printf("Case #%d: %d\n",++cs,ret);
	}
	return 0;
}
