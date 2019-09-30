#include<stdio.h>
#include<string.h>

struct v_t
{
	int d,l;
};

int n,d;
struct v_t vines[10010];
int h[10010];

int main()
{
	int t,tt,i;
	int j,ret;

	scanf("%d",&t);
	for (tt=1;tt<=t;tt++)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++) { scanf("%d %d",&vines[i].d,&vines[i].l); }
		scanf("%d",&d);
		memset(h,0,sizeof(h));
		ret=0;

		h[0]=vines[0].d;

		for (i=0;i<n;i++)
		{
			//printf("(d:%d,l:%d): h=%d\n",vines[i].d,vines[i].l,h[i]);
			if (vines[i].d+h[i]>=d) { ret=1; break; }
			for (j=i+1;j<n;j++)
			{
				if (vines[i].d+h[i]>=vines[j].d)
				{
					if (vines[j].d-vines[i].d>h[j]) { h[j]=vines[j].d-vines[i].d; }
					if (h[j]>vines[j].l) { h[j]=vines[j].l; }
				}
				else { break; }
			}
		}

		printf("Case #%d: %s\n",tt,ret?"YES":"NO");
	}

	return 0;
}

