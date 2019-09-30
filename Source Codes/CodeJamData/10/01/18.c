#include<stdio.h>

int main(int argc, char* argv[]){
	unsigned long machines;
	unsigned long pulses;
	unsigned long cases;
	unsigned long base;
	unsigned long i;
	char line[256];

	if (!fgets(line,256,stdin))
		return -1;

	cases=atoi(line);

	for (i=1;i<=cases;i++){
		if (!fgets(line,256,stdin))
			return -1;
		if (2!=sscanf(line,"%ld %ld",&machines,&pulses))
			return -1;
		base=1<<machines;
		pulses%=base;
		if (pulses==base-1)
			fprintf(stdout, "Case #%d: ON\n",i);
		else
			fprintf(stdout, "Case #%d: OFF\n",i);
	}
	return 0;
}
