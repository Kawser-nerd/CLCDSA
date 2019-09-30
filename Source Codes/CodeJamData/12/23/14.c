// C题，给出一个集合（长度<=500)，问是否能够找到两个不同的子集，使它两子集的元素和相等。Special Judge

#include <stdio.h>

#include <stdlib.h>
#include <string.h>

long long merge(long long a[], long long alen, long long b[], long long blen, long long des[])
{
	long long ai,bi=0,c=0;
	
	for(ai=0;ai<alen;ai++)
	{
		for(;bi<blen;bi++)
		{
			if(b[bi]>=a[ai])break;
			des[c++]=b[bi];
		}
		des[c++]=a[ai];
	}
	for(;bi<blen;bi++)
		des[c++]=b[bi];
	
	return c;
}

void mergepart(long long a[], long long len, long long t[])
{
	if(len==1)return;
	mergepart(t,len/2,a);
	mergepart(t+len/2,(len+1)/2,a+len/2);
	merge(t,len/2,t+len/2,(len+1)/2,a);
}

void mergesort(long long a[], long long len)
{
	long long *t;
	t=(long long*)malloc(len*sizeof(long long));
	memcpy(t,a,len*sizeof(long long));
	mergepart(a,len,t);
	free(t);
}

long long f[1100000];
int fp[1100000];

int cmp(const int* a, const int* b)
{
	if(f[*a]-f[*b]>0)return 1;
	if(f[*a]-f[*b]<0)return -1;
	return 0;
}

int main()
{
	int ac, a[501], i, j, k, p, t;
	int testc, testi;
	
	freopen("gcj2_3.in", "r", stdin);
	freopen("gcj2_3.out", "w", stdout);
	
	scanf("%d", &testc);
	for(testi=1; testi<=testc; testi++)
	{
		scanf("%d", &ac);
		for(i=0;i<ac;i++)
			scanf("%d", a+i);
		
		f[0] = 0;
		t = 1;
		for(i=0; i<ac; i++) {
			for(j=0; j<t; j++)
				f[j|t] = f[j]+a[i];
			t = t<<1;
		}
		
		for(i=0; i<t; i++) {
			fp[i] = i;
		}
		qsort(fp, t, sizeof(int), cmp);
		for(i=1; i<t; i++) {
			if(f[fp[i]]==f[fp[i-1]]) break;
		}
		
		printf("Case #%d:\n", testi);
		if(i==t) printf("Impossible");
		else {
			p = fp[i-1];
			k = 0;
			for(j=0; p; j++,p/=2) {
				if(p%2 == 0) continue;
				if(!k) k++;
				else printf(" ");
				printf("%d", a[j]);
			}
			printf("\n");
			p = fp[i];
			k = 0;
			for(j=0; p; j++,p/=2) {
				if(p%2 == 0) continue;
				if(!k) k++;
				else printf(" ");
				printf("%d", a[j]);
			}
		}
		printf("\n");
	}
	
	return 0;
}
