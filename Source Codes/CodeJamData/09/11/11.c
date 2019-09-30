#include <stdio.h>

int record[1025];

char happy[11][40000000];

void mark(int input, int base, int mark)
{
    while (happy[base][input] == 1) {
	int sum = 0;
	happy[base][input] = mark;
	while (input > 0) {
	    sum += (input % base) * (input % base);
	    input /= base;
	}
	input = sum;
	if (input == 1)
	    return;
    }
}

int IsHappy(int input, int base)
{
    int i;
    int temp = input;
    if (happy[base][input] == 2)
	return 1;
    else if (happy[base][input] == 3)
	return 0;
    while (happy[base][input] == 0) {
	int sum = 0;
	happy[base][input] = 1;
	while (input > 0) {
	    sum += (input % base) * (input % base);
	    input /= base;
	}
	input = sum;
	if (input == 1) {
	    mark(temp, base, 2);
	    return 1;
	}
	if (happy[base][input] == 2){
	    mark(temp, base, 2);
	    return 1;
        }
	else if (happy[base][input] == 3){
	    mark(temp, base, 3);
	    return 0;
        }
    }
    mark(temp, base, 3);
    return 0;
}

int main(int argc, char **argv)
{
    int i, j, k, l, n, base[10];
    char c;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
	for (j = 0;; j++) {
	    scanf("%d", &base[j]);
	    scanf("%c", &c);
	    if (c == '\n')
		break;
	}
	j++;
	for (k = 2;; k++) {
	    for (l = 0; l < j; l++)
		if (IsHappy(k, base[l]) == 0)
		    break;
	    if (l == j) {
		printf("Case #%d: %d\n", i + 1, k);
		break;
	    }
	}
    }
}
