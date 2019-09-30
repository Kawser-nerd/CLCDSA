using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        string[]strs = Console.ReadLine().Split(' ');
        List<int> L = new List<int>() { Capacity = N };
        foreach (var i in strs)
            L.Add(int.Parse(i));
        L.Sort();
        int min = int.MaxValue;
        for(int i = L[0]; i <= L[N - 1]; i++)
        {
            int s = 0;
            foreach (var j in L)
                s += (j - i)* (j - i);
            min = Math.Min(min, s);
        }
        Console.WriteLine(min);
    }
}