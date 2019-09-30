#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>


int n;
struct Person {
	int number;
	int boss;
	int junior[20];
	int junior_num;
	long salary;
	int done;
};

struct Person person[20];


int main() {
	for(int i = 0; i < 20; i++) {
		person[i].number = i;
		person[i].boss = 0;
		person[i].junior_num = 0;
		person[i].salary = 0;
	}

	scanf("%d", &n);

	for(int i = 1; i < n; i++) {
		scanf("%d", &person[i].boss);
		person[i].boss--;
		int target = person[i].boss;
		person[target].junior_num++;
		int target_junior_num = person[target].junior_num;
		person[target].junior[target_junior_num - 1] = i;
	}

	for(int i = 0; i < n; i++) {
		if(person[i].junior_num == 0) {
			person[i].salary = 1;
		}
	}

	while(1) {
		int id;
		int flag = 0;
		for(int i = 0; i < n; i++) {
			//???????????
			if(person[person[i].boss].salary != 0) {
				continue;
			}

			//???????
			if(person[i].salary == 0) {
				continue;
			}

			id = person[i].boss;
			flag = 1;

			for(int j = 0; j < person[id].junior_num; j++) {
				//???????????????
				if(person[person[id].junior[j]].salary == 0) {
					flag = 0;
					break;
				}
			}
			if(flag == 0) {
				continue;
			}
			else {
				break;
			}
		}

		if(flag == 0) {
			break;
		}

		long max = 0, min = 10000000;
		for(int i = 0; i < person[id].junior_num; i++) {
			long junior_salary = person[person[id].junior[i]].salary;
			if(max < junior_salary) {
				max = junior_salary;
			}
			if(min > junior_salary) {
				min = junior_salary;
			}
		}

		person[id].salary = 1 + min + max;
	}

	printf("%ld\n", person[0].salary);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:32:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &person[i].boss);
   ^