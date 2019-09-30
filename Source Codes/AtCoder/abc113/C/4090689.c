#include <stdio.h>
#include <stdlib.h>
 
#define DEBUG 0
 
typedef struct {
	int input;
 	int place;
  	long year;
  	long id;
} Town;

int compareInput(const void *a,const void *b)
{
	return ((Town *)a)->input - ((Town *)b)->input;
}

int compareYear(const void *a,const void *b)
{
	return ((Town *)a)->year - ((Town *)b)->year;
}
 
int main(void)
{
	int n,m,*p;
 	long i,j,k,min;
  	Town *town;
  	scanf("%d %d",&n,&m);
  	town = (Town *)malloc(sizeof(Town) * m);
  	if (town==NULL) {
    		perror("town malloc");
    	  	exit(1);
   	 }
  	for (i=0;i<m;i++) {
		scanf("%d %ld",&town[i].place,&town[i].year);
		town[i].input = i;
	}
	p = (int *)malloc(sizeof(int) * n);
	for (i=0;i<n;i++) p[i]=1;
	qsort(town,m,sizeof(Town),compareYear);
	
	for (i=0;i<m;i++) {
		town[i].id = town[i].place * 1E6 + p[town[i].place-1];
		p[town[i].place-1]++;
	}

	qsort(town,m,sizeof(Town),compareInput);
  	for (i=0;i<m;i++) printf("%012ld\n",town[i].id);
	
  	free(town);
	free(p);
  	return 0;
} ./Main.c: In function ‘main’:
./Main.c:28:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d %d",&n,&m);
    ^
./Main.c:35:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %ld",&town[i].place,&town[i].year);
   ^