#include<stdio.h>
#include<string.h>
int main(void)
{
  int h,w;
  int a[502][502],b[502][502];
  int i,j;
  long int t=0;

  scanf("%d %d",&h,&w);
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++){
      scanf("%d",&a[i][j]);
      b[i][j] = a[i][j];
    }
  }

  for(i=1;i<h;i++){
    for(j=1;j<w;j++){
      if(a[i][j]%2==1){
        a[i][j]--;
        a[i][j+1]++;
        t++;
      }
    }
    if(a[i][j]%2==1){   //j == w
      a[i][j]--;
      a[i+1][j]++;
      t++;
    }
  }
  for(j=1;j<w;j++){    //i == h
    if(a[i][j]%2==1){
      a[i][j]--;
      a[i][j+1]++;
      t++;
    }
  }
  printf("%d\n",t);
  for(i=1;i<h;i++){
    for(j=1;j<w;j++){
      if(b[i][j]%2==1){
        b[i][j]--;
        b[i][j+1]++;
        printf("%d %d %d %d\n",i,j,i,j+1);
      }
    }
    if(b[i][j]%2==1){   //j == w
      b[i][j]--;
      b[i+1][j]++;
      printf("%d %d %d %d\n",i,j,i+1,j);
    }
  }
  for(j=1;j<w;j++){    //i == h
    if(b[i][j]%2==1){
      b[i][j]--;
      b[i][j+1]++;
      printf("%d %d %d %d\n",i,j,i,j+1);
    }
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:39:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long int’ [-Wformat=]
   printf("%d\n",t);
          ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&h,&w);
   ^
./Main.c:13:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&a[i][j]);
       ^