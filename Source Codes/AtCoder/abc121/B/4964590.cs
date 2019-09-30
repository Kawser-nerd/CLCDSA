using System;
using System.Diagnostics;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        string[] cin = Console.ReadLine().Split();

        int n = int.Parse(cin[0]);
        int m = int.Parse(cin[1]);
        int c = int.Parse(cin[2]);
        int[] b = Console.ReadLine().Split().Select(t => int.Parse(t)).ToArray();

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int[] a = Console.ReadLine().Split().Select(t => int.Parse(t)).ToArray();
            int tmp = c;
            for (int j = 0; j < m; j++)
            {
                tmp += a[j] * b[j];
            }
            if (0 < tmp) ans++;
        }

        Console.WriteLine(ans);
    }
}