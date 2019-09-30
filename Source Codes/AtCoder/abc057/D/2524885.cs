using System.Collections.Generic;
using System.Linq;
using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var a = int.Parse(line[1]);
        var b = int.Parse(line[2]);
        line = Console.ReadLine().Trim().Split(' ');
        var w = Array.ConvertAll(line, long.Parse);
        var ret1 = (decimal)w.OrderByDescending(x => x).Take(a).Average();
        Console.WriteLine("{0:0.000000}", ret1);
        var d = new Dictionary<long, int>();
        for (int i = 0; i < n; i++)
            if (d.ContainsKey(w[i])) d[w[i]]++;
            else d[w[i]] = 1;
        var w2 = d.OrderByDescending(x => x.Key).Select(x => x.Value).ToArray();
        var ret2 = getAns2(w2, a, b);
        Console.WriteLine(ret2);
    }
    public static long getAns2 (int[] w , int a , int b)
    {
        
        var ret = 0L;
        var w0 = w[0];
        if (a == w0) return 1;
        if (a < w0)
        {
            var imax = Math.Min(b, w0);
            for (int i = a; i <= imax; i++)
                ret += Combi(w0, i);
            return ret;
        }
        else
        {
            var aa = a;
            var p = 0;
            while (true)
            {
                if (aa - w[p] > 0) { aa -= w[p]; p++; }
                else if (aa - w[p] < 0) return Combi(w[p], aa);
                else return 1;
            }
        }
    }
    public static long Combi(int n, int r)
    {
        if (n < 2 * r) r = n - r;
        var dp = new long[n + 1, r + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= r; j++)
                if (i == j | j == 0) dp[i, j] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= r; j++)
                dp[i, j] = dp[i - 1, j] + dp[i - 1, j - 1];
        return dp[n, r];
    }
}