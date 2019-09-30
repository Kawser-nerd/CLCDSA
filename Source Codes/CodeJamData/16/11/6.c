#include <stdio.h>
#include <stdlib.h>

int main() {
	int n_max;
	int n_count;
	int c_count;
	int c_count_2;
	int c_length;
	char c_max;
	int c_record;
	char c_temp;

	scanf("%d\n", &n_max);
	char * s = (char *)malloc(1000 * sizeof(char));
	int * s_r = (int *)malloc(1000 * sizeof(int));

	n_count = 0;



	while (n_count < n_max) {
		n_count ++;
		printf("Case #%d: ", n_count);
		
		c_length = 0;
		c_temp = 1;
		while (c_temp) {
			scanf("%c", &c_temp);
			if (c_temp == '\n' || c_temp == EOF) {
				c_temp = 0;
			}
			s[c_length] = c_temp;
			c_length ++;
		}
		c_length --;		

		c_count = 0;
		while (c_count < c_length) {
			s_r[c_count] = 1;
			c_count ++;
		}

		c_count = c_length;
		while (c_count > 0) {
			c_count_2 = c_count;
			c_record = -1;
			while (c_count_2 > 0) {
				c_count_2 --;
				if (c_record == -1 || s[c_record] < s[c_count_2]) {
					c_record = c_count_2;
				}
			}

			printf("%c", s[c_record]);
			s_r[c_record] = 0;

			c_count = c_record;
			// printf("%d\n", c_count);
		}

		c_count = 0;
		while (c_count < c_length) {
			if (s_r[c_count]) {
				printf("%c", s[c_count]);
			}
			c_count ++;
		}
		
		printf("\n");
	}
	
}
