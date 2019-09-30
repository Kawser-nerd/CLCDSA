#include<stdio.h>
int main(){
  int T,n,t,i,strt,l,tstrt;
  char ic[30];
  long long int ans;
  char str[1000008];

  for(i='a';i<='z';i++)
    ic[i-'a'] = 1;

  ic[-'a' + 'a'] = 0;
  ic[-'a' + 'e'] = 0;
  ic[-'a' + 'i'] = 0;
  ic[-'a' + 'o'] = 0;
  ic[-'a' + 'u'] = 0;

  scanf("%d",&T);
  for(t=1;t<=T;t++){
    scanf("%s",str);
    scanf("%d",&n);
    ans = 0;
    l = 0;
    strt = -1;
    for(i=0;str[i]!='\0';i++){
        if(ic[str[i] - 'a']){
          if(l == 0){
            tstrt = i;
          }
          l++;
          if(l == n)
            strt = tstrt;
        } else {
          if(l > n)
            strt = strt + (l - n);
          l = 0;
        }

        if(l >= n){
          ans += (long long int) strt + (l - n) + 1;
        } else
          ans += (long long int) strt + 1;
    }
    printf("Case #%d: %lld\n",t,ans);
  }
  return 0;
}
