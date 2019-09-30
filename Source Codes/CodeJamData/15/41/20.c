#include <stdio.h>

#define true 1
#define false 0

#define UP      '^'
#define RIGHT   '>'
#define DOWN    'v'
#define LEFT    '<' 
#define NONE    '.'

typedef unsigned char bool;

int r, c;

char mat[110][110];

bool tryUp(int i0, int k0)
{
    int i;
    
    for(i = i0-1; i >= 0; i--)
        if(mat[i][k0] != NONE)
            return true;
    return false;
}

bool tryRight(int i0, int k0)
{
    int k;
    
    for(k = k0+1; k < c; k++)
        if(mat[i0][k] != NONE)
            return true;
    return false;
}

bool tryDown(int i0, int k0)
{
    int i;
    
    for(i = i0+1; i < r; i++)
        if(mat[i][k0] != NONE)
            return true;
    return false;
}

bool tryLeft(int i0, int k0)
{
    int k;
    
    for(k = k0-1; k >= 0; k--)
        if(mat[i0][k] != NONE)
            return true;
    return false;
}

int test(int i, int k)
{
    bool t;

    switch(mat[i][k])
    {
        case UP:
            t = tryUp(i, k);
            if(t) return 0;
            t = tryRight(i, k);
            if(t) return 1;
            t = tryDown(i, k);
            if(t) return 1;
            t = tryLeft(i, k);
            if(t) return 1;
            return -1;
        case RIGHT:
            t = tryRight(i, k);
            if(t) return 0;
            t = tryDown(i, k);
            if(t) return 1;
            t = tryLeft(i, k);
            if(t) return 1;
            t = tryUp(i, k);
            if(t) return 1;
            return -1;
        case DOWN:
            t = tryDown(i, k);
            if(t) return 0;
            t = tryLeft(i, k);
            if(t) return 1;
            t = tryUp(i, k);
            if(t) return 1;
            t = tryRight(i, k);
            if(t) return 1;
            return -1;
        case LEFT:
            t = tryLeft(i, k);
            if(t) return 0;
            t = tryUp(i, k);
            if(t) return 1;
            t = tryRight(i, k);
            if(t) return 1;
            t = tryDown(i, k);
            if(t) return 1;
            return -1;
    }
    
    return -1;
}

int main()
{
    int T, cont = 0;
    scanf("%d\n", &T);
    
    while(T--)
    {
        int i, k;
        int t, sum = 0;
        
        scanf("%d %d\n", &r, &c);
        
        for(i = 0; i < r; i++)
            for(k = 0; k < c; k++)
                scanf("%c\n", &mat[i][k]);
            
        for(i = 0; i < r && sum >= 0; i++)
            for(k = 0; k < c && sum >= 0; k++)
                if(mat[i][k] != NONE)
                {
                    t = test(i, k);
                    sum = (t != -1) ? sum+t : t;
                }
        
        if(sum >= 0)
            printf("Case #%d: %d\n", ++cont, sum);
        else
            printf("Case #%d: IMPOSSIBLE\n", ++cont);
    }
    
    return 0;
}
