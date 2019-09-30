#include <stdio.h>
#include <stdlib.h>

int sort(const void *a, const void *b){
    return *(int*)b-*(int*)a ;
}

typedef struct {
    int a;
    int b;
} students;

int main(void){
    int n;
    scanf ("%d",&n);
    students student[100000];
    
    for (int i=0; i<n; i++){
        scanf("%d",&student[i].a);
        student[i].b=i;
    }
    qsort (student,n,sizeof(students),sort);
    for (int j=0; j<n; j++){
        printf("%d\n",student[j].b+1);
    }
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%d",&n);
     ^
./Main.c:19:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&student[i].a);
         ^