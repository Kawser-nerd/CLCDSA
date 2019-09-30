/*
AtCoder Regular Contest 007 B - ???CD???
Ver10???
??:
*/

#include<stdio.h>

//#define DEBUG1

int main() {

	int n, m;
	int pl[101] = { 0 };//??????
	int ca[100] = { 0 };//CD???
	int play = 0;//????CD
	int kari = 0;//??????????CD

	/*????? ???????*/
	scanf("%d %d", &n, &m);
	/*?????????*/
	pl[0] = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &pl[i]);
	}
#ifdef DEBUG1
	puts("<??????>");
	for (int i = 0; i <= m; i++) {
		printf("pl[%d] = %d\n", i, pl[i]);
	}
#endif
	/*CD????CD??????*/
	for (int i = 0; i < n + 1; i++) {
		ca[i] = i;
	}
#ifdef DEBUG1
	puts("<CD????????>");
	for (int i = 0; i < n + 1; i++) {
		printf("ca[%d] = %d\n", i, ca[i]);
	}
#endif

	/*?????*/
	for (int i = 1; i < m + 1; i++) {
#ifdef DEBUG1
		printf("??? %d : pl[%d] = %d?", i, i, pl[i]);
#endif
		if (pl[i] == play) {//??????
			//?????
#ifdef DEBUG1
			puts("<??????>");
#endif
		}
		if (pl[i] != play) {//??????????
#ifdef DEBUG1
			puts("<??????????>");
#endif
			//??CD???
			for (int j = 1; j < n + 1; j++) {
				if (pl[i] == ca[j]) {
					kari = play;
					play = ca[j];
					ca[j] = kari;
#ifdef DEBUG1
					printf("play = %d  ca[%d] = %d\n", play, j, ca[j]);
#endif
				}
			}
		}

	}

	/*??*/
#ifdef DEBUG1
	puts("<CD??????>");
	for (int i = 1; i < n + 1; i++) {
		printf("ca[%d] = %d\n", i, ca[i]);
	}
#endif
	for (int i = 1; i < n + 1; i++) {
		printf("%d\n", ca[i]);
	}
#ifdef DEBUG1
	getch();
#endif
	//getch();
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &m);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &pl[i]);
   ^