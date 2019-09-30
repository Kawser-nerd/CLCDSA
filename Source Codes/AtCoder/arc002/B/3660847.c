#include <stdio.h>
int main(void){
    int y,m,d;
    scanf("%d/%d/%d",&y,&m,&d);
    while(1){
        if (y%(m*d)==0){
            if (d<10 && m<10){
                printf("%d/0%d/0%d\n",y,m,d);
            } else if (d<10){
                printf("%d/%d/0%d\n",y,m,d);
            } else if (m<10){
                printf("%d/0%d/%d\n",y,m,d);
            } else {
                printf("%d/%d/%d\n",y,m,d);
            }
            
            
            
            return 0;
        } else {
            d++;
            if (m==2){
                if (y%400==0){
                    if (d==30){
                        d=1;
                        m++;
                    }
                } else if (y%100==0){
                    if (d==29){
                        d=1;
                        m++;
                    }
                } else if (y%4==0){
                    if (d==30){
                        d=1;
                        m++;
                    }
                } else {
                    if (d==29){
                        d=1;
                        m++;
                    }
                }
            } else if (m==4||m==6||m==9||m==11){
                if (d==31){
                    d=1;
                    m++;
                }
            } else if (m==12){
                if (d==32){
                    d=1;
                    m=1;
                    y++;
                }
            } else {
                if (d==32){
                    d=1;
                    m++;
                }
            }
        }
    }
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d/%d/%d",&y,&m,&d);
     ^