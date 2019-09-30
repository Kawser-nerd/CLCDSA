using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

class Program
{
    static int[] x;
    static long?[,,] memo;
    static long Solve(int i, int n, int sum)
    {
        if (sum == 0) { return (n == 0) ? 1 : 0; }
        if (i >= x.Length || n == 0) { return 0; }
        if (!memo[i, n, sum].HasValue)
        {
            long count = 0;
            if (sum >= x[i])
            {
                count += Solve(i + 1, n - 1, sum - x[i]);
            }
            count += Solve(i + 1, n, sum);
            memo[i, n, sum] = count;
        }
        return memo[i, n, sum].Value;
    }
    static void Main(string[] args)
    {
        var values = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        int N = values[0];
        int A = values[1];
        x = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
        memo = new long?[N, N + 1, A * N + 1];
        long count = 0;
        for (int i = 1; i <= N; ++i)
        {
            count += Solve(0, i, A * i);
        }
        Console.WriteLine(count);
    }
}