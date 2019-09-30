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
  int n[3][3]={{0,0,0},{0,0,0},{0,0,0}},flag=0;
  int minx[3]={200,200,200};
  int miny[3]={200,200,200};
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      scanf("%d ",&n[i][j]);
    }
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      minx[i]=min(n[i][j],minx[i]);
    }
  }

  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      miny[i]=min(n[j][i],miny[i]);
    }
  }
  //debug
  //for(int i=0;i<3;i++)printf("%d\n",minx[i]);
  //for(int i=0;i<3;i++)printf("%d\n",miny[i]);
for(int a=0;a<=minx[0];a++){
  for(int b=0;b<=minx[1];b++){
    for(int c=0;c<=minx[2];c++){
      for(int d=0;d<=miny[0];d++){
        for(int e=0;e<=miny[1];e++){
          for(int f=0;f<=miny[2];f++){
            if(n[0][0]==a+d && n[0][1]==a+e && n[0][2]==a+f && n[1][0]==b+d && n[1][1]==b+e && n[1][2]==b+f && n[2][0]==c+d && n[2][1]==c+e && n[2][2]==c+f){
              printf("Yes");
              return 0;
            }
          }
        }
      }
    }
  }
}
printf("No");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:43:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d ",&n[i][j]);
       ^