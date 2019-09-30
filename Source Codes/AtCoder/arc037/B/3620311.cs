using System;
using System.Collections;
using System.Linq;


public class ARC37
{	
	
    public static int[,] edge;
    public static int[] node;
    public static int cnt = 0;
    public static int N;
	public static void Main()
	{
        string[] str = Console.ReadLine().Split(' ');
        N = int.Parse(str[0]);
        int M = int.Parse(str[1]);
        int ans = 0;

        edge = new int[N,N];
        node = new int[N];
        int a,b;
        for(int i = 0 ; i < M ; i++)
        {
            str = Console.ReadLine().Split(' ');
            a = int.Parse(str[0]) -1;
            b = int.Parse(str[1]) -1;
            edge[a,b] = 1;
            edge[b,a] = 1;
        }
        for(int i = 0 ; i < N ; i++)
        {
            node[i] = -1;
        }

        for(int i = 0 ; i < N ; i++)
        {
            if(node[i] == -1)
            {
                cnt = 1;
                DFS(i,0);
                ans += cnt;
            }
        }
        
        
        Console.WriteLine(ans);
    }
    
    public static void DFS(int index, int prev )
    {
        if(node[index] == 1)
        {
            cnt = 0;
            return;
        }

        node[index] = 1;

        for(int i = 0 ; i < N ; i++)
        {
            if(edge[index,i] == 1 && prev != i)
            {
                DFS(i, index);
            }
        }
    }
}