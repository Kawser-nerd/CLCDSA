#include <stdio.h>
    double p[100][4];
int cmp(const void * d1, const void * d2){
    int x = *((int*)d1);
    int y = *((int*)d2);
    double r1 = p[x][1]/p[x][0];
    double r2 = p[y][1]/p[y][0];
    if(r1 > r2)return -1;
    else if(r2>r1)return 1;
    else return 0;
}
int cmp2(const void * d1, const void * d2){
    double r1 = *((double*)d1);
    double r2 = *((double*)d2);
    if(r1 > r2)return -1;
    else if(r2>r1)return 1;
    else return 0;
}
double rats[100000000];
    int second[100000];
int I;
int Q;
void doit(int idx, double sofar){
    if(idx == 13 || idx == Q){
        //printf("%d %lf\n",I,sofar);
        rats[I++] = sofar;
        return;
    }
    doit(idx+1,sofar*p[second[idx]][0]);
    doit(idx+1,sofar*p[second[idx]][1]);
    doit(idx+1,sofar*p[second[idx]][2]);
    doit(idx+1,sofar*p[second[idx]][3]);
}
int main(){
    int i, j, k, C, M,l;
    scanf("%d",&C);
    for(i = 1; i<=C; i++){
        int ptr = 0;
        scanf("%d%d",&M,&Q);
        double best = 1;
        for(j = 0; j<Q; j++){
            for(k = 0; k<4; k++){
                scanf("%lf",&p[j][k]);
            }
            for(k = 0; k<4; k++){
                for(l = 0; l<k; l++){
                    if(p[j][k] > p[j][l]){
                        double t = p[j][k];
                        p[j][k] = p[j][l];
                        p[j][l] = t;
                    }
                }
            }
            //printf("%lf\n",p[j][0]);
            best *= p[j][0];
            second[ptr++] = j;
            //second[ptr++] = p[j][2] / p[j][0];
            //second[ptr++] = p[j][3] / p[j][0];
        }
        qsort(second,ptr,sizeof(int),cmp);
        //printf("%d ",second[0]);
        //printf("%d\n",second[1]);
        //printf("%lf\n",p[1][1]);
        I = 0;
        doit(0,1);
        qsort(rats,I,sizeof(double),cmp2);
        //printf("%lf %lf %lf\n",rats[0],rats[1],rats[2]);
        double sum = 0;
        for(j = 0; j<M && j < I; j++){
            sum += rats[j];
        }
        printf("Case #%d: %lf\n",i,sum);
    }
}
