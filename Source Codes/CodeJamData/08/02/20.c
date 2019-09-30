#include <stdio.h>
#include <string.h>

struct time
{
	int hh;
	int mm;
};

int mycomp(const void *aa, const void *bb)
{
	struct time a = *(struct time *) aa;
	struct time b = *(struct time *) bb;
	return (a.hh-b.hh)?(a.hh-b.hh):(a.mm-b.mm);
}

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
		int T, NA, NB;
		fscanf(fp,"%d\n%d %d\n",&T,&NA,&NB);
		struct time aout[NA];
		struct time ain[NB];
		struct time bout[NB];
		struct time bin[NA];
		int i, j;
		for (i=0; i<NA; i++) {
			fscanf(fp,"%d:%d %d:%d\n",
					&(aout[i].hh), &(aout[i].mm),
					&(bin[i].hh), &(bin[i].mm));
		}
		for (i=0; i<NB; i++) {
			fscanf(fp,"%d:%d %d:%d\n",
					&(bout[i].hh), &(bout[i].mm),
					&(ain[i].hh), &(ain[i].mm));
		}
		////
		qsort(aout, NA, sizeof(struct time), mycomp);
		qsort(bin, NA, sizeof(struct time), mycomp);
		qsort(bout, NB, sizeof(struct time), mycomp);
		qsort(ain, NB, sizeof(struct time), mycomp);
		int N = NA + NB;
		int ans1 = NA;
		int ans2 = NB;

		i = j = 0;
		struct time temp;
		while (i < NA && j < NB) {
			temp.hh = bin[i].hh;
			temp.mm = bin[i].mm + T;
			if (temp.mm >= 60) {
				temp.mm -= 60;
				temp.hh++;
			}
			if (mycomp(&temp, &bout[j]) <= 0) {
				ans2--;
				i++;
			}
			j++;
		}

		i = j = 0;
		while (i < NB && j < NA) {
			temp.hh = ain[i].hh;
			temp.mm = ain[i].mm + T;
			if (temp.mm >= 60) {
				temp.mm -= 60;
				temp.hh++;
			}
			if (mycomp(&temp, &aout[j]) <= 0) {
				ans1--;
				i++;
			}
			j++;
		}

		//
		printf("Case #%d: %d %d\n",++n2,ans1,ans2);
	}
	fclose(fp);
	return 0;
}

