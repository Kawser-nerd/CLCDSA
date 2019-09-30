#include <stdio.h>

int MAXN=300;

int qsort(int a[], double b[], int h, int t)
{
	int mida, i, j;
	double midb;
	if (h<t) {
		i=h; j=t;
		mida = a[i];
		midb = b[i];
		while (i<j) {
			while ((i<j) && (b[j]>midb)) j--;
			a[i] = a[j];
			b[i] = b[j];
			if (i<j) i++;
			while ((i<j) && (b[i]<midb)) i++;
			a[j] = a[i];
			b[j] = b[i];
			if (i<j) j--;
		}
		a[i] = mida;
		b[i] = midb;
		qsort(a, b, h, i-1);
		qsort(a, b, i+1, t);
	}
	return 0;
}

int main() 
{
	int T,i,j,n,j1;
	double S,S1;
	double a[MAXN];
	int b[MAXN];
	double ans[MAXN];
	double t;
	
	
	scanf("%d", &T);
	for (i=0; i<T; i++)
	{
		S = 0;
		scanf("%d", &n);
		for (j=0; j<n; j++) {
			scanf("%lf", &a[j]);
			S=S+a[j];
			b[j] = j;
		}
		
		qsort(b,a,0,n-1);
//		for (j=0; j<n; j++) printf("%lf ", a[j]);
//		for (j=0; j<n; j++) printf("%d ", b[j]);
//		printf("\n");

		for (j=0; j<n; j++) {
			ans[b[j]]=0;
			S1=0;
			for (j1=0; j1<j; j1++)
				S1=S1+a[j1];
			for (j1=j; j1<n; j1++) 
			{
				S1=S1+a[j1];
				if (j1==0) continue;
				t=((S+S1)/(j1+1)-a[j])/S;
				//printf("j=%d j1=%d S=%.2lf S1=%.2lf t=%.2lf\n", j,j1,S,S1,t);
				if (a[j]+t*S<a[j1]) continue;
				if ((j1<n-1) && (a[j]+t*S>a[j1+1])) continue;
				if (t>ans[b[j]]) ans[b[j]]=t*100;
			}
		}
		
		printf("Case #%d:", i+1);		
		for (j=0; j<n; j++)
			printf(" %.5lf",ans[j]);
		printf("\n");
	}
	return 0;
}