#include <stdio.h>
int N = 10;
int main(void){
    int i,j=0,counter=0,max=0,check=0;
    char a[N];
    scanf("%s",&a);
    
    for(i=0;i<N;i++){
        j = i;
        while(check == 0){
            if(a[j] == 'A' || a[j] == 'T' || a[j] == 'G' || a[j] == 'C') counter++;
            else check = 1;
            j++;
        }
        if(counter>max) max = counter;
        check = 0;
        counter = 0;
    }
    
    printf("%d",max);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[(sizetype)(N)]’ [-Wformat=]
     scanf("%s",&a);
           ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&a);
     ^