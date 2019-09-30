#include <stdio.h>

int max = 400;

int sym(char array[max][max],int n);

int main(int argc, const char * argv[]) {

    int n;
    char net[max][max];
    int ans = 0;
    
    //input
    scanf("%d",&n);
    for(int i = 0; i < n; i ++){
        scanf("%s",net[i]);
    }
    
    
    //calculation
    int a = 0;
    for(int b = 0; b < n ; b ++){
        //for all a and b
        char fix[max][max];
        for(int i = 0; i < n; i++){
            for (int  j = 0; j < n; j ++) {
                //fixed array fix[][]
                int fixa = a;
                if(i+fixa >= n)fixa -= n;
                int fixb = b;
                if(j+fixb >= n)fixb -= n;
                fix[i][j] = net[i+fixa][j+fixb];
            }
        }
        /*
        //print fix array
        printf("\n\n---------------------------\n");
        printf("a : %d       b : %d\n",a,b);
        for(int i = 0; i < n ; i++){
            for (int j = 0; j < n ; j++) {
                printf("%c",fix[i][j]);
            }
            printf("\n");
        }
        printf("---------------------------\n\n");
        */
        
        //wheter symetry or not
        ans += sym(fix,n);
    }
    
    
    //printing answer
    printf("\n%d",ans*n);
    
    return 0;
}

int sym(char array[max][max],int n){
    int count = 0;
    for(int i = 0; i < n ; i++){
        for (int  j = 0; j < i; j ++) {
            if(array[i][j] != array[j][i]){
                count++;
                break;
            }
        }
    }
    
    if(count == 0){
        return 1;
    }else{
        return 0;
    }
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:16:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",net[i]);
         ^