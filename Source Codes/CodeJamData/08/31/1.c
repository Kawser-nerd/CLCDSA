#include<stdio.h>

long long N,P,K,L;
long long freq[2000];

void sort() {
	long long i,j,temp;

	for (i=0;i<L;i++)
		for (j=i+1;j<L;j++)
			if (freq[i]<freq[j]) {
				temp=freq[i];
				freq[i]=freq[j];
				freq[j]=temp;
			}
	return;
}

long long getMin() {
	long long sum = 0;
	long long i;
	for (i=0;i<L;i++) {
		sum += (((i/K)+1) * freq[i]);
	}
	return sum;
}

void main() {
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	long long i,j;
	long long min;

	fscanf(in,"%lld",&N);
	for (i=0;i<N;i++) {
		fscanf(in,"%lld %lld %lld", &P,&K,&L);
		for (j=0;j<L;j++)
			fscanf(in,"%lld",&freq[j]);

		sort();
		min=getMin();

	   fprintf(out,"Case #%lld: %lld\n",i+1, min);
	}
}