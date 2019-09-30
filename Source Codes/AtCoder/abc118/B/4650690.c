#include<stdio.h>

struct tag_suki{
  int food[30];
};

int main()
{
  int n,m;
  int k[30];
  struct tag_suki a[30];
  int i,j;
  int cnt = 0;

  scanf("%d %d",&n,&m);

    for(i=0;i<n;i++){
    scanf("%d",&k[i]);
    for(j=0;j<k[i];j++){
        scanf("%d",&(a[i].food[j]));
    }
  }

  int c[m]; //kobetu
  for(i=0;i<m;i++){
    c[i]=0;
  }

  for(i=0;i<n;i++){
    for(j=0;j<k[i];j++){
      c[a[i].food[j]-1] += 1;
    }
  }

  for(i=0;i<m;i++){
    if(c[i]==n) cnt++;
  }

  printf("%d",cnt);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&k[i]);
     ^
./Main.c:20:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&(a[i].food[j]));
         ^