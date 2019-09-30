using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static int n;
    static void Main()
    {
        n = int.Parse(Console.ReadLine());
        int[] p = new int[n];
        for (int i = 0; i < n; i++)
            p[i] = int.Parse(Console.ReadLine()) - 1;
        int[] ind = new int[n];
        for (int i = 0; i < n; i++)
            ind[p[i]] = i;
        bool[] d = new bool[n - 1];
        for (int i = 1; i < n; i++)
            d[i - 1] = ind[i] > ind[i - 1];
        List<int> l = new List<int>();
        int c = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (!d[i])
            {
                l.Add(c);
                c = 1;
            }
            else
                c++;
        }
        l.Add(c);
        Console.WriteLine(n - l.Max());
    }
}