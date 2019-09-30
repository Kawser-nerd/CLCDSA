#include <stdio.h>
#include <stdlib.h>
int cmp(const int *a, const int *b){
	return *a-*b;
}
int rp[100][100];
int irp[100][100];
char c[100][100];
int len[100];
int main(){
	int cases, p;
	scanf("%d", &cases);
	for(p=1;p<=cases;p++){
		int n;
		scanf("%d", &n);
		int i;
		for(i=0;i<n;i++){
			scanf("%c", c[i]);
			while(c[i][0]>'z' || c[i][0]<'a')
				scanf("%c", c[i]);
			rp[i][0]=1;
			char tmp;
			int head=1;
			while(1){
				scanf("%c", &tmp);
				if(tmp > 'z' || tmp < 'a')
					break;
				if(tmp == c[i][head-1])
					rp[i][head-1]++;
				else{
					c[i][head]=tmp;
					rp[i][head++]=1;
				}
			}
			len[i]=head;
		}
		int lose=0;
		for(i=0;i<n;i++){
			int j;
			for(j=0;j<i;j++){
				if(len[i] != len[j]){
					lose=1;
					goto out;
				}
				int k;
				for(k=0;k<len[i];k++)
					if(c[i][k] != c[j][k]){
						lose=1;
						goto out;
					}
			}
			for(j=0;j<len[i];j++)
				irp[j][i] = rp[i][j];
		}
		for(i=0;i<len[0];i++)
			qsort(irp[i], n, sizeof(int), cmp);

		int best=0;
		for(i=0;i<len[0];i++){
			int j;
			for(j=0;j<n;j++){
				if (j<n/2)
					best+=irp[i][n/2]-irp[i][j];
				else
					best+=irp[i][j]-irp[i][n/2];
			}
		}

out:
		printf("Case #%d: ", p);
		if (lose)
			printf("Fegla Won\n");
		else
			printf("%d\n", best);
	}
}
