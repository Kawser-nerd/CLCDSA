using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;


public class ARC54
{	
    public static bool[,] edge;
    public static bool[] node;
    public static int cnt = 0;
    public static bool ok = false;
	public static void Main()
	{
        string[] str = Console.ReadLine().Split(' ');
        int N = int.Parse(str[0]);
        int M = int.Parse(str[1]);
        int ans = 0;

        edge = new bool[N,N];
        node = new bool[N];
        int a,b;
        for(int i = 0 ; i < M ; i++)
        {
            str = Console.ReadLine().Split(' ');
            a = int.Parse(str[0]) -1;
            b = int.Parse(str[1]) -1;
            edge[a,b] = true;
            edge[b,a] = true;
        }
        
        node[0] = true;
        DFS(0,node);
        
        
        Console.WriteLine(cnt);
    }
    
    public static void DFS(int index, bool[] node)
    {
        ok = true;
        for(int i = 0 ; i < node.Length ; i ++)
        {
            if(!node[i]) ok = false;
        }
        // Console.WriteLine("index = " + index + " ok = " + ok);
        if(ok) cnt++;

        for(int i = 0 ; i < edge.GetLength(0) ; i++)
        {
            if(edge[index,i]) 
            {
                if(!node[i]){
                    node[i] = true;
                    DFS(i, node);
                    node[i] = false;
                }
            }
        }
    }
}