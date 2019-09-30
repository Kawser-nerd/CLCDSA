#include <stdio.h>
#include <string.h>

#define MAX 5000
#define MAX2 12000000
int dp[11][MAX2];

char taken[MAX];

int btr(int base,int num) {
   if(num==1) dp[base][num]=1;
   return 0;
}

int dfs(int base,int num) {
   int sum=0,d;
next:
   sum=0;
   while(num) d=num%base,num/=base,sum+=d*d;
   if(sum==1) return 1;
   if(num>=MAX && sum<MAX) return dp[base][sum];
   if(taken[sum]) return 0;
   taken[sum]=1;
   num=sum;
   goto next;
}

char s[1000];

int main() {
   int base,i,ans;
   int caseno=1,cases;
   int bases[10],bn;
   memset(dp,0,sizeof(dp));
   for(base=2;base<11;base++) {
//      if(base==4) continue;
//   for(base=7;base<8;base++) {
      for(i=2;i<MAX2;i++) {
         memset(taken,0,MAX);
         dp[base][i]=dfs(base,i);
//         if(dp[base][i]==1) printf("base %d happy: %d\n",base,i);
      }
   }
   gets(s);
   sscanf(s,"%d",&cases);
   while(cases--) {
      gets(s);
      bn=0;
      for(i=0;s[i];i++) if(s[i]>='2' && s[i]<='9' /*&& s[i]!=4 && s[i]!=2*/) bases[bn++]=s[i]-'0';
      else if(s[i]=='1') bases[bn++]=10;i++;
      for(ans=2;ans<MAX2;ans++) {
         for(i=0;i<bn;i++) if(!dp[bases[i]][ans]) goto neste;
         break;
      neste:;
      }
      printf("Case #%d: %d\n",caseno++,ans);
   }
   return 0;
}
