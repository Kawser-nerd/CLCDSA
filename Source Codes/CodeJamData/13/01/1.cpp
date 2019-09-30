#include <cstdio>
#include <cassert>

bool haswin(char grid[4][5], char player)
{
    for(int y=0; y<4; y++){
        bool good=true;
        for(int x=0; x<4; x++)
        {
            good&=(grid[y][x]==player || grid[y][x]=='T');
        }
        if(good)
            return true;
    }
    for(int x=0; x<4; x++){
        bool good=true;
        for(int y=0; y<4; y++)
        {
            good&=(grid[y][x]==player || grid[y][x]=='T');
        }
        if(good)
            return true;
    }
    {
        bool good=true;
        for(int x=0; x<4; x++)
        {
            good&=(grid[x][x]==player || grid[x][x]=='T');
        }
        if(good)
            return true;
    }
    {
        bool good=true;
        for(int x=0; x<4; x++)
        {
            good&=(grid[3-x][x]==player || grid[3-x][x]=='T');
        }
        if(good)
            return true;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        char grid[4][5];
        for(int i=0; i<4; i++)
        {
            scanf("%s", grid[i]);
        }
        printf("Case #%d: ", t);
        if(haswin(grid, 'O')){
            assert(!haswin(grid, 'X'));
            puts("O won");
        }else{
            if(haswin(grid, 'X'))
                puts("X won");
            else{
                bool done=true;
                for(int y=0; y<4; y++)
                    for(int x=0; x<4; x++)
                        done&=grid[y][x]!='.';
                if(done)
                    puts("Draw");
                else
                    puts("Game has not completed");
            }
        }
    }
}
