using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        string[] input = Console.ReadLine().Split();
        int N = int.Parse(input[0]);
        int Z = int.Parse(input[1]);
        int W = int.Parse(input[2]);

        int[] a = new int[N];
        string[] aInput = Console.ReadLine().Split();
        for (int i = 0; i < N; i++) a[i] = int.Parse(aInput[i]);

        int now = Math.Abs(W - a[N - 1]);
        if (N == 1) Console.WriteLine(now);
        else
        {
            int next = Math.Abs(a[N - 1] - a[N - 2]);
            Console.WriteLine(Math.Max(now, next));
        }

        Console.ReadLine();
    }
}