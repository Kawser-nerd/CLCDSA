#include <stdio.h>

#define max_len_target_string 30

int main (void)
{
	/* variables for main process */
	char buf_target_string[max_len_target_string];
	int  buf_rtvl_int;
	int  itr_elem;

	// STEP.01
	// read out the target integers
	buf_rtvl_int = scanf ("%s", &buf_target_string);

	// STEP.02
	// output the read string without designated characters
	for (itr_elem = 0; itr_elem < strlen (buf_target_string); itr_elem++)
	{
		if ( buf_target_string[itr_elem] == 'a' ) { continue; }
		if ( buf_target_string[itr_elem] == 'i' ) { continue; }
		if ( buf_target_string[itr_elem] == 'u' ) { continue; }
		if ( buf_target_string[itr_elem] == 'e' ) { continue; }
		if ( buf_target_string[itr_elem] == 'o' ) { continue; }

		printf ("%c", buf_target_string[itr_elem]);
	}
	printf ("\n");

	// STEP.END
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:24: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[30]’ [-Wformat=]
  buf_rtvl_int = scanf ("%s", &buf_target_string);
                        ^
./Main.c:18:32: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
  for (itr_elem = 0; itr_elem < strlen (buf_target_string); itr_elem++)
                                ^
./Main.c:18:32: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:18:32: note: include ‘<string.h>’ or provide a declaration of ‘strlen’