#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
int T;
int N,a[26];
int main(){
	cin>>T;
	rep1(tt,T){
		int N;
		cin>>N;
		rep(i,N) cin>>a[i];
		printf("Case #%d: ",tt);
		while(true){
			int c=0,mx=0,j=-1;
			rep(i,N){
				if(mx<a[i]) mx=a[i],j=i;
				if(a[i]>0) c++;
			}
			if(c==0) break;
			assert(c!=1);
			if(c==2){
				int k=0;
				rep(i,26) if(j!=i&&a[i]>0) k=i;
				if(a[j]==a[k]){
					printf("%c%c ",'A'+j,'A'+k);
					a[j]--,a[k]--;
				}else{
					printf("%c ",'A'+j);
					a[j]--;
				}
			}else{
				printf("%c ",'A'+j);
				a[j]--;
			}
		}
		puts("");
	}
}
