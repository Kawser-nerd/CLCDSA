using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] a = Console.ReadLine().Split().Select(i => int.Parse(i)).ToArray();

        int ans = 0;

        for (int i = 0; i < a.Length; i++)
        {
            while (a[i] % 2 == 0)
            {
                a[i] /= 2;
                ans++;
            }
        }

        Console.WriteLine(ans);
    }
}