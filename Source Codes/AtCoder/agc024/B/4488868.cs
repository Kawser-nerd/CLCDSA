using System;
using System.Linq;
using System.Collections.Generic;
public class Test
{
    public static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] p = new int[n + 1];
        for (int i = 0; i < n; i++)
        {
            var tmp = int.Parse(Console.ReadLine());
            p[tmp] = p[tmp - 1] + 1;
        }
        Console.WriteLine(n - p.Max());
    }
}