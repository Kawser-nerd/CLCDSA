#include <stdio.h>

#define MAX_SIZE 100
#define MAX_SINKS 26

int main()
{
    int case_count, case_index;
    int h, w;
    int altitude[MAX_SIZE][MAX_SIZE];
    int sink_count;
    int sink_y[MAX_SINKS], sink_x[MAX_SINKS];
    int i, j, x, y, k, dir, drop;
    
    scanf("%d", &case_count);
    for (case_index=1; case_index<=case_count; case_index++)
    {
        scanf("%d %d", &h, &w);
        for (i=0; i<h; i++)
            for (j=0; j<w; j++)
                scanf("%d", &altitude[i][j]);
        sink_count = 0;
        printf("Case #%d:\n", case_index);
        
        for (i=0; i<h; i++)
        {
            for (j=0; j<w; j++)
            {
                y = i, x = j;
                dir = 1;
                while (dir != 0)
                {
                    dir = 0, drop = 0;
                    if (y > 0 && altitude[y][x] - altitude[y-1][x] > drop)
                        dir = 1, drop = altitude[y][x] - altitude[y-1][x];
                    if (x > 0 && altitude[y][x] - altitude[y][x-1] > drop)
                        dir = 2, drop = altitude[y][x] - altitude[y][x-1];
                    if (x < w-1 && altitude[y][x] - altitude[y][x+1] > drop)
                        dir = 3, drop = altitude[y][x] - altitude[y][x+1];
                    if (y < h-1 && altitude[y][x] - altitude[y+1][x] > drop)
                        dir = 4, drop = altitude[y][x] - altitude[y+1][x];
                    
                    switch (dir)
                    {
                        case 1: y--; break;
                        case 2: x--; break;
                        case 3: x++; break;
                        case 4: y++; break;
                    }
                }
                
                for (k=0; k<sink_count; k++)
                    if (sink_y[k] == y && sink_x[k] == x)
                        break;
                if (k == sink_count)
                    sink_y[k] = y, sink_x[k] = x, sink_count++;
                printf("%c ", 'a'+(char)k);
            }
            printf("\n");
        }
    }
    return 0;
}
