#include <stdio.h>
#include <algorithm>
using namespace std;

struct A {
	int d,a;
	int valid;
	bool operator<(const A& c) const { return d<c.d || (d==c.d && a<c.a); }
} ab[110],ba[110];
char b[1000];
const int BAD=100000;
int nca,ncb,na,nb,t;

int ffirst() {
	int i,mi=-1;
	for (i=0; i<na; ++i) if (ab[i].valid) { mi=i; break; }
	for (i=0; i<nb; ++i) if (ba[i].valid) break;
	if (mi==-1 && i==nb) return BAD;
	if (mi==-1) return -i-1;
	if (i==nb || ab[mi]<ba[i]) return mi;
	return -i-1;
}
int fnext(A* aa, int n, int d) {
	int i;
	for (i=0; i<n; ++i) if (aa[i].valid && aa[i].d>=d) return i;
	return BAD;
}
void simul(int a) {
	if (a<0) ++ncb;
	else ++nca;
	while (a!=BAD) {
//		printf("%c%d ",a<0?'b':'a',a<0?-a-1:a);
		if (a<0) {
			ba[-a-1].valid=0;
			a=fnext(ab,na,ba[-a-1].a+t);
		} else {
			ab[a].valid=0;
			a=fnext(ba,nb,ab[a].a+t);
			if (a!=BAD) a=-a-1;
		}
	}
//	printf("\n");
}

int main() {
	int i,j,n,h1,h2,m1,m2;
	gets(b);
	sscanf(b,"%d",&n);
	for (i=0; i<n; ++i) {
		gets(b);
		sscanf(b,"%d",&t);
		gets(b);
		sscanf(b,"%d %d",&na,&nb);
		for (j=0; j<na; ++j) {
			gets(b);
			sscanf(b,"%d:%d %d:%d",&h1,&m1,&h2,&m2);
			ab[j].d=60*h1+m1;
			ab[j].a=60*h2+m2;
			ab[j].valid=1;
		}
		for (j=0; j<nb; ++j) {
			gets(b);
			sscanf(b,"%d:%d %d:%d",&h1,&m1,&h2,&m2);
			ba[j].d=60*h1+m1;
			ba[j].a=60*h2+m2;
			ba[j].valid=1;
		}
		sort(ab,ab+na);
		sort(ba,ba+nb);
//		for (j=0; j<na; ++j) printf("%d-%d ",ab[j].d,ab[j].a);
//		printf("\n");
//		for (j=0; j<nb; ++j) printf("%d-%d ",ba[j].d,ba[j].a);
//		printf("\n");
		nca=ncb=0;
		while ((j=ffirst())!=BAD) {
			simul(j);
		}
		printf("Case #%d: %d %d\n",i+1,nca,ncb);
	}
	return 0;
}
