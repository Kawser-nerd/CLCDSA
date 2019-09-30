using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class FactorialFunction
{
    readonly long[] dp;
    readonly long[] inv;

    public static long Power(long x, int n, int mod)
    {
        var y = 1L;
        while (n > 0)
        {
            if (n % 2 == 0)
            {
                x = (x * x) % mod;
                n /= 2;
            }
            else
            {
                y = (y * x) % mod;
                n--;
            }
        }
        return y;
    }

    public long Invoke(int n)
    {
        return dp[n];
    }

    public long Inverse(int n)
    {
        return inv[n];
    }

    public FactorialFunction(int m, int mod)
    {
        dp = new long[m + 1];
        inv = new long[m + 1];

        for (var i = 0; i <= m; i++)
        {
            dp[i] = (i == 0 ? 1 : (dp[i - 1] * i) % mod);
            inv[i] = Power(dp[i], mod - 2, mod);
        }
    }
}

public class CombinationFunction
{
    readonly int mod;
    readonly FactorialFunction fact;

    public long Invoke(int n, int k)
    {
        if (k == 0 || n == k) return 1;
        if (k > n) return 0;

        var c = fact.Invoke(n);
        c = (c * fact.Inverse(n - k)) % mod;
        c = (c * fact.Inverse(k)) % mod;
        return c;
    }

    public CombinationFunction(int n, int mod)
    {
        this.mod = mod;
        fact = new FactorialFunction(n, mod);
    }
}

public class Program
{
    public const int Mod = 1000000007;

    #region Standard I/O
    readonly TextReader input;
    readonly TextWriter output;

    X[] ReadLine<X>(Func<string, X> func)
    {
        return input.ReadLine().Split(' ').Select(func).ToArray();
    }

    void WriteLineOne(object obj)
    {
        output.WriteLine("{0}", obj);
    }

    void WriteLineMany(params object[] objects)
    {
        output.WriteLine(string.Join(" ", objects.Select(obj => obj.ToString())));
    }
    #endregion

    int n;
    long[] xs;

    void Read()
    {
        n = ReadLine(int.Parse)[0];
        xs = ReadLine(long.Parse);
    }

    IEnumerable<long> Solve()
    {
        yield return n;

        var combination = new CombinationFunction(n, Mod);

        // ?? n+1 ???? n ?????1??????????????
        // ????1?????2??????
        // ??????????3? (P, Q, R) ????????????? p, q, r ????
        var p = default(int);
        var q = default(int);
        var r = default(int);
        {
            // ?? i ? ys[i] ???????????
            var ys = Enumerable.Repeat(-1, n + 2).ToArray();
            for (var i = 0; i <= n; i++)
            {
                var j = ys[xs[i]];
                if (j == -1)
                {
                    ys[xs[i]] = i;
                }
                else
                {
                    p = j;
                    q = i - j - 1;
                    r = (n + 1) - i - 1;
                    break;
                }
            }
        }

        for (var k = 2; k <= n; k++)
        {
            // ????????????????
            // PQR
            var c = 0L;

            c = combination.Invoke(p + q + r, k);
            // ???????1???????????
            // P1QR + PQ1R - P1R
            c = (c + combination.Invoke(p + q + r, k - 1)) % Mod;
            c = (c + combination.Invoke(p + q + r, k - 1)) % Mod;
            c = (((c - combination.Invoke(p + r, k - 1)) % Mod) + Mod) % Mod;
            // ???????2?????????
            // P1Q1R
            c = (c + combination.Invoke(p + q + r, k - 2)) % Mod;
            yield return c;
        }

        yield return 1;
    }

    public void Run()
    {
        Read();

        foreach (var c in Solve())
        {
            WriteLineOne(c);
        }
    }

    public Program(TextReader input, TextWriter output)
    {
        this.input = input;
        this.output = output;
    }

    public static void Main(string[] args)
    {
        new Program(Console.In, Console.Out).Run();
    }
}