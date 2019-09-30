using System;
using System.Collections.Generic;
using System.Linq;
class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        int[] a = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
        long[] sum = new long[n + 1];
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + a[i - 1];
        long ans = long.MaxValue;
        for (int i = 1; i < n; i++)
        {
            long temp = Math.Abs(sum[n] - 2 * sum[i]);
            ans = Math.Min(ans, temp);
        }
        Console.WriteLine(ans);
    }
}