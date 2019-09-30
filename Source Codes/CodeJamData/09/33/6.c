#include <stdio.h>

enum constraints
{
    MAX_Q = 8,
    MAX_P = 128
};

int P, Q;
char used[MAX_Q];
short pos[MAX_Q];
char cells[MAX_P];

short price(int idx)
{
    int i, price;
    
    for(i=idx+1; cells[i]; i++) ;
    price = i-idx-1;
    
    for(i=idx-1; cells[i]; i--) ;
    price += idx-i-1;
    
    return price;
}

short rec(char cnt)
{
    char i;
    short best, curr;

    if(cnt == 0)
    {
        return 0;
    }
    
    best = 0x7FFF;
    for(i=0; i<Q; i++)
    {
        if(!used[i])
        {
            used[i] = 1;
            cells[pos[i]] = 0;
            
            curr = rec(cnt-1) + price(pos[i]);
            
            cells[pos[i]] = 1;
            used[i] = 0;
            
            if(curr < best)
            {
                best = curr;
            }
        }
    }
    
    return best;
}

void input(void)
{
    int i;
    
    scanf("%d %d", &P, &Q);
    for(i=0; i<Q; ++i)
    {
        scanf("%d", &pos[i]);
    }
}

int main(void)
{
    int test, T;
    
    memset(cells, 1, sizeof cells);
    cells[0] = 0;
    
    scanf("%d", &T);
    for(test=1; test<=T; ++test)
    {
        input();
        cells[P+1] = 0;
        printf("Case #%d: %hd\n", test, rec(Q));
        cells[P+1] = 1;
    }
    return 0;
}
