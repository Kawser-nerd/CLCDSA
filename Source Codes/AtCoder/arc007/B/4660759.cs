using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    public static void Main()
    {
        int N, M;
        string[] str = Console.ReadLine().Split(' ');
        N = int.Parse(str[0]);
        M = int.Parse(str[1]);
        int[] L = new int[N];
        for (int i = 0; i < N; i++)
            L[i] = i + 1;
        int run = 0;
        for(int i = 0; i < M; i++)
        {
            int t = int.Parse(Console.ReadLine());
            for (int j = 0; j < N; j++)
            {
                if (L[j]==t)
                {
                    L[j] = run;
                    run = t;
                    break;
                }
            }
        }
        for (int i = 0; i < N; i++)
            Console.WriteLine(L[i]);
    }
}