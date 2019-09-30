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

typedef struct{
	int No;
	int r;
	int x;
	int y;
}ST_student;

int ST_studentqsort_No_ASC(const void* data1, const void* data2){
	ST_student* I1 = (ST_student*)data1;
	ST_student* I2 = (ST_student*)data2;

	if(I1->No>I2->No) return 1;
	if(I1->No<I2->No) return -1;
	return 0;
}

int ST_studentqsort_r_ASC(const void* data1, const void* data2){
	ST_student* I1 = (ST_student*)data1;
	ST_student* I2 = (ST_student*)data2;

	if(I1->r>I2->r) return 1;
	if(I1->r<I2->r) return -1;
	return 0;
}

void ST_studentqsort_No(ST_student* v, int num, int updown){
	if(updown==0){	qsort(v, num, sizeof(ST_student), ST_studentqsort_No_ASC);}
//	else{			qsort(v, num, sizeof(ST_student), ST_studentqsort_No_DESC);}
}

void ST_studentqsort_r(ST_student* v, int num, int updown){
	if(updown==0){	qsort(v, num, sizeof(ST_student), ST_studentqsort_r_ASC);}
//	else{			qsort(v, num, sizeof(ST_student), ST_studentqsort_r_DESC);}
}

void main(int argc, char* argv[]){
	char fname_o[_MAX_PATH];
	FILE* fp_i;
	FILE* fp_o;
	int No;
	int ii;

	int T;
	int N;
	int W;
	int L;
	ST_student student[2000];
	int flg;

	GenerateFilename(fname_o, argv[1], "_out.txt");
	fp_i = fopen(argv[1], "r");
	fp_o = fopen(fname_o, "w");

	fscanf(fp_i, "%d", &T);
	for(No=1; No<=T; No++){
		fprintf(stderr, "Case #%d/%d...", No, T);
		fscanf(fp_i, "%d", &N);
		fscanf(fp_i, "%d", &W);
		fscanf(fp_i, "%d", &L);

		for(ii=0; ii<N; ii++){
			student[ii].No = ii;
			fscanf(fp_i, "%d", &(student[ii].r));
			student[ii].x = 0;
			student[ii].y = 0;
		}

		ST_studentqsort_r(student, N, 0);

		flg = 0;
		if(W>L){
			for(ii=1; ii<N; ii++){
				if(flg==0){
					student[ii].x = student[ii-1].x + student[ii-1].r + student[ii].r;
					student[ii].y = 0;
					if(student[ii].x > W){
						flg = 1;
						student[ii].x = 0;
						student[ii].y = L;
						continue;
					}
				}else{
					student[ii].x = 0;
					student[ii].y = student[ii-1].y - student[ii-1].r - student[ii].r;
				}
			}
		}else{
			for(ii=1; ii<N; ii++){
				if(flg==0){
					student[ii].x = 0;
					student[ii].y = student[ii-1].y + student[ii-1].r + student[ii].r;
					if(student[ii].y > L){
						flg = 1;
						student[ii].x = W;
						student[ii].y = 0;
						continue;
					}
				}else{
					student[ii].x = student[ii-1].x - student[ii-1].r - student[ii].r;
					student[ii].y = 0;
				}
			}
		}

		ST_studentqsort_No(student, N, 0);

		fprintf(fp_o, "Case #%d:", No);
		for(ii=0; ii<N; ii++){
			fprintf(fp_o, " %d %d", student[ii].x, student[ii].y);
		}
		fprintf(fp_o, "\n");

		fprintf(stderr, "finish!!\n");
	}

	fclose(fp_i);
	fclose(fp_o);
}
