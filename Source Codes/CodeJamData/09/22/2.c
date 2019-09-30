#include <stdio.h>
#include <string.h>

char num[22];

inline void swap(char *a, char *b) {
	char c;
	c = *a;
	*a = *b;
	*b = c;
}

void sort(int a, int b) {
	int i,j;
	if (a>=b) return;
	for (i=a;i<=b-1;i++)
	for (j=i+1;j<=b;j++)
		if (num[i]>num[j])
			swap(&num[i], &num[j]);
}

int main() {
	int i,j,k,l,m,nl;
	int T;
	scanf("%d", &T);
	for (i=0;i<T;i++) {
		scanf("%s", num);
		nl = strlen(num);
		for (j=0;j<=21;j++) {
			if (nl-j-1>=0) num[21-j] = num[nl-j-1]-'0';
			else num[21-j] = 0;
		}

		k=21;
		while(num[k-1]>=num[k]) k--;
		k--;
		l=21;
		while(num[k]>=num[l] && l>k) l--;
		//printf("swap %d %d\n", k,l);
		swap(&num[l], &num[k]);
		sort(k+1, 21);

		printf("Case #%d: ", i+1);
		k=0;
		for (j=0;j<22;j++) {
			if (num[j]!=0 || k) {
				printf("%d", num[j]);
				k=1;
			}
		}
		printf("\n");
	}
}
