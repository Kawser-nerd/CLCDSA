//
//  main.c
//  MagicTrick
//
//  Created by Mohamed Saad on 4/12/14.
//  Copyright (c) 2014 Mohamed Saad. All rights reserved.
//

#include <stdio.h>
#include <math.h>

FILE *input;
FILE *output;

int count[1000];
int edges[1000][1000];
int trees[1000];
int visit[1000];

int parseTree(int node)
{
    visit[node] = 1;
    if (count[node] <= 1)
    {
        visit[node] = 0;
        return 1;
    }
    else {
        int sMax = 1;
        int cCount = count[node];
        for (int i=0 ; i< cCount ; i++)
        {
            for (int j=i+1 ; j< cCount ; j++)
            {
                if (i!=j && visit[edges[node][i]]==0 && visit[edges[node][j]]==0)
                {
                    int st1 = parseTree(edges[node][i]);
                    int st2 = parseTree(edges[node][j]);
                    int sCount = st1+st2+1;
                    sMax = (int)fmax(sMax,sCount);
                }
            }
        }
        trees[node] = sMax;
        visit[node] = 0;
        return sMax;
    }
    return 0;
}

void startTestCase(int testCaseNumber)
{
    int n;
    fscanf(input, "%d",&n);
    
    for (int i=0 ; i<n ; i++)
    {
        count[i] = 0;
        visit[i] = 0;
        for (int j=0 ; j<n ; j++)
        {
            edges[i][j] = 0;
        }
    }
    
    for (int i=0 ; i<n-1 ; i++)
    {
        int x,y;
        fscanf(input, "%d %d",&x,&y);
        x--;
        y--;
        
        edges[x][count[x]] = y; count[x]++;
        edges[y][count[y]] = x; count[y]++;
    }
    
    int max = 0;
    for (int i=0 ; i<n ; i++)
    {
        int ts = parseTree(i);
        max = fmax(max, ts);
    }
    
    int removedNodes = n - max;
    
    fprintf(output, "Case #%d: %d\n",testCaseNumber,removedNodes);
}

void start()
{
    input = fopen("a.in", "r");
    output = fopen("a.out", "w");
    
    int testCases = 0;
    fscanf(input, "%d",&testCases);
    for (int i=1 ; i<= testCases ; i++)
    {
        startTestCase(i);
    }
    
    fclose(input);
    fclose(output);
}

int main(int argc, const char * argv[])
{
    start();
    return 0;
}

