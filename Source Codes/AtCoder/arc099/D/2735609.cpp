#include <iostream>
#include <unordered_map>
using namespace std;
 
typedef unsigned long long ull;
const ull M=998244353;
const ull N=1000000007; 
const ull X=99431;
const ull Y=99487;
ull R;
ull L;
const int W=1000;
 
 
ull ModPow(ull x, ull n, ull mod) {
        ull ret = 1;
        for (; n > 0; n /= 2, x = (x * x) % mod)
            if ((n & 1) == 1) ret = (ret * x) % mod;
        return ret;
    }
 
ull has=0,vec=1;
ull has2=0,vec2=1;
 
int n;
string s;
unordered_map<ull,int> B[550];
long long ans;
inline void calc(char c, ull &u,ull &p,ull &v,ull &q){
	if(c=='+'){u+=p;v+=q;}
	else if(c=='-'){u+=M-p;v+=N-q;}
	else if(c=='>'){p=(p*X)%M;q=(q*Y)%N;}
	else {p=(p*R)%M;q=(q*L)%N;}
	if(u>=M)u-=M;
	if(v>=N)v-=N;
}
int main(){
	R=ModPow(X,M-2,M);
	L=ModPow(Y,N-2,N);
	cin>>n>>s;
    //n=250000;
    //s=string(n,'+');
	for(int i=0;i<n;i++)calc(s[i],has,vec,has2,vec2);
	for(int i=0;i<n;i++){
		if(i%W==0)continue;
		ull h=0,x=1,hh=0,y=1;
		for(int j=i;j<n;j++){
			if(j%W==0)break;
			calc(s[j],h,x,hh,y);
			if(h==has&&hh==has2)ans++;
		}
		ull nh = (has+M-h)%M;
		nh = nh * ModPow(x,M-2,M)%M;
		ull nh2 = (has2+N-hh)%N;
		nh2 = nh2 * ModPow(y,N-2,N)%N;
		B[i/W+1][nh*N+nh2]++;
	}
	for(int i=0;i<n;i+=W){
		ull h=0,x=1,hh=0,y=1;
		for(int j=i;j<n;j++){
			calc(s[j],h,x,hh,y);
			if(h==has&&hh==has2)ans++;
			auto it = B[i/W].find(h*N+hh);
			if(it!=B[i/W].end())ans+=it->second;
		}
	}
	
	cout<<ans;
 
 
}