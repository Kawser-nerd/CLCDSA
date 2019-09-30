#include <stdio.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <assert.h> 
#include <map> 
#include <vector> 
#include <string> 
#include <algorithm> 
using namespace std; 

typedef long long ll; 

#define modp(x) (((x)%P+P)%P) 
#define mod(x,y) (((x)%(y)+(y))%(y)) 

vector<int> c[3000];
int h[3000];

void saiki(int p,int nowh,int nowsl){
  h[p]=nowh;
  for(int i=0;i<c[p].size();i++){
    saiki(c[p][i],nowh-(nowsl+i)*(p-c[p][i]),nowsl+i);
  }
}

main(){
  int testcases;
  scanf("%d",&testcases);
  for(int casenum=1;casenum<=testcases;casenum++){
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)c[i].clear();
    int v[3000];
    for(int i=0;i<n-1;i++){
      scanf("%d",&v[i]);v[i]--;
      c[v[i]].push_back(i);
    }
    
    bool ok=true;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	if(i<j && j<v[i] && v[i]<v[j])ok=false;
      }
    }
    if(ok){
      for(int i=0;i<n;i++){
	sort(c[i].begin(),c[i].end());
      }
      saiki(n-1,1000000000,0);
      printf("Case #%d:",casenum);
      for(int i=0;i<n;i++)printf(" %d",h[i]);
      puts("");
    }else{
      printf("Case #%d: Impossible\n",casenum);
    }
  }
}
