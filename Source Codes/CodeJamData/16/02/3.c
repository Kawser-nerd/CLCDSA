#include <stdio.h>
#include <stdlib.h>

int find(int * array, int mode, int st, int ed) {
	
	//fprintf(stderr, "%d, %d, %d\n",mode, st, ed);
	
	int right;
	int left;

		right = ed;
		while (right >= st && (array[right] == mode)) {
			right --;
		}
		if (right < st) {
			return 0;
		}
		left = right;
		while (left >= st && (array[left] == mode)) {
			left --;
		}
		if (left < st) {
			return 1;
		}
		return 1 + find(array, !mode, st, left);

	/*
	if (mode) {
		right = ed;
		while (right >= st && array[right]) {
			right --;
		}
		if (right < st) {
			return 0;
		}
		left = right;
		while (left >= st && !array[left]) {
			left --;
		}
		if (left < st) {
			return 1;
		}
		return 1 + find(array, !mode, st, left);
	}
	
	else {
		left = st;
		while (left <= ed && !array[left]) {
			left ++;
		}
		if (left > ed) {
			return 0;
		}
		right = left;
		while (right <= ed && array[right]) {
			right ++;
		}
		if (right > ed) {
			return 1;
		}
		return 1 + find(array, !mode, right, ed);
	}
	*/
}

int main() {
	
	
	int num;
	scanf("%d\n", &num);

	int count = 0;
	int * array = malloc(100 * sizeof(int));

	char c;
	int cycle;
	int length;

	while (count < num) {
		
		count ++;

		cycle = 0;
		while (cycle < 100) {
			array[cycle] = 0;
			cycle ++;
		}

		length = 0;
		while ((c = fgetc(stdin)) == '+' || c == '-') {
			if (c == '+') {
				array[length] = 1;
			}
			length ++;
		}
		printf("Case #%d: %d\n", count, find(array, 1, 0, length - 1));
		
	}
}
