#include<stdio.h>

long long mylcm(long long a, long long b){
  if(a==0||b==0) return 0;
  long long r, tmp;
  if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }
 
  r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
 
  return b;
}


int main(){
  int t;
  scanf("%d", &t);

  int i, flag = 0;
  long long a,b, c, d, memo, tmp, tmp2;
  for(i=0; i<t; i++){
    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
    if(d<b || a<b) flag = 1;
    else if(b<c);
    else{
      memo = a%b;
      tmp = mylcm(d%b, b);
      if(tmp==0){
	if(memo>c) flag = 1;
      }
      else if(tmp==1){
	if(c<b-1) flag=1;
      }
      else{
	if(b-c>tmp) flag = 1;
	else{
	  memo = a%tmp;
	  tmp2 = b - tmp + memo;
	  if(c<tmp2) flag = 1;
	}
      }
    }
    if(flag==1) printf("No\n");
    else printf("Yes\n");
    flag = 0;
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &t);
   ^
./Main.c:30:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
     ^