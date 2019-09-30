using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        List<int> L = new List<int>() { Capacity = 2 * N };
        var s = Console.ReadLine().Split(' ');
        for(int i = 0; i < N; i++)
        {
            L.Add(int.Parse(s[2 * i]));
            L.Add(int.Parse(s[2 * i + 1]));
        }
        L.Sort((x, y) => x - y);
        int ctr = 0;
        for (int i = 0; i < N; i++)
            ctr += Math.Min(L[2 * i], L[2 * i + 1]);
        Console.WriteLine(ctr);
    }
}