#include<stdio.h>

int main()
{
	int i=0,xi,yi,a,N;
	int wl,wr,hu,hd,W,H;
    scanf("%d %d %d",&W,&H,&N);
     wl=0,hd=0,wr=W,hu=H;
    for(i=0;i<N;i++)
    {
    	scanf("%d %d %d",&xi,&yi,&a);
    	if(a==1)
    	{
    		if(xi>=wl)
    		wl=xi;
		}
		else if(a==2)
		{
			if(xi<=wr)
			wr=xi;
		}
		else if(a==3)
		{
			if(yi>=hd)
			hd=yi;
			
		}
		else
		{
			if(yi<=hu)
			hu=yi;
		}
		
	}
	if((wl>=wr)||(hd>=hu))
	{
		printf("0");
	}
	else
	printf("%d",(hu-hd)*(wr-wl));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&W,&H,&N);
     ^
./Main.c:12:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      scanf("%d %d %d",&xi,&yi,&a);
      ^