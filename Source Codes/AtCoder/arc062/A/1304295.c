#include "stdio.h"

int main()
{
	//?????????
	//??????????????????????????????
	int N = 0;
	int T[1010], A[1010];
	long long int voteT = 0, voteA = 0;
	for (int i = 0; i < 1010; i++) {
		T[i] = 0;
		A[i] = 0;
	}

	//?????????
	scanf("%d",&N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &T[i], &A[i]);
	}

	//???????????????????
	voteT = T[0];
	voteA = A[0];

	//???????????
	long long int count = 0;

	//??????????????????????i=1?i=N?????
	for (int i = 1; i < N; i++) {
		//??????????
		count = 0;

		//???????
		//???????????????????????while???????
		if ((T[i] == T[i - 1]) && (A[i] == A[i - 1]))
			count = -1;

		//??????
		//???????????????
		if ((T[i] == 1) && (A[i] == 1)) {
			if (voteT >= voteA)
				voteA = voteT;
			else
				voteT = voteA;

			count = -1;
		}

		//???????????????????????????????
		if (count != -1) {
			//????????????????????????????????????????
			//????????????????????????

			if (voteT >= T[i]) {
				for (int j = 0; j < T[i]; j++) {
					if ((voteT - j) % T[i] == 0) {
						count = voteT / T[i];
						break;
					}
				}
			}

			//A?????????
			if (voteA >= A[i]) {
				for (int j = 0; j < A[i]; j++) {
					if ((voteA - j) % A[i] == 0) {
						//??A???????????????????????????
						//??????????????????
						if (count < voteA / A[i])
							count = voteA / A[i];
						else
							break;
					}
				}
			}
		}
		

		//???????????count==-1?????????????????
		while (count!=-1) {


			//???????????????????????????
			//???????????????
			//?????????????????????????????
			if ((T[i] * count >= voteT) && (A[i] * count >= voteA)) {
				voteT = T[i] * count;
				voteA = A[i] * count;
				break;
			}

			//?????????
			count++;
		}
	}

	//???????
	printf("%lld",voteT+voteA);

    return 0;
} ./Main.c: In function �main�:
./Main.c:17:2: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:19:3: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &T[i], &A[i]);
   ^