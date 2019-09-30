/*
 * main.c
 *
 *  Created on: 2019/02/21
 *      Author: family
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	long long int x;
	long long int y;
	long long int h;
} info_t;

info_t data[100] = {0};

long long int max(long long int a, long long int b)
{
	if (a > b) {
		return a;
	} else {
	}
	return b;
}

void get_center_pos(long long int* cx, long long int *cy, int n, int ref)
{
	long long int i = 0;
	long long int j = 0;
	long long int h1 = 0;
	long long int h2 = 0;
    int k = 0;
	for( i = 0; i <= 100; i++) {
		for( j = 0; j <= 100; j++) {
			h1 = data[ref].h + abs(data[ref].x - i) + abs(data[ref].y - j);
			for( k = 0; k < n; k++) {
				h2 = max(h1 - abs(data[k].x - i) - abs(data[k].y - j), 0);
				if (data[k].h == h2) {
				} else {
					break;
				}
			}
			if( k == n ) {
				*cx = i;
				*cy = j;
				return;
			}
		}
	}
	return;
}

int main()
{
	int n_info_count = 0;
	int i = 0;
	int ref = 0;
	long long int x,y,h;
	scanf("%d", &n_info_count);
	for(i = 0; i < n_info_count; i++) {
		scanf("%lld %lld %lld", &x, &y, &h);
		data[i].x = x;
		data[i].y = y;
		data[i].h = h;
	}

	for(i = 0; i < n_info_count; i++) {
		if (data[i].h != 0) {
			ref = i;
			break;
		}
	}

	get_center_pos(&x, &y, n_info_count, ref);
	h = data[ref].h + abs(data[ref].x - x) + abs(data[ref].y - y);
	printf("%lld %lld %lld\n", x, y, h);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:64:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n_info_count);
  ^
./Main.c:66:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld %lld", &x, &y, &h);
   ^