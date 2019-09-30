using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    public static void Main()
    {
        string[] fs = Console.ReadLine().Split(' ');
        int N = int.Parse(fs[0]);
        int K = int.Parse(fs[1]);

        int[] h = new int[N];

        for (int i = 0; i < N; i++)
            h[i] = int.Parse(Console.ReadLine());

        Array.Sort(h);

        int min = int.MaxValue;
        for (int i = 0; i <= N - K; i++)
            min = Math.Min(min, h[i + K - 1] - h[i]);
        Console.WriteLine(min);
    }
}