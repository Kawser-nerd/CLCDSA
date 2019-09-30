#include<stdio.h>

int uruu(int year);
int get_day(int month,int year);

int main(){
    int y,m,d,end_day;
    int i,j,k,l;

    scanf("%d/%d/%d",&y,&m,&d);

    if(y%m==0 && y/m%d==0){
        printf("%d/%02d/%02d\n",y,m,d);
        return 0;
    }else{ 
        for(i=m;i<=12;i++){
            end_day = get_day(i,y);
            for(j=d;j<=end_day;j++){
                if(y%i==0 && y/i%j==0){
                    printf("%d/%02d/%02d\n",y,i,j);
                    return 0;
                }
            }
            d = 1;
        }
    }
    printf("%d/01/01\n",y+1);
    return 0;
}
int uruu(int year){

    if(year%400==0 || (year%100!=0 && year%4==0)){
        return 0;
    }
        return 1;   
}

int get_day(int month,int year){

    int day;
    switch(month){
        case 2:
            if(uruu(year)==1){
                day = 28;
            }else{ day = 29;}
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            day = 30;
            break;
        default:
            day = 31;
    }
    return day;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d/%d/%d",&y,&m,&d);
     ^