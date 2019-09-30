#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

int max(int a, int b){
  return a >= b ? a : b;
}
int min(int a, int b){
  return b >= a ? a : b;
}
int sei(int a){
  return a>0 ? a : 0;
}
long int power(int a,int b){
  long int count=1;
  for(int i=0;i<b;i++){
    count *= 2;
  }
  return count;
}
int factorial(int n) {
    if (n > 0) return n*factorial(n - 1);
		else return 1;
}
int compare_up_int(const void *a, const void *b){
   return *(int*)a - *(int*)b;
}
int compare_down_int(const void *a, const void *b){
   return *(int*)b - *(int*)a;
}
int euclid(int a, int b){
  if(a < b){int tmp = a;a = b;b = tmp;}
  int r = a % b;
  if(r < 0) r += b;
  while(r != 0){
    a = b;b = r;r = a % b;
    if(r < 0) r += b;
  }
  return b;
}

int main(){
  int flag=2;
  char s[100],t[100];
  scanf("%s",s);
  scanf("%s",t);
  for(int i=0;i<strlen(s);i++){
    for(int j=i+1;j<strlen(s);j++){
      if(s[i] > s[j]){
        char tmp=s[i];s[i]=s[j];s[j]=tmp;
      }
    }
  }
  for(int i=0;i<strlen(t);i++){
    for(int j=i+1;j<strlen(t);j++){
      if(t[i] < t[j]){
        char tmp=t[i];t[i]=t[j];t[j]=tmp;
      }
    }
  }
  for(int i=0;i<min(strlen(s),strlen(t));i++){
    if(s[i] < t[i]){
      flag=1;break;
    }
    if(s[i] > t[i]){
      flag=0;break;
    }
  }
  if(flag==1)printf("Yes");
  else if(flag==0)  printf("No");
  else if(flag==2){
    if(strlen(s) < strlen(t))printf("Yes");
    else printf("No");
  }
  //printf("%s\n",s);
  //printf("%s\n",t);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:47:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
./Main.c:48:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",t);
   ^