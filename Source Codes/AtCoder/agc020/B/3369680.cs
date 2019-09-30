using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;

class Solution
{
    static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        int[] a = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
        long l = 2, r = 2;

        for (int i = a.Length - 1; i >= 0; i--)
        {
            if (r / a[i] * a[i] < l)
            {
                Console.WriteLine(-1);
                return;
            }
            l = l % a[i] == 0 ? l : (l / a[i] + 1) * a[i];
            r = r / a[i] * a[i] + a[i] - 1;
        }

        Console.WriteLine($"{l} {r}");
    }
}