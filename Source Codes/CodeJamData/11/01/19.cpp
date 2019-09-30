#include <stdio.h>

int T,i,j,k,l,m,n,ans,a[200],b[200],c[200],x,y,t;
char s[10];

int sgn(int x)
{
	return (x>0)-(x<0);
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		k=l=0;
		a[0]=b[0]=0;
		for(i=0;i<n;i++)
		{
			scanf("%s%d",&s,&x);
			x--;
			if(s[0]=='O')
			{
				a[k++]=x;
				c[i]=0;
			}
			else
			{
				b[l++]=x;
				c[i]=1;
			}
		}
		x=y=0;
		ans=0;
		j=m=0;
		for(i=0;i<n;i++)
		{
			if(!c[i])
			{
				while(x!=a[j])
				{
					x+=sgn(a[j]-x);
					y+=sgn(b[m]-y);
					ans++;
				}
				y+=sgn(b[m]-y);
				ans++;
				if(j<k-1)
					j++;
			}
			else
			{
				while(y!=b[m])
				{
					x+=sgn(a[j]-x);
					y+=sgn(b[m]-y);
					ans++;
				}
				x+=sgn(a[j]-x);
				ans++;
				if(m<l-1)
					m++;
			}
		}
		printf("Case #%d: %d\n",++t,ans);
	}
	return 0;
}


