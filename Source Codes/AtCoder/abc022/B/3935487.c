#include <stdio.h>
#include <stdlib.h>

typedef struct a{
	int no;
	struct a *next;
} visit;

visit **flower;

void init(){
	flower = malloc(sizeof(visit*) * 100);
	for(int i = 0; i < 100; i++)
		flower[i] = NULL;
}

int look(int no){
	visit *top = flower[no % 100];
	while(top){
		if(top->no == no)return 1;
		top = top->next;
	}
	return 0;
}

void add(int no){
	if(flower[no % 100] == NULL){
		flower[no % 100] = malloc(sizeof(visit));
		flower[no % 100]->no = no;
		flower[no % 100]->next = NULL;
		return;
	}
	visit *top = flower[no % 100];
	while(top->next != NULL)top = top->next;
	top->next = malloc(sizeof(visit));
	top = top->next;
	top->no = no;
	top->next = NULL;
}

int main(){
	int n;
	int in, count = 0;
	init();
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &in);
		if(look(in))
			count++;
		else
			add(in);
	}
	printf("%d\n", count);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:45:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:47:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &in);
   ^