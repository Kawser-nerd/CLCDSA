/* common *********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
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

long long int S[500];
int flg[500];
int N;
long long int A;
long long int B;

void solver(int jj){
	int ii;

	if(A==B) return;

	for(ii=jj+1; ii<N; ii++){
		if(flg[ii]!=0)continue;

		if(A<B){
			flg[ii] = 1;
			A+=S[ii];
			solver(ii);
			if(A==B)break;
			flg[ii] = 0;
			A-=S[ii];

			flg[ii] = 2;
			B+=S[ii];
			solver(ii);
			if(A==B)break;
			flg[ii] = 0;
			B-=S[ii];

			solver(ii);
			if(A==B)break;
		}else{
			flg[ii] = 2;
			B+=S[ii];
			solver(ii);
			if(A==B)break;
			flg[ii] = 0;
			B-=S[ii];

			flg[ii] = 1;
			A+=S[ii];
			solver(ii);
			if(A==B)break;
			flg[ii] = 0;
			A-=S[ii];

			solver(ii);
			if(A==B)break;
		}
	}

}
void main(int argc, char* argv[]){
	char fname_o[_MAX_PATH];
	FILE* fp_i;
	FILE* fp_o;
	int No;
	int ii;
	int T;

	GenerateFilename(fname_o, argv[1], "_out.txt");
	fp_i = fopen(argv[1], "r");
	fp_o = fopen(fname_o, "w");

	fscanf(fp_i, "%d", &T);
	for(No=1; No<=T; No++){
		fprintf(stderr, "Case #%d/%d...", No, T);
		fscanf(fp_i, "%d", &N);

		for(ii=0; ii<N; ii++){
			fscanf(fp_i, "%lld", &(S[ii]));
			flg[ii]=0;
		}

		A=0;
		B=0;

		for(ii=0; ii<N; ii++){
			flg[ii] = 1;
			A+=S[ii];
			solver(ii);
			if(A==B)break;
			flg[ii] = 0;
			A-=S[ii];
		}

		fprintf(fp_o, "Case #%d:\n", No);
		if(ii==N){
			fprintf(fp_o, "Impossible\n");
		}else{
			for(ii=0; ii<N; ii++){
				if(flg[ii]==1)fprintf(fp_o, "%d ", S[ii]);
			}
			fprintf(fp_o, "\n");
			for(ii=0; ii<N; ii++){
				if(flg[ii]==2)fprintf(fp_o, "%d ", S[ii]);
			}
			fprintf(fp_o, "\n");
		}

		fprintf(stderr, "finish!!\n");
	}

	fclose(fp_i);
	fclose(fp_o);
}
