#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct {
    long departure;
    long arrival;
} Train;

int CompareInt(int *a,int *b){
    return (*a-*b);
}
int CompareIntR(int *a,int *b){
    return (*b-*a);
}

int main(int argc, char **argv){
    int numOfCases;
    int i;

    scanf("%d",&numOfCases);
    for(i=0; i < numOfCases; i++){
        int dimension,j;
        int vectorA[800];
        int vectorB[800];
        int answer;

        scanf("%d",&dimension);
        for(j=0; j < dimension; j++){
            scanf("%d",&vectorA[j]);
        }
        for(j=0; j < dimension; j++){
            scanf("%d",&vectorB[j]);
        }
        qsort(vectorA,dimension,sizeof(int),(int(*)(const void*, const void*))CompareInt);
        qsort(vectorB,dimension,sizeof(int),(int(*)(const void*, const void*))CompareIntR);

        for(j=0,answer=0; j < dimension; j++){
            //            printf("%d %d\n",vectorA[j],vectorB[j]);
            answer += vectorA[j]*vectorB[j];
        }
        printf("Case #%d: %d\n",i+1,answer);
    }
}

