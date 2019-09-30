#include<cstdio>
using namespace std;
int main(){
  int ans=0;
  char s[5];
  scanf("%s",s);
  for(int i=0;i<4;i++){
    if(s[i]=='+')
      ans++;
    else
      ans--;
  }
  printf("%d\n",ans);
}