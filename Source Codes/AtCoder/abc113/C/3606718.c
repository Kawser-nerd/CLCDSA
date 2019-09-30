#include <stdio.h>
#include <stdlib.h>

struct dat{
	int num;
	int p;
	int y;
};

int dat_sort(const void *a, const void *b) {
  return ((struct dat *)a)->y - ((struct dat *)b)->y;
}

int main( void ){
	struct dat city[100001];
	int n,m,pref[100001],id[100001],pcnt[100001]={0};
	int i;

	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&city[i].p,&city[i].y);
		city[i].num = i;
		pref[i]=city[i].p;
	}

	qsort( city, m, sizeof(city[0]), dat_sort );
	for(i=0;i<m;i++){
		id[ city[i].num ] = ++pcnt[ city[i].p ];
	}
		
	for(i=0;i<m;i++)
		printf("%06d%06d\n",pref[i],id[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&city[i].p,&city[i].y);
   ^