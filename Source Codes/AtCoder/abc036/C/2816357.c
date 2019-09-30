#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int a,b,c;

typedef struct {
    int a;
    int b;
    int c;
} person;

int max(int a, int b){
    if(a>b){
        return(a);
    } else {
        return(b);
    }
}

int min(int a, int b){
    if(a<b){
        return(a);
    } else {
        return(b);
    }
}

int sorta (const void *a, const void *b){
    return ((person*)a)->a - ((person*)b)->a ;
}

int sortb (const void *a, const void *b){
    return ((person*)a)->b - ((person*)b)->b ;
}

int main(void){
    int n;
    scanf("%d",&n);
    person p[n];
    for (int i=0; i<n; i++){
        scanf("%d",&p[i].a);
        p[i].b=i;
    }
    qsort (p,n,sizeof(person),sorta);
    int count=0;
    for (int i=0; i<n; i++){
        if (i==0){
            p[i].c=count;
        } else if (p[i].a==p[i-1].a){
            p[i].c=count;
        } else {
            count++;
            p[i].c=count;
        }
    }
    qsort (p,n,sizeof(person),sortb);
    for (int i=0; i<n; i++){
        printf("%d\n",p[i].c);
    }
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:41:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:44:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&p[i].a);
         ^