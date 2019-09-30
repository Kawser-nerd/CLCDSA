#include <stdio.h>

int main() {
	FILE *f = fopen("A-large.in", "r");
	int N;
	fscanf(f, "%d", &N);
	for (int test_cast = 0; test_cast < N; test_cast++)
	{
		char buf[1002];
		fscanf(f, "%s", buf);
		char out[1002];
		int len = strlen(buf);
		out[len] = 0;
		int out_left = 0;
		int out_right = len-1;
		for (int index = len-1; index >= 0; )
		{
			int in_index = 0;
			for (int ii = 0; ii <= index; ii++)
			{
				if (buf[ii] >= buf[in_index]) {
					in_index = ii;
				}
			}
			// remaining to right
			for (int ii = index; ii > in_index; ii--)
			{
				out[out_right--] = buf[ii];
			}
			out[out_left++] = buf[in_index];
			index = in_index - 1;
		}
		printf("Case #%d: %s\n", test_cast + 1, out);
	}
	return 0;
}