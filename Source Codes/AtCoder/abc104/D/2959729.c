#include<stdio.h>
#include<string.h>
int main(){
  char s[100010];
  int n;
  long long int ans=0,cnt[4]={},th[100010],l,r;
  scanf("%s",s);
  n=strlen(s);
  th[0]=1;
  for(int i=1;i<n;i++)
    th[i]=th[i-1]*3%1000000007;
  for(int i=0;i<n;i++){
    if(i>1&&s[i]=='?')
      cnt[3]++;
    else if(i>1&&s[i]=='C')
      cnt[2]++;
    else if(i==0&&s[i]=='A')
      cnt[0]++;
    else if(i==0&&s[i]=='?')
      cnt[1]++;
  }
  l=cnt[0]*th[cnt[1]]%1000000007;
  if(cnt[1])
    l+=cnt[1]*th[cnt[1]-1]%1000000007;
  l%=1000000007;
  r=cnt[2]*th[cnt[3]]%1000000007;
  if(cnt[3])
    r+=cnt[3]*th[cnt[3]-1]%1000000007;
  r%=1000000007;
  if(s[1]=='B'||s[1]=='?')
    ans+=l*r%1000000007;
  for(int i=2;i<n-1;i++){
    if(s[i]=='?')
      cnt[3]--;
    else if(s[i]=='C')
      cnt[2]--;
    if(s[i-1]=='A')
      cnt[0]++;
    else if(s[i-1]=='?')
      cnt[1]++;
    if(s[i]=='B'||s[i]=='?'){
      l=cnt[0]*th[cnt[1]]%1000000007;
      if(cnt[1])
        l+=cnt[1]*th[cnt[1]-1]%1000000007;
      r=cnt[2]*th[cnt[3]]%1000000007;
      if(cnt[3])
        r+=cnt[3]*th[cnt[3]-1]%1000000007;
      ans+=l*r%1000000007;
      ans%=1000000007;
    }
  }
  printf("%lld\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^