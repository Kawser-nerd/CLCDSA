#include <algorithm> 
#include <iostream> 
#include <sstream> 
#include <string> 
#include <vector> 
#include <queue> 
#include <set> 
#include <map> 
#include <cstdio> 
#include <cstdlib> 
#include <cctype> 
#include <cmath> 
#include <list>
#include <cassert>
using namespace std; 

#define PB push_back 
#define MP make_pair 
#define SZ(v) ((int)(v).size()) 
#define FOR(i,a,b) for(int i=(a);i<(b);++i) 
#define REP(i,n) FOR(i,0,n) 
#define FORE(i,a,b) for(int i=(a);i<=(b);++i) 
#define REPE(i,n) FORE(i,0,n) 
#define FORSZ(i,a,v) FOR(i,a,SZ(v)) 
#define REPSZ(i,v) REP(i,SZ(v))
#define VAR(a,b) __typeof(b) a=b
#define FORIT(i,v) for(VAR(i,(v).begin());i!=(v).end();++i)
typedef long long ll; 

int total,perpack;

double choose[41][41];

int main() {
	int nrcases; scanf("%d",&nrcases);
	REPE(i,40) { choose[i][0]=choose[i][i]=1; FOR(j,1,i) choose[i][j]=choose[i-1][j-1]+choose[i-1][j]; }
	FORE(casenr,1,nrcases) {
		scanf("%d%d",&total,&perpack);
		vector<double> exp(total+1);
		exp[total]=0;
		for(int i=total-1;i>=0;--i) {
			vector<double> p(perpack+1);
			REPE(j,perpack) {
				if(i+j>total) { p[j]=0; continue; }
				if(perpack-j>i) { p[j]=0; continue; }
				p[j]=choose[total-i][j]*choose[i][perpack-j]/choose[total][perpack];
			}
			double times=1.0/(1.0-p[0]);
			exp[i]=1*times; FORE(j,1,perpack) if(p[j]!=0) exp[i]+=p[j]*times*exp[i+j];
//			printf("%d: %lf\n" ,i,exp[i]); REPSZ(j,p) if(p[j]!=0) printf("\t%d: %lf\n",j,p[j]);
		}
		
		printf("Case #%d: %.9lf\n",casenr,exp[0]);
	}
	return 0;
}
