#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  int i;
  int j[8];
  int n,a,b,c;
  int a2;
  int b2;
  int c2;
  int a3;
  int b3;
  int c3;
  int l[8];
  int ans=2997;
  int ans2;
  scanf("%d %d %d %d",&n,&a,&b,&c);
  for(i=0;i<n;i++)
  {
    scanf("%d",&l[i]);
  }
  for(j[0]=0;j[0]<4;j[0]++){
    for(j[1]=0;j[1]<4;j[1]++){
      for(j[2]=0;j[2]<4;j[2]++){
        for(j[3]=0;j[3]<4;j[3]++){
          for(j[4]=0;j[4]<4;j[4]++){
            for(j[5]=0;j[5]<4;j[5]++){
              for(j[6]=0;j[6]<4;j[6]++){
                for(j[7]=0;j[7]<4;j[7]++){
                  a2=0;
                  b2=0;
                  c2=0;
                  a3=0;
                  b3=0;
                  c3=0;
                  ans2=0;
                  for(i=0;i<n;i++){
                    switch(j[i]){
                    case 0:
                      a2+=l[i];
                      a3++;
                      break;
                    case 1:
                      b2+=l[i];
                      b3++;
                      break;
                    case 2:
                      c2+=l[i];
                      c3++;
                      break;
                    case 3:
                      break;
                    }
                  }
                  if(a3!=0 && b3!=0 && c3!=0){
                    ans2=abs(a-a2)+abs(b-b2)+abs(c-c2)+10*(a3+b3+c3-3);
                    if(ans>ans2){
                      ans=ans2;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  printf("%d",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d",&n,&a,&b,&c);
   ^
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&l[i]);
     ^