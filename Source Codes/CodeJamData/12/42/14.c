#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

int n;
long w,l;
double r[N];
double x[N], y[N];
int idx[N];

int sort(int h, int t)
{
	int i,j,mididx;
	double midr;
	if (h<t) {
		i=h;
		j=t;
		midr=r[i];
		mididx=idx[i];
		while (i<j) {
			while ((i<j) && (r[j]<midr)) j--;
			r[i]=r[j]; idx[i]=idx[j];
			if (i<j) i++;
			while ((i<j) && (r[i]>midr)) i++;
			r[j]=r[i]; idx[j]=idx[i];
			if (i<j) j--;			
		}
		r[i]=midr;
		idx[i]=mididx;
		sort(h,i-1);
		sort(i+1,t);
	}
	return 0;
}

int input()
{
	int i;
	scanf("%d %ld %ld", &n, &w, &l);
	for (i=0; i<n; i++)
	{
		scanf("%lf", &r[i]);
		idx[i]=i;
	}
	sort(0,n-1);
	//for (i=0; i<n; i++)
	//	printf("%lf %d ", r[i], idx[i]);
	return 0;
}

int output()
{
	int i;
	double xx[N], yy[N];
	for (i=0; i<n; i++)
	{
		xx[idx[i]]=x[i];
		yy[idx[i]]=y[i];
	}
	for (i=0; i<n; i++)
		printf(" %.2lf %.2lf", xx[i], yy[i]);
	printf("\n");
	return 0;
}

int work()
{
	int i,j;
	int c,f;
	while (1) {
		f=1;
		for (i=0; i<n; i++)
		{
			c=0;
			while (c<10000) {
				x[i]=(rand()*RAND_MAX+rand())%(w+1);
				y[i]=(rand()*RAND_MAX+rand())%(l+1);
				//printf("%lf %lf\n", x[i], y[i]);
				for (j=0; j<i; j++)
					if ((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<(r[i]+r[j])*(r[i]+r[j]))
						{f=0; break;}
				if (f==1) break;
				c++;
			}
			if (f==0) break;
		}
		if (f>0) break;
	}
	return 0;
}

int main() 
{
	long T,i;
	
	srand(time(NULL));
	//printf("%ld\n",RAND_MAX);
	scanf("%d", &T);
	for (i=0; i<T; i++)
	{
		input();
		work();
		printf("Case #%d:", i+1);
		output();
	}
	return 0;
}