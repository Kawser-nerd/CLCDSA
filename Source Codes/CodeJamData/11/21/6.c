#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
char table[200][200];
int wp[200][2];
double owp[200],oowp[200];
void WP();
void OWP();
void OOWP();
int main(){
    int Case,t;
    int i,j;
    scanf("%d",&Case);
    for(t=1;t<=Case;++t){
        scanf("%d",&n);
        for(i=0;i<n;++i){
            scanf(" %s",table[i]);
        }
        WP();
        OWP();
        OOWP();
        printf("Case #%d:\n",t);
        for(i=0;i<n;++i){
            printf("%lf\n",0.25*(double)(wp[i][0])/(double)(wp[i][1]) + 0.5*owp[i] + 0.25 *oowp[i]);
        }
    }

    return 0;
}
void WP(){
    int up = 0;
    int down = 0;
    int i,j;
    for(i=0;i<n;++i){
        up = down = 0;
        for(j=0;j<n;++j){
            if(table[i][j] == '1'){
                ++up;
                ++down;
            }else if(table[i][j] == '0'){
                ++down;
            }
        }
        wp[i][0] = up;
        wp[i][1] = down;
    }
}
void OWP(){
    int i,j;
    int up,down;
    double temp;
    int num;
    for(i=0;i<n;++i){
        temp = 0;
        num = 0;
        for(j=0;j<n;++j){
            if(table[i][j]=='1'){
                temp += (double)(wp[j][0])/(double)(wp[j][1]-1);
                num++;
            }else if(table[i][j]=='0'){
                temp += (double)(wp[j][0]-1)/(double)(wp[j][1]-1);
                num++;
            }
        }
        owp[i] = temp/(double)(num);
    }
}
void OOWP(int NO){
    int i,j;
    double temp;
    int num;
    for(i=0;i<n;++i){
        temp = 0;
        num = 0;
        for(j=0;j<n;++j){
            if(table[i][j]!='.'){
                temp += owp[j];
                num++;
            }
        }
        oowp[i] = temp / (double)(num);
    }


}
