#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned cur_line, cur_column, min, record_size,
	        *A;
	const unsigned alpha = 26;
	int i,
	    flag;
	char ch;

	scanf("%u\n",&record_size);
	
	A = (unsigned *)malloc(sizeof(unsigned) * alpha * record_size);
	i = alpha * record_size;
	while(0 <= --i) A[i] =0;
	
	cur_line = 0;
	while (cur_line < record_size)
	{
		while ('\n' != ( ch=fgetc(stdin) ) )
			A[cur_line * alpha + ch - 'a'] += 1;
		
		cur_line++;
	}
	
	cur_column  =0;
	while (cur_column < alpha)
	{
		cur_line = 0;
		min = -1;
		flag = 1;
		while (cur_line < record_size)
		{
			
			if (A[alpha * cur_line + cur_column] == 0){
				flag = 0;
				break;
			}
			else if (min > A[alpha * cur_line + cur_column] )
				min = A[alpha * cur_line + cur_column];
			
			cur_line++;
		}
		if (flag ==1)
			while (min--) printf("%c",cur_column + 'a');
		
		cur_column++;
	}
	fputc('\n',stdout);
	
	free(A);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%u\n",&record_size);
  ^