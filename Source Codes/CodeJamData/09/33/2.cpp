#include<iostream>
#include<cmath>
using namespace std;

int opt[200][200];

int P, Q, sz;
int a[1000];

int get(int L, int R) {
	if(R < L) return 0;
	int&ret=opt[L][R];
	if(ret>-1)return ret;
	int len = a[R+1]-a[L-1]-1;
	ret = 0x7fffffff;
	for(int i=L;i<=R;++i)
		ret <?= get(L,i-1)+get(i+1,R);
	ret += len-1;
	return ret;
}

int run() {
	scanf("%d %d",&P,&Q);
	if(Q<2) {
		if(!Q) {
			cout<<"0"<<endl; return 1;
		}
		int b; cin>>b;
		cout<<P-1<<endl; return 1;
	}
	sz=0; a[sz++]=0; a[sz++]=P+1;
	for(int i=0;i<Q;++i) {
		int b; scanf("%d", &b);
		a[sz++]=b;
	}
	sort(a,a+sz);
	memset(opt,-1,sizeof(opt));
	printf("%d\n", get(1,sz-2));
}

int main() {
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	
	int test; scanf("%d",&test);
	for(int no=1;no<=test;++no) {
		printf("Case #%d: ",no);
		run();
	}
}
