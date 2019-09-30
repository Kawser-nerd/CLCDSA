#include <stdio.h>
#include <math.h>

int main(void)
{
	int h, w, a[250000], ans[1000000], n, flag=0, dir=0, h1, w1, k=0, p=0, i1, i2, c=0;
	scanf("%d%d", &h, &w);
	h1=h;
	w1=w;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			scanf("%d", &a[500*i+j]);
		}
	}
	while (c < w*h)	
	{
		if (dir==0 || dir==1)
		{
			if (dir==0 && flag==1)
			{
				ans[k]=p/500+1;
				ans[k+1]=(p+500)%500;
				ans[k+2]=ans[k];
				ans[k+3]=ans[k+1]+1;
				k+=4;
				if ((a[p]+2)%2 == 1) 
				{
					flag=0;
					a[p]++;
				}
			}
			i1=(int)pow(-1, dir);
			for (int i = 0; i < w1-1; ++i)
			{
				i2=i1*i;
				if ((flag+a[p+i2]+2)%2 == 1)
				{
					ans[k]=(p+i2)/500+1;
					ans[k+1]=(p+i2+500)%500+1;
					ans[k+2]=ans[k];
					ans[k+3]=ans[k+1]+i1;
					k+=4;
				}
				if ((a[p+i2]+2)%2 == 1) flag=(flag+3)%2;
			}
			if (dir == 0)
			{
				dir=2;
				if (h1==1) c++;
			}
			else
			{
				dir=3;
				if (h1==2) c++;
			}
			p=p+(w1-1)*i1;
			c=c+w1-1;
		} else
		{
			i1=(int)pow(-1, dir);
			if (dir==3) h1--;
			for (int i = 0; i < h1-1; ++i)
			{
				i2=i1*i*500;
				if ((flag+a[p+i2]+2)%2 == 1)
				{
					ans[k]=(p+i2)/500+1;
					ans[k+1]=(p+i2+500)%500+1;
					ans[k+2]=ans[k]+i1;
					ans[k+3]=ans[k+1];
					k+=4;
				}
				if ((a[p+i2]+2)%2 == 1)
				{
					flag=(flag+3)%2;
				}
			}
			if (dir == 2)
			{
				p+=500*(h1-1)*i1;
				c=c+h1-1;
				if (w1==1) c++;
				dir=1;
			}
			else
			{
				dir=0;
				p=p+500*(h1-1)*i1+1;
				if ((a[p-1]+2)%2 == 1)
				{
					flag=(flag+3)%2;
				}
				c=c+h1;
				if (w1==2) c++;
				h1--;
				w1-=2;
			}
		}
	}
	printf("%d\n", k/4);
	for (int i = 0; i < k/4; ++i)
	{
		printf("%d %d %d %d\n", ans[4*i], ans[4*i+1], ans[4*i+2], ans[4*i+3]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &h, &w);
  ^
./Main.c:14:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &a[500*i+j]);
    ^