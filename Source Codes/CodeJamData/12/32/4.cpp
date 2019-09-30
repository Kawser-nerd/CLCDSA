#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
pair<double,double> car[2005];
double d;
int n,a;
double carreachd;
double solve(double ac){
	double lb=carreachd,ub=1e6;
	REP(hoge,80){
		double md=(lb+ub)/2;
		double lb2=0,ub2=md;//time to use to move
		REP(hoge2,80){
			double md2=(lb2+ub2)/2;
			if(0.5*ac*md2*md2>d) ub2=md2;
			else lb2=md2;
		}
		if(0.5*lb2*lb2*ac<d-1e-8){
			lb=md;
			continue;
		}
		double begin=md-lb2;
		int failed=0;
		REP(i,n) if(begin<=car[i].fr && car[i].fr<=md){
			double height=(car[i].fr-begin)*(car[i].fr-begin)*0.5*ac;
			if(height>car[i].sc){
				failed=1;break;
			}
		}
		if(failed){
			lb=md;
			continue;
		}
		ub=md;
	}
	return ub;
}


int main(){
	int t;scanf("%d",&t);
	REP(setn,t){
		printf("Case #%d:\n",setn+1);
		scanf("%lf%d%d",&d,&n,&a);
		REP(i,n){
			scanf("%lf%lf",&car[i].fr,&car[i].sc);
		}
		REP(i,n) if(car[i].sc>=d-1e-8){
			if(i==0) carreachd=0;
			else carreachd=car[i-1].fr+(car[i].fr-car[i-1].fr)/
					(car[i].sc-car[i-1].sc)*(d-car[i-1].sc);
			break;
		}
		REP(hoge,a){
			double ac;scanf("%lf",&ac);
			printf("%.8f\n",solve(ac));
		}
	}

	return 0;
}



