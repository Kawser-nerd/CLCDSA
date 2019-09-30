#include <stdio.h>

int main(int argc, char **argv){
    int D,G;
    int i=1;
    scanf("%d%d",&D,&G);
    int p[D];
    int c[D];
    int ANS=1e9;
    int h;
    for(h=0;h<D;h++){
        scanf("%d %d", &p[h], &c[h]);
    }
    for(int a=0;a<(1<<D);a++){
        int score=0,count=0,rest_max=1;
        for(h=0;h<D;h++){
            if(a>>h & 1){
                score+=100*(h+1)*p[h]+c[h];
                count+=p[h];
            }
            else{
                rest_max=h;
            }
        }
        if(score<G){
            int high_score=100*(rest_max + 1);
            int need = (int)(G-score+high_score-1)/high_score;
            if(need>=p[rest_max]){
                continue;
            }
            count+=need;
        }
        if(ANS>count){
            ANS=count;
        }
    }
    printf("%d\n",ANS);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&D,&G);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &p[h], &c[h]);
         ^