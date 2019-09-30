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

main(){
  int testcases;
  scanf("%d",&testcases);
  for(int casenum=1;casenum<=testcases;casenum++){
    int n;
    scanf("%d",&n);
    int pos[20000],l[20000];
    for(int i=0;i<n;i++)scanf("%d%d",&pos[i],&l[i]);
    int goal;
    scanf("%d",&goal);
    int dp[20000];
    for(int i=n-1;i>=0;i--){
      dp[i]=goal-pos[i];
      for(int j=i+1;j<n;j++){
	if(dp[j]>l[j])continue;
	int tmp=min(pos[j]-pos[i],l[j]);
	if(tmp>=dp[j]){dp[i]=min(dp[i],pos[j]-pos[i]);break;}
      }
      //printf("dp %d = %d\n",i,dp[i]);
    }
    printf("Case #%d: ",casenum);
    if(dp[0]<=pos[0])puts("YES");
    else puts("NO");
  }
}
