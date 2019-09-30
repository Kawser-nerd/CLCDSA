#include<stdio.h>

double GPACalc(int *N, char *str){
    int sum=0;

    for(int i=0; i<*N;i++){
        switch(str[i]){
            case 'A': sum+=4; break;
            case 'B': sum+=3; break;
            case 'C': sum+=2; break;
            case 'D': sum+=1; break;
            default : break;
        }
    }   
return (double)sum/(*N);
}


int main(){
    int UnitNumber;
    char Unitstr[100];
    scanf("%d %s", &UnitNumber, Unitstr);

    printf("%1.15f\n", GPACalc(&UnitNumber, Unitstr));

return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %s", &UnitNumber, Unitstr);
     ^