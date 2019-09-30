using System;
using System.Linq;
using System.Collections.Generic;

class P
{
    static void Main(string[] _)
    {
        _ = Console.ReadLine().Split(' ');
        int n = int.Parse(_[0]);
        int m = int.Parse(_[1]);
        Int64[] x = new Int64[n];
        Int64[] y = new Int64[m];

        _ = Console.ReadLine().Split(' ');
        for (int i = 0; i < n; i++)
        {
            x[i] = Int64.Parse(_[i]);
        }
        _ = Console.ReadLine().Split(' ');
        for (int i = 0; i < m; i++)
        {
            y[i] = Int64.Parse(_[i]);
        }
        Int64 xx = 0;
        for (int i = 1; i <= n; i++)
        {
            xx += ((i - 1) * x[i - 1] - (n - i) * x[i - 1]);
        }
        Int64 yy = 0;
        for (int i = 1; i <= m; i++)
        {
            yy += ((i - 1) * y[i - 1] - (m - i) * y[i - 1]);
        }

        Console.WriteLine(((xx % 1000000007) * (yy % 1000000007)) % 1000000007);
    }
}