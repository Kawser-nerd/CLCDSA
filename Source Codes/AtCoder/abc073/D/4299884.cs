using System;
using System.Collections.Generic;

class Program
{
    static private int N, M, R;

    static private int INF = 1<<29;
    static private int[,] d = new int[200,200];
    static private int[] r = new int[8];
    static private int A, B, C;
    static private int res;
    static private bool[] used = new bool[8];
    static private void dfs(int c, int las, int dist){
        if(c==R){
            if(res>dist)res=dist;
            return;
        }
        for(int i=0; i<R; i++){
            if(!used[i]){
                used[i] = true;
                if(las == -1)dfs(c+1, i, 0);
                else dfs(c+1, i, dist + d[r[las],r[i]]);
                used[i] = false;
            }
        }
    }

    static void Main(string[] args)
    {
        string[] str = Console.ReadLine().Split(' ');
        N = int.Parse(str[0]);
        M = int.Parse(str[1]);
        R = int.Parse(str[2]);
        for(int i=0; i<N; i++)for(int j=0; j<N; j++)if(i!=j)d[i,j] = INF;
        str = Console.ReadLine().Split(' ');
        for(int i=0; i<R; i++)r[i] = int.Parse(str[i])-1;
        for(int i=0; i<M; i++){
            str = Console.ReadLine().Split(' ');
            A = int.Parse(str[0]);
            B = int.Parse(str[1]);
            C = int.Parse(str[2]);
            if(d[A-1,B-1] > C)d[A-1,B-1] = d[B-1,A-1] = C;
        }
        for(int k=0; k<N; k++){
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    if(d[i,j]>d[i,k]+d[k,j]){
                        d[i,j] = d[i,k]+d[k,j];
                    }
                }
            }
        }
        /* 
        N = 3;
        M = 3;
        R = 3;
        for(int i=1; i<=N; i++)for(int j=1; j<=N; j++)if(i!=j)d[i,j] = INF;
        r = new int[9]{0, 1, 2, 3, 0, 0, 0, 0, 0};
        int[] a = new int[]{1,2,3};
        int[] b = new int[]{2,3,1};
        int[] c = new int[]{1,1,4};
        for(int i=0; i<M; i++){
            if(d[a[i],b[i]] > c[i])d[a[i],b[i]] = c[i];
        }
        for(int k=1; k<=N; k++){
            for(int i = 1; i<=N; i++){
                for(int j=1; j<=N; j++){
                    if(d[i,j]>d[i,k]+d[k,j]){
                        d[i,j] = d[i,k]+d[k,j];
                    }
                }
            }
        }*/
        res = INF;
        dfs(0,-1,0);
        Console.WriteLine("{0}", res);
    }
}