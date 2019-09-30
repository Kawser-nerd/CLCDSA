/* common *********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#define ASC 0
#define DESC 1
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
	int ii;
	int T;
	int No;

	char dic[] = "yhesocvxduiglbkrztnwjpfmaq";
	char buff[1000];
	char* tok;

	GenerateFilename(fname_o, argv[1], "_out.txt");
	fp_i = fopen(argv[1], "r");
	fp_o = fopen(fname_o, "w");

	fgets(buff, sizeof(buff), fp_i);
	tok = strtok(buff, "\r\n");
	T = atoi(tok);
	for(No=1; No<=T; No++){
		fgets(buff, sizeof(buff), fp_i);
		tok = strtok(buff, "\r\n");

		fprintf(fp_o, "Case #%d: ", No);
		for(ii=0; tok[ii]!='\0'; ii++){
			if(tok[ii] == ' '){
				fprintf(fp_o, " ");
			}else{
				fprintf(fp_o, "%c", dic[tok[ii]-'a']);
			}
		}
		fprintf(fp_o, "\n");
	}

	fclose(fp_i);
	fclose(fp_o);
}
