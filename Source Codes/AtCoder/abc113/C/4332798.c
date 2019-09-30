/*
 * main.c
 *
 *  Created on: 2019/02/20
 *      Author: family
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	int p;
	int year;
	int no;
	int seq_num;
} city_data_t;

city_data_t data[100001] = {0};

int sort_inc_year(const void *a, const void *b)
{
	int dta = ((city_data_t*)a)->year;
	int dtb = ((city_data_t*)b)->year;
	//printf("%llu %llu\n",dta, dtb);
	return (dta - dtb);
}

int sort_inc_no(const void *a, const void *b)
{
	int dta = ((city_data_t*)a)->no;
	int dtb = ((city_data_t*)b)->no;
	//printf("%d %d\n",dta, dtb);
	return (dta - dtb);
}

int sort_inc_pref(const void *a, const void *b)
{
	int dta = ((city_data_t*)a)->p;
	int dtb = ((city_data_t*)b)->p;
	//printf("%d %d\n",dta, dtb);
	if (dta == dtb) {
		dta = ((city_data_t*)a)->year;
		dtb = ((city_data_t*)b)->year;
	}
	return (dta - dtb);
}

void printdata(int m)
{
	int i = 0;
	for(i = 0; i < m; i++) {
		printf("p=%d,y=%llu,n=%d\n", data[i].p, data[i].year, data[i].no);
	}
}

int main()
{
	int n_pref = 0;
	int m_city = 0;
	int i = 0;
	int v = 1;
	int pref_no = 0;
	scanf("%d %d", &n_pref, &m_city);
	for(i = 0; i < m_city; i++) {
		int a = 0;
		unsigned long long int b = 0;
		scanf("%d %llu", &a, &b);
		data[i].p = a;
		data[i].year = b;
		data[i].no = i;
	}
	qsort(data, m_city, sizeof(city_data_t), sort_inc_pref);
	//printdata(m_city);
	for(i = 0; i < m_city; i++) {
		if(pref_no != data[i].p) {
			v = 1;
			pref_no = data[i].p;
		}
		data[i].seq_num = v++;
	}
	qsort(data, m_city, sizeof(city_data_t), sort_inc_no);
	//printdata(m_city);
	for(i = 0; i < m_city; i++) {
		printf("%06d%06d\n",data[i].p,data[i].seq_num);
	}
	return 0;
} ./Main.c: In function ‘printdata’:
./Main.c:54:10: warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument 3 has type ‘int’ [-Wformat=]
   printf("p=%d,y=%llu,n=%d\n", data[i].p, data[i].year, data[i].no);
          ^
./Main.c: In function ‘main’:
./Main.c:65:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n_pref, &m_city);
  ^
./Main.c:69:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %llu", &a, &b);
   ^