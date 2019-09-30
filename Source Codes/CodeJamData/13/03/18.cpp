#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define SZ(c) ((int)(c).size())

typedef long long LL;

void toarray(int *a, int &n, LL t) {
	n=0;
	while(t>0) {a[n++] = t%10;t/=10;}
	reverse(a, a+n);
}
bool ispalindrome(int *a, int n) {
	for(int i=0,j=n-1;i<j;i++,j--) if(a[i]!=a[j]) return false;
	return true;
}

int cs;
vector<string> ra, rb;


int b[125], mb, m, c[125], d[125], md, e[125], me;
const int MOD = 10000, DIGIT = 4, ten[4]={1,10,100,1000};
void copy_self_odd(int *a, int n) {
	m=n;
	for(int j=0;j<n;j++) b[j]=a[j];
	for(int j=n-2;j>=0;j--) b[m++] = a[j];
	mb=m;

	md=0;
	for(int j=0;j<m;j++) d[j]=0;
	//for(int j=m-1;j>=0;j-=DIGIT,++md) for(int k=0;k<DIGIT&&j-k>=0;k++) d[md] = d[md]*10+b[j-k];
	for(int j=m-1;j>=0;j-=DIGIT,++md) for(int k=0;k<DIGIT&&j-k>=0;k++) d[md] = d[md]+b[j-k]*ten[k];
	me=md*2;
	for(int j=0;j<me;j++) e[j]=0;
	for(int i=0;i<md;i++) for(int j=0;j<md;j++) e[i+j] += d[i]*d[j];
	for(int j=0;j<me;j++) if(e[j]>=MOD) { e[j+1]+=e[j]/MOD; e[j]%=MOD; }
	while(e[me-1]==0) --me;
	m=0;
	while(e[me-1]) { c[m++] = e[me-1]%10; e[me-1]/=10; }
	reverse(c,c+m);
	for(int i=me-2;i>=0;i--) for(int j=DIGIT-1;j>=0;j--) c[m++]=e[i]/ten[j]%10;
}
const int CHECK = 26; //TODO: 26
void copy_self_even(int *a, int n) {
	m=n;
	for(int j=0;j<n;j++) b[j]=a[j];
	for(int j=n-1;j>=0;j--) b[m++] = a[j];
	mb=m;

	md=0;
	for(int j=0;j<m;j++) d[j]=0;
	//for(int j=m-1;j>=0;j-=DIGIT,++md) for(int k=0;k<DIGIT&&j-k>=0;k++) d[md] = d[md]*10+b[j-k];
	for(int j=m-1;j>=0;j-=DIGIT,++md) for(int k=0;k<DIGIT&&j-k>=0;k++) d[md] = d[md]+b[j-k]*ten[k];
	//printf("b>>>>> "); for(int j=m-1;j>=0;j--) printf("%d ", b[j]); puts("");
	//printf("d>>>>> "); for(int j=md-1;j>=0;j--) printf("%d ", d[j]); puts("");

	me=md*2;
	for(int j=0;j<me;j++) e[j]=0;
	for(int i=0;i<md;i++) for(int j=0;j<md;j++) e[i+j] += d[i]*d[j];
	for(int j=0;j<me;j++) if(e[j]>=MOD) { e[j+1]+=e[j]/MOD; e[j]%=MOD; }
	while(e[me-1]==0) --me;
	m=0;
	while(e[me-1]) { c[m++] = e[me-1]%10; e[me-1]/=10; }
	reverse(c,c+m);
	for(int i=me-2;i>=0;i--) for(int j=DIGIT-1;j>=0;j--) c[m++]=e[i]/ten[j]%10;


	
/*
	for(int j=0;j<2*m;j++) c[j]=0;
	for(int i=0;i<m;i++) for(int j=0;j<m;j++) c[i+j] += b[i]*b[j];
	for(int j=0;j<2*m;j++) if(c[j]>=10) { c[j+1]+=c[j]/10; c[j]%=10; }
	mb = m;
	m=2*m; while(c[m-1]==0) --m;*/
}

void check() {
	if(ispalindrome(c, m)) {
		string w="";
		for(int i=0;i<m;i++) w+=(char)(c[i]+'0');
		rb.push_back(w);
		
		//w="";
		//for(int i=0;i<mb;i++) w+=(char)(b[i]+'0');
		//ra.push_back(w);
		//printf("found %s\n", w.c_str());
		//fprintf(stderr, "found %s\n", w.c_str());
	}
}
void go(int n, int *a, int twos=0, int cursum=0) {
	if(cursum*2 >= 10) return;
	if(n==CHECK) return;
	if(n==0) {
		for(a[0]=1;a[0]<=3;a[0]++) {
			copy_self_odd(a,1); check();
			copy_self_even(a,1); check();
			if(a[0]<3) go(1,a,twos+(a[0]==2));
		}
		return;
	}
	for(a[n]=0;a[n]<=2-twos;a[n]++) {
		copy_self_odd(a,n+1); check();
		copy_self_even(a,n+1); check();
		go(n+1,a,twos+(a[n]==2),cursum + (a[n]*a[n]));
	}
}

const int CONSIZE = 105;
void solve() {
	string A, B;
	char AA[200], BB[200];
	scanf("%s%s", AA, BB);
	A = string(AA);
	B = string(BB);
	while(SZ(A) <= CONSIZE) A = string("0") + A;
	while(SZ(B) <= CONSIZE) B = string("0") + B;
	vector<string>::iterator ita, itb;
	int na=SZ(rb), nb=SZ(rb);
	ita = lower_bound(rb.begin(), rb.end(), A);
	itb = upper_bound(rb.begin(), rb.end(), B);
	if(ita != rb.end()) na = ita-rb.begin();
	if(itb != rb.end()) nb = itb-rb.begin();
	printf("Case #%d: %d\n", cs, nb-na);
	fprintf(stderr, "Case #%d: %d\n", cs, nb-na);
}

void pre() {
	int a[500];
	go(0, a);

	//FOR(it, rb) printf("%s\n", it->c_str());
	
	//printf("total = %d\n", SZ(rb));
	for(int i=0;i<SZ(rb);i++) {
		while(SZ(rb[i]) <= CONSIZE) rb[i] += '0';
		reverse(rb[i].begin(), rb[i].end());
	}
	sort(rb.begin(), rb.end());
}

int main(void) {
	int T;
	pre();
	fprintf(stderr, "pre done! %d\n", SZ(rb));
	scanf("%d", &T);
	for(cs=1;cs<=T;cs++) {
		//printf("Case #%d: ", cs);
		solve();
	}
	return 0;
}

