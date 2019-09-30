#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

int perm[1005];
int n=100;

int appear[1005][1005];

double score[105][105];
int main(){
	int repeat=10000000;
	REP(hoge,repeat){
		REP(i,n) perm[i]=i;

		REP(i,n){
			int a=rand()%n;
			swap(perm[a],perm[i]);
		}
		REP(i,n) appear[i][perm[i]]++;

	}
	
	REP(i,n){
		REP(j,n){
		//	printf("%3d%c",(appear[i][j]-repeat/n)*100/(repeat/n),j==n-1?'\n':' ');
			score[i][j]=(appear[i][j]-repeat/n)/(double)(repeat/n);
		}
	}
	

	int t;cin>>t;
	REP(setn,t){
		printf("Case #%d: ",setn+1);
		double sum=0;
		cin>>n;
		REP(i,n){
			int a;scanf("%d",&a);
			sum+=score[i/10][a/10];
		}
		if(sum>=7.0) puts("BAD");
		else puts("GOOD");
	}


	return 0;
}



