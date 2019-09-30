#include <stdio.h>

#define MAX_SIZE 20

struct pattern
{
    int s, w, t;
};

int main()
{
    int case_index, case_count;
    int height, width;
    struct pattern light_grid[MAX_SIZE][MAX_SIZE];
    unsigned int time[2*MAX_SIZE][2*MAX_SIZE];
    int reached[2*MAX_SIZE][2*MAX_SIZE];
    int i, j, next_i, next_j;
    struct pattern *light_p;
    unsigned int temp, temp2;
    int rel_time, s, w, t;
    
    scanf("%d", &case_count);
    for (case_index=1; case_index<=case_count; case_index++)
    {
        scanf("%d %d", &height, &width);
        for (i=0; i<height; i++)
            for (j=0; j<width; j++)
                scanf("%d %d %d", &light_grid[i][j].s, &light_grid[i][j].w, &light_grid[i][j].t);
        for (i=0; i<2*height; i++)
            for (j=0; j<2*width; j++)
            {
                reached[i][j] = 0;
                time[i][j] = ~0;
            }
        
        next_i = 2*height-1;
        next_j = 0;
        time[next_i][next_j] = 0;
        while (next_i != 0 || next_j != 2*width-1)
        {
            i = next_i, j = next_j;
            
            //Walking along side of blocks
            next_i = i%2 ? i+1 : i-1;
            next_j = j%2 ? j+1 : j-1;
            temp = time[i][j] + 2;
            if (next_i>=0 && next_i<2*height && temp<time[next_i][j])
                time[next_i][j] = temp;
            if (next_j>=0 && next_j<2*width && temp < time[i][next_j])
                time[i][next_j] = temp;
            
            //Crossing roads
            next_i = i^1;
            next_j = j^1;
            light_p = &light_grid[i/2][j/2];
            s = light_p->s;
            w = light_p->w;
            t = light_p->t;
            rel_time = ((int)time[i][j] - t) % (s + w);
            if (rel_time < 0)
                rel_time += s + w; //Wouldn't need this with floored division :-(
            if (rel_time < s)
            {
                temp = time[i][j] + 1;
                temp2 = time[i][j] + s - rel_time + 1;
            }
            else
            {
                temp = time[i][j] + s + w - rel_time + 1;
                temp2 = time[i][j] + 1;
            }
            if (next_i>=0 && next_i<2*height && temp < time[next_i][j])
                time[next_i][j] = temp;
            if (next_j>=0 && next_j<2*width && temp2 < time[i][next_j])
                time[i][next_j] = temp2;
            
            reached[i][j] = 1;
            
            temp = ~0;
            for (i=0; i<2*height; i++)
                for (j=0; j<2*width; j++)
                    if (!reached[i][j] && time[i][j] < temp)
                        next_i=i, next_j=j, temp=time[i][j];
        }
        
        printf("Case #%d: %d\n", case_index, time[next_i][next_j]);
    }
    return 0;
}
