#include <stdio.h>
#include <limits.h>

#define P 100
#define Q 20

int releaseorder[P];

int countbribes(int prison[], int released, int size)
{
	int i;
	int count;

	count = 0;
	for (i = released - 1; i >= 0 && prison[i]; i--) {
		count++;
	}
	for (i = released + 1; i < size && prison[i]; i++) {
		count++;
	}

	return count;
}

int getminbribes(int prison[], int releases, int left, int size)
{
	int i;
	int bribes, minbribes;
	int myprison[P];

	minbribes = INT_MAX;

	if (!left) {
		return 0;
	}

	for (i = 0; i < size; i++) {
		myprison[i] = prison[i];
	}

	for (i = 0; i < releases; i++) {
		if (prison[releaseorder[i]]) {

			int j = releaseorder[i];

			myprison[j] = 0;
			bribes = countbribes(myprison, j, size) + getminbribes(myprison, releases, left - 1, size);
			myprison[j] = 1;

			if (bribes < minbribes) {
				minbribes = bribes;
			}
		}
	}

	return minbribes;
}

int main(void)
{
	int ncase, ncases;
	int prisioners, releases;
	int prison[P];
	int i;

	scanf("%d", &ncases);
	for (ncase = 1; ncase <= ncases; ncase++) {

		scanf("%d%d", &prisioners, &releases);

		for (i = 0; i < prisioners; i++) {
			prison[i] = 1;
		}
		for (i = 0; i < releases; i++) {
			scanf("%d", &releaseorder[i]);
			releaseorder[i]--;
		}

		printf("Case #%d: %d\n", ncase, getminbribes(prison, releases, releases, prisioners));

	}

	return 0;
}
