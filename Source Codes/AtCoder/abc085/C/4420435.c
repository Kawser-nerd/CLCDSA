#include<stdio.h>
    #include<math.h>
    int main(){
    int N,Y;
    scanf("%d " ,&N);
    scanf("%d" ,&Y);
    double k = Y / 1000;
    double b = k-N;
    double round_x ,round_y ,round_z;
    int answer_x ,answer_y ,answer_z ;
    round_x = floor(b/4);
    round_y = ceil(2*(b)/9);
    round_z = floor(k/5);
     
    if(round_y<=round_x && round_y <= round_z){
         answer_x = b - 4*round_y;
         answer_y = 9*round_y - 2 * b;
         answer_z = k - 5 * round_y;
     
    }else {
        answer_x = -1;
        answer_y = -1;
        answer_z = -1;
    }
    printf("%d %d %d ", answer_x ,answer_y ,answer_z );
    return 0;
    } ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d " ,&N);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d" ,&Y);
     ^