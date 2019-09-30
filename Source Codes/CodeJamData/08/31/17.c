#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int i, int j) {
    int t = x[i];
    x[i] = x[j];
    x[j] = t;
}

int randint(int l, int u) {
    return rand()%(u-l+1)+l;
}

void quicksort(int *x, int l, int u) {
    int i, m;
    if (l >= u) return;
    swap(x, l, randint(l, u));
    m = l;
    for (i = l+1; i <= u; i++)
        if (x[i] > x[l])
            swap(x, ++m, i);
    swap(x, l, m);
    quicksort(x, l, m-1);
    quicksort(x, m+1, u);
}


int main()
{
	int i,j,n,k,p,l,a,b;
	long long int sum;
	int freq[2000];

	scanf("%d", &n);

	for(i=0;i<n;i++)
	{
		scanf(" %d %d %d", &p, &k, &l);

		for(j=0;j<l;j++)
			scanf(" %d", &freq[j]);

		quicksort(freq, 0, l-1);

		for(j=0,sum=0;j<l;j++)
		{
//			printf("Xing %d and %d\n", ((j/k)+1), freq[j]);
			sum += (long long int)((j/k)+1)*freq[j];
		}

		printf("Case #%d: %lld\n", i+1, sum);	
	}

	return 0;
}
