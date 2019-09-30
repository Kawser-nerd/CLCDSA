#include <stdio.h>

int prime[10000], plist[10000], pfactor[1001][1001];
int set[1002];

int main()
{

	int ppp,qq;
	int A, B, P;
	int i, j, p, q, k;
	int pcount,ans;
	int temp, flag=0;
	scanf("%d", &ppp);
	for (qq=0; qq<ppp; qq++){
	
	scanf("%d %d %d", &A, &B, &P);

	for (i=0; i<1001; i++) prime[i] = 1;
	for (i=0; i<1001; i++) plist[i] = 0;
	for (i=0; i<1001; i++) 
		for (j=0; j<1001; j++) 
			pfactor[i][j] = 0;

	prime[0] = prime[1] = 0;

	for (i=3; i<=1000; i++){
		for (j=2; j*j<=i; j++){
			if (i % j == 0){
				prime[i] = 0;
				break;
			}
		}
	}

	pcount=0;
	for (i=2; i<1001; i++)
		if (prime[i]) plist[pcount++] = i;

//	for (i=0; i<pcount; i++) printf("%d ", plist[i]);
	for (i=A; i<=B; i++){
		for (j=0; j<pcount; j++)
			if (i % plist[j] == 0){ pfactor[i][j] = 1;
			//	printf("%d is a factor of %d\n", plist[j], i);
				}
	}


	flag = 1;
			ans = 0;
			for (i=A; i<=B; i++) set[i] = i;
	while (flag == 1){
		flag = 0;




		for (i=A; i<=B; i++){
			for (j=i+1; j<=B; j++){

				if (set[i] == set[j]) continue;

				for (k=0; k<pcount; k++){

					if (pfactor[i][k] == 1 && pfactor[j][k] == 1 && plist[k] >= P){
				//						printf("merging %d (set %d) and %d (set %d)\n", i, set[i], j, set[j]);
						flag = 1;
						ans++;
						temp = set[j];
						for (p=A; p<=B; p++){
							if (set[p] == temp) {
								set[p] = set[i];
								//				printf("%d is now in the set %d\n", p, set[i]);
							}	
						}
						break;
					}
				}
			}
		}
	}



	printf("Case #%d: %d\n",qq+1, B-A+1-ans);
	}

	return 0;
}
