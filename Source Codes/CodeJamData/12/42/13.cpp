#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 
#include <assert.h> 
#include <map> 
#include <vector> 
#include <string> 
#include <algorithm> 
#include <complex>
using namespace std; 

typedef long long ll; 

#define modp(x) (((x)%P+P)%P) 
#define mod(x,y) (((x)%(y)+(y))%(y)) 

pair<double,int> r[2000];
complex<double> p[2000];

double myrand(){
  return rand()/(1.0+RAND_MAX);
}

main(){
  int testcases;
  scanf("%d",&testcases);
  for(int casenum=1;casenum<=testcases;casenum++){
    int n;
    double w,l;
    scanf("%d%lf%lf",&n,&w,&l);
    for(int i=0;i<n;i++){
      double tmp;
      scanf("%lf",&tmp);
      r[i]=make_pair(tmp,i);
    }
    sort(r,r+n);
    reverse(r,r+n);
    for(int i=0;i<n;i++){
      for(;;){
	p[r[i].second]=complex<double>(myrand()*w,myrand()*l);
	bool ok=true;
	for(int j=0;j<i;j++){
	  if(abs(p[r[i].second]-p[r[j].second])<(r[i].first+r[j].first)*1.000000001+1)ok=false;
	}
	if(ok)break;
      }
    }
    printf("Case #%d:",casenum);
    for(int i=0;i<n;i++)printf(" %.9f %.9f",p[i].real(),p[i].imag());
    puts("");
  }
}
