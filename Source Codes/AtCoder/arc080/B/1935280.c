#include <stdio.h>

int main(void)
{
	int h,w,n,i,j,h1,w1;
	scanf("%d %d",&h,&w);
	scanf("%d",&n);
	int a[h][w],b[n];
	for(i=0;i<n;i++)
	  scanf("%d",&b[i]);
	
	h1=w1=0;
	for(i=0;i<n;i++)
	{
		while(b[i])
		{
			a[h1][w1]=i+1;
			if(w1==(w-1))
			{
				h1++;
				w1=0;
			}
			else
			  w1++;
			b[i]--;
		}
	}
	
	for(i=0;i<h;i++)
	  {
	    if(i%2==0)
	      for(j=0;j<w;j++)
	        printf("%d ",a[i][j]);
		else
		  for(j=w-1;j>=0;j--)
		    printf("%d ",a[i][j]);
		printf("\n");
	     
      }
      
    return 0;  	
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&h,&w);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:10:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&b[i]);
    ^