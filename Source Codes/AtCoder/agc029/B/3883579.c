#include <stdio.h>
#include <stdlib.h>
#include <math.h>

inline int read_int(void)
{
	int i;
	int c;
	i = 0;

	while(1) {
		c = getc(stdin);
		if (c >= '0' && c <= '9') {
			i = c - '0';
			break;
		}
	}
	while(1) {
		c = getc(stdin);
		if (c >= '0' && c <= '9') {
			i = i * 10 + (c - '0');
		} else {
			break;
		}
	}
	return i;
}

int compare_int(const void *a, const void *b)
{
	// ?? 
	return *(int *) b - *(int *) a;
}

typedef int value_type; /* ????????? */

/* x, y, z ??????? */
value_type med3(value_type x, value_type y, value_type z) {
    if (x < y) {
        if (y < z) return y; else if (z < x) return x; else return z;
    } else {
        if (z < y) return y; else if (x < z) return x; else return z;
    }
}

/* ???????
 * a     : ???????
 * left  : ?????????????
 * right : ?????????????
 */
void quicksort(value_type a[], int left, int right) {
    if (left < right) {
        int i = left, j = right;
        value_type tmp, pivot = med3(a[i], a[i + (j - i) / 2], a[j]); /* (i+j)/2 ?????????????? */
        while (1) { /* a[] ? pivot ?????????????? */
            while (a[i] > pivot) i++; /* a[i] >= pivot ???????? */
            while (pivot > a[j]) j--; /* a[j] <= pivot ???????? */
            if (i >= j) break;
            tmp = a[i]; a[i] = a[j]; a[j] = tmp; /* a[i], a[j] ??? */
            i++; j--;
        }
        quicksort(a, left, i - 1);  /* ????????????? */
        quicksort(a, j + 1, right); /* ????????????? */
    }
}

int main(int argc, char *argv[])
{
	int n, i, c;
	int j;
	int a[200000];
	
	int x, y;
	int min_sq, l_min_sq;
	
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
	//	scanf("%d", &a[i]);
		a[i] = read_int();
	}
	
	//qsort(a, n, sizeof(int), compare_int);
	quicksort(a, 0, n - 1);

	c = 0;

	l_min_sq = -1;
	for (i = 0; i < n; i++) {
		x = a[i];
		if (x == 0) {continue;}
		min_sq = pow(2, (int) log2(x) + 1);

		if (l_min_sq != min_sq) {
			j = n - 1;
		}
		for (;j > i; j--) {
			y = a[j];
			if (y == 0) {continue;}
			if (y == min_sq - x) {
				a[j] = 0;
				c++;
				break;
			}
			if (y > min_sq - x) {
				break;
			}
		}
		l_min_sq = min_sq;
	}

	printf("%d\n", c);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:76:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^