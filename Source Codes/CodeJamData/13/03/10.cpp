#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define each(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define snuke srand((unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 100005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

char in[105];
int a[105], ai, b[105], bi, c[105], d[55];

int cmb(int x, int y){
	if(x<y) return 0;
	int res = 1;
	rep(i,y) res *= x-i;
	rrep(i,y) res /= i;
	return res;
}

bool cmp(int x[105], int y[105], int n){
	rep(i,n){
		if(x[i]>y[i]) return false;
		if(x[i]<y[i]) return true;
	}
	return true;
}

int f(int x[105], int n){
	int res = 0;
	if(n>1||x[0]>3) res = 3; else res = x[0];
	if(n <= 1) return res;
	
	for(int i = 2; i < n; i++){
		if(i&1){
			res += 5;
			res += cmb(i/2-1,1)*3;
			res += cmb(i/2-1,2)*2;
			res += cmb(i/2-1,3)*2;
		} else {
			res += 2;
			rrep(j,3) res += cmb(i/2-1,j);
		}
	}
	
	int m = n/2;
	rep(i,n) c[i] = 0;
	c[0] = c[n-1] = 2;
	if(cmp(c,x,n)) res++;
	if(n&1){
		c[m] = 1;
		if(cmp(c,x,n)) res++;
	}
	
	rep(i,n) c[i] = 2;
	c[0] = c[n-1] = 1;
	int s = 1, mul;
	rrep(i,m-1){
		c[i] = c[n-1-i] = 0;
		if(cmp(c,x,n)){
			rep(j,5-s){
				if(n&1) mul = (j+s<=2?3:2); else mul = 1;
				res += cmb(m-i-1,j)*mul;
			}
			
			c[i] = c[n-1-i] = 1; s++;
			if(cmp(c,x,n)){
				rep(j,5-s){
					if(n&1) mul = (j+s<=2?3:2); else mul = 1;
					res += cmb(m-i-1,j)*mul;
				}
				s = 5;
			}
		}
		if(s >= 5) break;
	}
	
	if(s < 5 && (n&1)){
		rep(i,3){
			c[m] = i;
			if(cmp(c,x,n)) res++;
		}
	}
	if(n == 2) if(cmp(c,x,n)) res++;
	
	return res;
}


bool cmp2(int x[105], int n){
	rep(i,102) c[i] = 0;
	rep(i,51)rep(j,51){
		c[100-i-j] += d[i]*d[j];
	}
	int m = 0;
	rep(i,102){
		c[i+1] += c[i]/10;
		c[i] %= 10;
		if(c[i]) m = i+1;
	}
	
	if(m < n) return true;
	if(m > n) return false;
	rep(i,n){
		if(c[n-1-i]>x[i]) return false;
		if(c[n-1-i]<x[i]) return true;
	}
	return true;
}

int calc(int x[105], int n){
	if(n == 0) return 0;
	
	rep(i,51) d[i] = 0;
	rep(i,51){
		rrep(j,9){
			d[i] = j;
			if(!cmp2(x,n)){ d[i]--; break;}
		}
	}
	int m = 51;
	
	while(d[0]==0){
		m--;
		rep(j,m) d[j] = d[j+1];
	}
	//rep(i,m) printf("%d",d[i]); printf(" %d\n",m);
	
	return f(d,m);
}


int main(){
	/*
	scanf("%s",in); for(int i = 0; in[i] != '\0'; i++) a[ai++] = in[i]-'0';
	rep(i,ai) printf("%d",a[i]); printf(" %d\n",ai);
	cout << calc(a,ai) << endl;//*/
	
	//*
	int t;
	scanf("%d",&t);
	
	rrep(ti,t){
		ai = bi = 0;
		scanf("%s",in); for(int i = 0; in[i] != '\0'; i++) a[ai++] = in[i]-'0';
		scanf("%s",in); for(int i = 0; in[i] != '\0'; i++) b[bi++] = in[i]-'0';
		for(int i = ai-1; i >= 0; i--){
			if(a[i]==0) a[i] = 9; else {
				a[i]--;
				if(i == 0 && a[i] == 0){
					ai--;
					rep(j,ai) a[j] = a[j+1];
				}
				break;
			}
		}
		printf("Case #%d: %d\n",ti,calc(b,bi)-calc(a,ai));
	}
	//*/
	return 0;
}





