/* common *********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#define ASC 0
#define DESC 1
#define LLI long long int
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>

void GenerateFilename(char* out, char* in, char* add){
	char* p;
	sprintf(out, "%s", in);
	for(p=out+strlen(out)-1; p>=out; p--){
		if(*p=='/' )break;
		if(*p=='\\')break;
		if(*p=='.' ){*p='\0'; break;}
	}
	sprintf(out+strlen(out), "%s", add);
}
/******************************************************************************/

void main(int argc, char* argv[]){
	char fname_o[_MAX_PATH];
	FILE* fp_i;
	FILE* fp_o;

	int T;
	int N;
	int S;
	int p;

	int TotalScore;
	int a;
	int b;

	int No;
	int ii;

	int sum;

	GenerateFilename(fname_o, argv[1], "_out.txt");
	fp_i = fopen(argv[1], "r");
	fp_o = fopen(fname_o, "w");

	fscanf(fp_i, "%d", &T);
	for(No=1; No<=T; No++){
		fscanf(fp_i, "%d", &N);
		fscanf(fp_i, "%d", &S);
		fscanf(fp_i, "%d", &p);

		sum = 0;
		for(ii=0; ii<N; ii++){
			fscanf(fp_i, "%d", &(TotalScore));
			a = TotalScore / 3;
			b = TotalScore % 3;
			if(      a >= p            ){ sum++;}
			else if( a == p-1 && b != 0){ sum++;}
			else if( a == p-1 && b == 0 && S > 0 && a > 0 ){ sum++; S--;}
			else if( a == p-2 && b == 2 && S > 0){ sum++; S--;}
//			printf("%d %d %d: %d/3=%d...%d", sum, S, p, TotalScore, a, b);
//			printf("\n");
		}
//		printf("\n");

		fprintf(fp_o, "Case #%d: %d\n", No, sum);
	}

	fclose(fp_i);
	fclose(fp_o);
}

