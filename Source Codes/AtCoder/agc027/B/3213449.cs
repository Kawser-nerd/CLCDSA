using System.Numerics;
using System;

public class Hello
{
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = long.Parse(line[0]);
        var x = long.Parse(line[1]);
        line = Console.ReadLine().Trim().Split(' ');
        var a = Array.ConvertAll(line, long.Parse);
        var b = new long[n + 1];
        b[1] = a[0];
        for (int i = 2; i <= n; i++)
            b[i] = b[i - 1] + a[i - 1];
        BigInteger res = getAns(b, n, x);
        Console.WriteLine(res);

    }
    public static BigInteger getAns(long[] b, long n, long x)
    {
        BigInteger ans = long.MaxValue;
        for (int i = 1; i <= n; i++)
        {
            BigInteger tsum = 0;
            var p = 0;
            var st = n;
            while (true)
            {
                if (st - i < 0) { tsum += (b[st] - b[0]) * getCo(p); break; }
                else tsum += (b[st] - b[st - i]) * getCo(p);
                st = st - i;
                p++;
            }
            tsum += (n + i) * x;
            ans =BigInteger.Min(ans, tsum);
        }
        return ans;
    }
    public static int getCo(int n) => n == 0 ? 5 : 5 + (n - 1) * 2;
}