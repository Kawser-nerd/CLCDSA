#include<stdio.h>
char board[10][10];
int main() {
    int t,i,j,c=0,xcnt,ocnt,tcnt,dcnt,res;
    scanf("%d",&t);
    while(t--) {
               for(i=0;i<4;i++)
                               scanf(" %s",board[i]);
               dcnt=res=0;
               //Row check
               for(i=0;i<4;i++) {
                                xcnt=ocnt=tcnt=0;
                                for(j=0;j<4;j++)
                                                if(board[i][j]=='X') xcnt++;
                                                else if(board[i][j]=='O') ocnt++;
                                                else if(board[i][j]=='T') tcnt++;
                                                else dcnt++;
                                if(xcnt+tcnt==4) {
                                                 res=1;
                                                 goto end;
                                }
                                else if(ocnt+tcnt==4) {
                                     res=2;
                                     goto end;
                                }
               }
               //Column check
               for(i=0;i<4;i++) {
                                xcnt=ocnt=tcnt=0;
                                for(j=0;j<4;j++)
                                                if(board[j][i]=='X') xcnt++;
                                                else if(board[j][i]=='O') ocnt++;
                                                else if(board[j][i]=='T') tcnt++;
                                                else dcnt++;
                                if(xcnt+tcnt==4) {
                                                 res=1;
                                                 goto end;
                                }
                                else if(ocnt+tcnt==4) {
                                     res=2;
                                     goto end;
                                }
               }
               //Leading Diagonal check
               xcnt=ocnt=tcnt=0;
               for(i=0;i<4;i++) {
                                if(board[i][i]=='X') xcnt++;
                                else if(board[i][i]=='O') ocnt++;
                                else if(board[i][i]=='T') tcnt++;
                                else dcnt++;
               }
               if(xcnt+tcnt==4) {
                                res=1;
                                goto end;
               }
               else if(ocnt+tcnt==4) {
                                     res=2;
                                     goto end;
               }
               //Trailing Diagonal check
               xcnt=ocnt=tcnt=0;
               for(i=0;i<4;i++) {
                                if(board[i][3-i]=='X') xcnt++;
                                else if(board[i][3-i]=='O') ocnt++;
                                else if(board[i][3-i]=='T') tcnt++;
                                else dcnt++;
               }
               if(xcnt+tcnt==4) {
                                res=1;
                                goto end;
               }
               else if(ocnt+tcnt==4) {
                                     res=2;
                                     goto end;
               }
               if(!dcnt) res=3;
               else res=4;
               end:
                   printf("Case #%d: ",++c);
                   switch(res) {
                               case 1:
                                    printf("X won\n");
                                    break;
                               case 2:
                                    printf("O won\n");
                                    break;
                               case 3:
                                    printf("Draw\n");
                                    break;
                               case 4:
                                    printf("Game has not completed\n");
                                    break;
                   }
    }
    return 0;
}
