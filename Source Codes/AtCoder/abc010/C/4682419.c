#include<stdio.h>
#include<math.h>

int main(void)
{
  int txa,txb,tya,tyb,v,n,t,i;
  int house_x[1000];
  int house_y[1000];
  double kyori;

  scanf("%d%d%d%d%d%d",&txa,&tya,&txb,&tyb,&t,&v);
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d%d",&house_x[i],&house_y[i]);
    }

  for(i=0;i<n;i++)
    {
      kyori=sqrt((txa-house_x[i])*(txa-house_x[i])
		 +(tya-house_y[i])*(tya-house_y[i]))
	+sqrt((txb-house_x[i])*(txb-house_x[i])
	      +(tyb-house_y[i])*(tyb-house_y[i]));
      if(kyori<=t*v){
	printf("YES\n");
	return 0;
    }
    }
  printf("NO\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d%d%d",&txa,&tya,&txb,&tyb,&t,&v);
   ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:15:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d%d",&house_x[i],&house_y[i]);
       ^