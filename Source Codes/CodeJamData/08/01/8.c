#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100
#define MAXSIZE 1000

typedef struct searchengine{
	int no;
	char content[MAXLEN];
} *SE;

typedef struct query{
	int no;
	char content[MAXLEN];
} *Q;

SE se[MAXLEN];
Q qy[MAXSIZE];
int n,s,q;
int bitmap[MAXSIZE]={0};
int cases[MAXLEN]= {0};

int se2no(Q qt){
	int i;
	for(i=1;i<=s;i++){
		if(strcmp(qt->content,se[i]->content)==0)
			return i;
	}
	return 0;
}

int check(){
	int i;
	for(i=1;i<=s;i++){
		if(bitmap[i]==0)
			return 0;
	}
	return 1;
}
void clearbitmap(){
	int i;
	for(i=0;i<=s;i++){
		bitmap[i]=0;
	}
}
int computeSwitchs(){
	int result = 0;
	int i,index;
	for(i=1;i<=q;i++){
		index = se2no(qy[i]);
		bitmap[index]++;
		if(check())
		{
			result++;
			clearbitmap();
			i--;
		}
	}
	clearbitmap();
	return result;
}

void getline(char *a,FILE *f){
	char c;
	int i = 0;
	while((c=fgetc(f))!='\n' && c != EOF)
		a[i++] = c;
	a[i] = '\0';
}

void main(){
	FILE *f;
	int i,j;
	
	f = fopen("A-large.in","r");
	fscanf(f,"%d",&n);
	for(i=0;i<n;i++){
		fscanf(f,"%d",&s);
		fgetc(f);
		for(j=1;j<=s;j++){
			se[j] = malloc(sizeof(struct searchengine));
			getline(se[j]->content,f);
			se[j]->no = j;
		}
		fscanf(f,"%d",&q);
		fgetc(f);
		for(j=1;j<=q;j++){
			qy[j] = malloc(sizeof(struct query));
			getline(qy[j]->content,f);
			qy[j]->no = j;
		}
		cases[i] = computeSwitchs();
	}
	fclose(f);
	f = fopen("A-large.out","w");
	for(i=0;i<n;i++){
		fprintf(f,"Case #%d: %d\n",i+1,cases[i]);
	}
	

};