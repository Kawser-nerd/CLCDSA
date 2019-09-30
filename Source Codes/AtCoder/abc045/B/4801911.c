#include <stdio.h>
#include <string.h>
int main(void)
{
    char sa[105],sb[105],sc[105];
    char aa[1]={'a'};
    char bb[1]={'b'};
    char cc[1]={'c'};
    char null[1]={'\0'};
    int a=0, b=0, c=0, turn=0; 
    scanf("%s%s%s", sa, sb, sc);

    while(1)
    {
        if(turn==0)
        {
            if(strncmp(sa+a, null, 1)==0)
            {
                printf("A");
                break;
            }

            if(strncmp(sa+a, aa, 1)==0)
            {
                turn=0;
                a++;
            }
            else if(strncmp(sa+a, bb, 1)==0)
            {
                turn=1;
                a++;
            }
            else if(strncmp(sa+a, cc, 1)==0)
            {
                turn=2;
                a++;
            }
        }
        else if(turn==1)
        {
            if(strncmp(sb+b, null, 1)==0)
            {
                printf("B");
                break;
            }

            if(strncmp(sb+b, aa, 1)==0)
            {
                turn=0;
                b++;
            }
            else if(strncmp(sb+b, bb, 1)==0)
            {
                turn=1;
                b++;
            }
            else if(strncmp(sb+b, cc, 1)==0)
            {
                turn=2;
                b++;
            }

        }
        else if(turn==2)
        {
            if(strncmp(sc+c, null, 1)==0)
            {
                printf("C");
                break;
            }

            if(strncmp(sc+c, aa, 1)==0)
            {
                turn=0;
                c++;
            }
            else if(strncmp(sc+c, bb, 1)==0)
            {
                turn=1;
                c++;
            }
            else if(strncmp(sc+c, cc, 1)==0)
            {
                turn=2;
                c++;
            }
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s%s", sa, sb, sc);
     ^