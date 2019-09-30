#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int n, n2=0;
	if (argc < 2)
		exit(0);
	FILE *fp = fopen(argv[1],"r");
	if (!fp)
		exit(0);
	fscanf(fp,"%d\n",&n);
	while (n--) {
		int S, Q;
		char engine[100][256];
		char query[1000][256];
		fscanf(fp,"%d\n",&S);
		int i, j;
		char c;
		for (i=0; i<S; i++) {
			j = 0;
			while ((c=fgetc(fp)) && c!='\n' && c!=EOF) {
				engine[i][j++] = c;
			}
			engine[i][j] = '\0';
		}
		fscanf(fp,"%d\n",&Q);
		for (i=0; i<Q; i++) {
			j = 0;
			while ((c=fgetc(fp)) && c!='\n' && c!=EOF) {
				query[i][j++] = c;
			}
			query[i][j] = '\0';
		}
		////
		int s = S;
		int ans = 0;
		int x[S];
		int z;
		for (z=0; z<S; z++) {
			x[z] = 1;
		}
		for (i=0; i<Q; i++) {
			for (j=0; j<S; j++) {
				if (strcmp(query[i],engine[j])==0) {
					if (x[j]==1) {
						x[j] = 0;
						s--;
					}
					break;
				}
			}
			if (s==0) {
				ans++;
				s = S;
				for (z=0; z<S; z++) {
					x[z] = 1;
				}
				i--;
			}
		}
		// print result
		printf("Case #%d: %d\n",++n2,ans);
	}
	fclose(fp);
	return 0;
}

