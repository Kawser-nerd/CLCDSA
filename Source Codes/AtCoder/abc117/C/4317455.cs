using System;
using System.Collections;
using System.Collections.Generic;

class Program
{
    public static void Main()
    {
        string[] sa = Console.ReadLine().Split(' ');
        int N = int.Parse(sa[0]);
        int M = int.Parse(sa[1]);
        sa = Console.ReadLine().Split(' ');
        int[] V = new int[M];

        for (int i = 0; i < M; i++)
            V[i] = int.Parse(sa[i]);

        Array.Sort(V);
        
        int[] D = new int[M];
        D[0] = 0;
        for (int i = 1; i < M ; i++)
            D[i] = V[i] - V[i - 1];
        
        Array.Sort(D);

        int s = 0;
        for (int i = 0; i < M - N; i++)
            s += D[i + 1];

        Console.WriteLine(s);
    }
}