#include <stdio.h>

int usercode(char letter) {
        return (letter-'a');
}


int main(void) {
        char stra[101];
        char strb[101];
        char strc[101];
        char* str[3] = {stra,strb,strc};
        //init str
        for (int i=0;i<101;i++) {
                stra[i] = 0;
                strb[i] = 0;
                strc[i] = 0;
        }
        //read
        scanf("%101s",stra);
        scanf("%101s",strb);
        scanf("%101s",strc);
        //count cards
        int num[3];
        for (int i=0;i<3;i++) {
                num[i] = 0;
                for (int j=0;j<100;j++) {
                        if (str[i][j]) num[i]++;
                }
        }
        //let the game commence
        int indexr[3];
        for (int i=0;i<3;i++) indexr[i]=0;
        int user = usercode('a');
        while(1) {
                if (indexr[user] == num[user]) break;
                indexr[user]++;
                user = usercode(str[user][indexr[user]-1]);
        }
        printf("%c\n", user+'A');

        return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%101s",stra);
         ^
./Main.c:21:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%101s",strb);
         ^
./Main.c:22:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%101s",strc);
         ^