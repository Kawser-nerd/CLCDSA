#include<stdio.h>
int main()
{
	int t,n,i,cn,z,y,k;
	double d,x[10000];
	FILE *fp,*fo;
    fp=fopen("B-small-attempt0.in","rb");
    //fp=fopen("C-large.in","rb");
    //fp=fopen("C.in","rb");
    fo=fopen("B-small-attempt.out","wb");
    //fo=fopen("C-large.out","wb");
	fscanf(fp,"%d",&t);
	for(k=1;k<=t;k++)
	{
		fscanf(fp,"%d%lf",&cn,&d);
		n=0;
		for(i=0;i<cn;i++)
		{
		    fscanf(fp,"%d",&z);
		    fscanf(fp,"%d",&y);
		    while(y--)
                x[n++]=z;
		}
		double l=0,h=10000000,mid,pre,dif;
		while(h-l>=0.00001)
		{
			mid=(h+l)/2;
//			printf("%lf %lf %lf\n",l,h,mid);
			pre=x[0]-mid;
			//if(pre<0)
			//	pre=0;
			for(i=1;i<n;i++)
			{
				dif=x[i]-pre;
				if(d<dif)
				{
					if(x[i]-(pre+d)<mid)
						pre+=d;
					else
						pre=x[i]-mid;
				}
				else if(dif<=d)
				{
					pre+=d;
					if(pre-x[i]>mid)
						break;
				}
			}
			if(i==n)
			{
				h=mid;
			}
			else
			{
				l=mid;
			}
		}
		fprintf(fo,"Case #%d: %.1lf\n",k,h);
	}
	return 0;
}
