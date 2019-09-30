#include<cstdio>
using namespace std;
int main(){
  int a,b,x;
  scanf("%d %d %d",&a,&b,&x);
  if(a<=x&&a+b>=x)
    printf("YES\n");
  else
    printf("NO\n");
}