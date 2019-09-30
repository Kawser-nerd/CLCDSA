//gcc -std=gnu11 -O2 -o a.out Main.c -lm
//http://abc039.contest.atcoder.jp/tasks/abc039_c
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdint.h>
#include <string.h>


const char *answerStr[12] = {
	"Do",
	"Do#",
	"Re",
	"Re#",
	"Mi",
	"Fa",
	"Fa#",
	"So",
	"So#",
	"La",
	"La#",
	"Si",
};

int main(void)
{
#define N_MAX 20
	int ret;
	int i,j,k;
	char kenbanStr[N_MAX+1];

	//-------------------------------------
	//Input process
	//-------------------------------------
	ret = scanf("%s", kenbanStr);
	if(strlen(kenbanStr) != 20){
		printf("kenbanStr length error.\n");
		return(-1);
	}

	//-------------------------------------
	//Search process
	//-------------------------------------
	
	//???????????????
	for(i=0;i<(N_MAX-1);i++){
		if(kenbanStr[i] == 'W' && kenbanStr[i+1] == 'W'){
			break;
		}
	}
	//i?????6??????-5???????????????????????
	if(i<5) {
		j=i+6;
	}else{
		j=j-5;
	}
	if(kenbanStr[j] == 'B'){
		//i?????
		k= (12+4-i)%12;
	}else{
		//i?????
		k=(12+11-i)%12;
	}
	
	//-------------------------------------
	//Output process
	//-------------------------------------
	printf("%s\n", answerStr[k]);

	return(0);
}