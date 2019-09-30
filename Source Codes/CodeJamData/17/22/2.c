#include<stdio.h>

void addC(char c1,int *d,char c2) {
	int i;
	printf("%c",c1);
	for(i=0;i<*d;i++) printf("%c%c",c2,c1);
	*d=0;
} 

int main() {
	int N,cs=0,n,r,y,b,o,v,g,a[3],d[3],i,j,k;
	char s1[]="RBY";
	char s2[]="GOV";
	for(scanf("%d",&N);N--;puts("")) {
		scanf("%d",&n);
		scanf("%d %d %d %d %d %d",&r,&o,&y,&g,&b,&v);
		printf("Case #%d: ",++cs);
		if (o>0) {
			if (o==b && n==b+b) {
				for(i=0;i<b;i++) printf("OB");
				continue;
			}
			if (b<=o) {
				printf("IMPOSSIBLE");
				continue;
			}
		}
		a[1]=b-o,d[1]=o;
		if (g>0) {
			if (g==r && n==r+r) {
				for(i=0;i<r;i++) printf("GR");
				continue;
			}
			if (r<=g) {
				printf("IMPOSSIBLE");
				continue;
			}
		}
		a[0]=r-g,d[0]=g;
		if (v>0) {
			if (v==y && n==y+y) {
				for(i=0;i<y;i++) printf("VY");
				continue;
			}
			if (v<=y) {
				printf("IMPOSSIBLE");
				continue;
			}
		}
		a[2]=y-v,d[2]=v;
		if (a[0]>a[1]+a[2] || a[1]>a[0]+a[2] || a[2]>a[0]+a[1]) {
			printf("IMPOSSIBLE");
			continue;
		}
		for(i=2;i>=0;i--) if (a[i]>0) {
			j=i;
			break;
		}
		for(;a[0]>0 || a[1]>0 || a[2]>0;) {
			for(i=0,k=-1;i<3;i++) if (i!=j && a[i]>0) {
				if (k<0 || a[i]>a[k]) k=i;
			}
			j=k;
			addC(s1[k],&d[k],s2[k]);
			a[k]--;
		}
	}
	return 0;
}