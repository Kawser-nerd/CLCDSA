
#include<stdio.h>
#include<stdlib.h>

int comp (const void * el1, const void * el2) 
{
    double e1 = *((double*)el1);
    double e2 = *((double*)el2);
    if (e1 > e2) return  1;
    if (e1 < e2) return -1;
    return 0;
}

double Naomi[1000],Ken[1000];

int sort(int N){
    qsort ((void*) Naomi, N, sizeof(double), comp);
    qsort ((void*) Ken, N, sizeof(double), comp);
}

void solve(int N,FILE *g,int num){
    sort(N);
    int i1,i2,j1,j2;
    int score1=0,score2=0;
    //Estrategia War
    for(i1=0,j1=0;j1<N;)
        if(Naomi[i1]<Ken[j1]){
            i1++;j1++;
        }
        else{
            j1++;score1++;
        }
    //Estrategia Deceitful
    for(i1=0,j1=0,j2=N-1;j1<=j2;)
        if(Naomi[i1]>Ken[j1]){
            score2++;
            i1++;
            j1++;
        }
        else{
            i1++;
            j2--;
        }
    fprintf(g,"Case #%d: %d %d\n",num,score2,score1);
}

int main(){
    int i,j,k,T,N;
    FILE *f=fopen("input","r");
    FILE *g=fopen("output","w");
    fscanf(f,"%d",&T);
    for(i=0;i<T;i++){
        fscanf(f,"%d",&N);
        for(j=0;j<N;j++)
            fscanf(f,"%lf",&Naomi[j]);
        for(j=0;j<N;j++)
            fscanf(f,"%lf",&Ken[j]);
        solve(N,g,i+1);
    }
    fclose(f);
    fclose(g);
}
