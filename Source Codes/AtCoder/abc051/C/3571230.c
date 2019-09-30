#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int sx;
    int sy;
    int tx;
    int ty;

    scanf("%d", &sx);
    scanf("%d", &sy);
    scanf("%d", &tx);
    scanf("%d", &ty);
    // Loop 1 x direction//
    if(tx > sx)
    {
        for(int i = 0; i < (tx - sx); i++)
        {
            printf("R");
        }
    }
    else if(tx < sx)
    {
        for(int j = 0; j < sx - tx; j++)
        {
            printf("L");
        }
    }
    // Loop 1 y direction//
    if(ty > sy)
    {
        for(int k = 0; k < (ty - sy); k++)
        {
            printf("U");
        }
    }
    else if(ty < sy)
    {
        for(int l = 0; l < sy - ty; l++)
        {
            printf("D");
        }
    }
    // Loop 1 -x direction//
    if(tx > sx)
    {
        for(int i = 0; i < (tx - sx); i++)
        {
            printf("L");
        }
    }
    else if(tx < sx)
    {
        for(int j = 0; j < sx - tx; j++)
        {
            printf("R");
        }
    }

    //Lopp 1 -y direction
    if(ty > sy)
    {
        for(int k = 0; k < (ty - sy); k++)
        {
            printf("D");
        }
    }
    else if(ty < sy)
    {
        for(int l = 0; l < sy - ty; l++)
        {
            printf("U");
        }
    }
    // Loop 2 Y
    if (tx > sx)
    {
        sx = sx -1;
        printf("L");
    }
    else if(tx < sx)
    {
        sx = sx +1;
        printf("R");
    }

    if(ty > sy)
    {
        for(int k = 0; k < (ty - sy) + 1; k++)
        {
            printf("U");
        }
    }
    else if(ty < sy)
    {
        for(int l = 0; l < sy - ty + 1; l++)
        {
            printf("D");
        }
    }
    // loop2 x dir
    if(tx > sx)
    {
        for(int i = 0; i < (tx - sx ); i++)
        {
            printf("R");
        }
    }
    else if(tx < sx)
    {
        for(int j = 0; j < sx - tx ; j++)
        {
            printf("L");
        }
    }
    if (ty > sy)
    {
        printf("D");
    }
    else if(ty < sy)
    {
        printf("U");
    }
    //resetting coords//

    if (tx > sx)
    {
        sx = sx +1;
    }
    else if(tx < sx)
    {
        sx = sx -1;
    }

    //loop 2 -ve Y

    if (tx > sx)
    {
        sx = sx -1;
        printf("R");
    }
    else if(tx < sx)
    {
        sx = sx +1;
        printf("L");
    }

    if(ty > sy)
    {
        for(int k = 0; k < (ty - sy) + 1; k++)
        {
            printf("D");
        }
    }
    else if(ty < sy)
    {
        for(int l = 0; l < sy - ty + 1; l++)
        {
            printf("U");
        }
    }
    // loop2 -x dir
    if(tx > sx)
    {
        for(int i = 0; i < (tx - sx ); i++)
        {
            printf("L");
        }
    }
    else if(tx < sx)
    {
        for(int j = 0; j < sx - tx ; j++)
        {
            printf("R");
        }
    }
    if (ty > sy)
    {
        printf("U");
    }
    else if(ty < sy)
    {
        printf("D");
    }


    printf("\n");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &sx);
     ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &sy);
     ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &tx);
     ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &ty);
     ^