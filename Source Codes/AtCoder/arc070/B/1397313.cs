using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class BruteForceSolver
{
    readonly int n, k;
    readonly long[] xs;

    IEnumerable<long> Loop(int j, int i)
    {
        if (i == xs.Length)
        {
            yield return 0L;
        }
        else
        {
            foreach (var sum in Loop(j, i + 1))
            {
                yield return sum;

                if (i != j)
                {
                    yield return sum + xs[i];
                }
            }
        }
    }

    public int Solve()
    {
        var count = 0;

        for (var j = 0; j < xs.Length; j++)
        {
            var ok = true;

            foreach (var sum in Loop(j, 0))
            {
                if (sum + xs[j] < k) continue;
                if (sum < k)
                {
                    ok = false;
                    break;
                }
            }

            if (ok) count++;
        }

        return count;
    }

    public BruteForceSolver(int n, int k, long[] xs)
    {
        this.n = n;
        this.k = k;
        this.xs = xs.ToArray();
    }
}

public class FastSolver
{
    readonly int n, k;
    readonly int[] xs;

    bool[,] Dp1()
    {
        var dp = new bool[n + 1, k + 1];

        dp[0, 0] = true;

        for (var i = 0; i < n; i++)
        {
            for (var s = k; s >= 0; s--)
            {
                dp[i + 1, s] = dp[i + 1, s] || dp[i, s];

                var x = xs[i];
                if (s >= x)
                {
                    dp[i + 1, s] = dp[i + 1, s] || dp[i, s - x];
                }
            }
        }

        return dp;
    }

    bool[,] Dp2()
    {
        var dp = new bool[n + 1, k + 1];

        dp[0, 0] = true;

        for (var i = 0; i < n; i++)
        {
            for (var s = k; s >= 0; s--)
            {
                dp[i + 1, s] = dp[i + 1, s] || dp[i, s];

                var x = xs[n - i - 1];
                if (s >= x)
                {
                    dp[i + 1, s] = dp[i + 1, s] || dp[i, s - x];
                }
            }
        }

        return dp;
    }

    public int Solve()
    {
        // dp1[i, s] = true ? ??? i ???????????????? s ??????????
        var dp1 = Dp1();

        // dp2[i, s] = true ? ???? i ???????????????? s ??????????
        var dp2 = Dp2();

        var count = 0;

        for (var j = 0; j < n; j++)
        {
            // sum[s] = k ?
            // j+1 ??????????????????????s ?????? k ???
            var sum = new int[k + 1];
            for (var s = 0; s <= k; s++)
            {
                sum[s] = (s == 0 ? 0 : sum[s - 1]) + (dp2[n - j - 1, s] ? 1 : 0);
            }

            // ??? j ?????
            // ??? j ??????????? s ??
            // k - a_j ? s ? k ???????????
            var isNecessary = false;

            for (var s = 0; s < k; s++)
            {
                // j ?????????????????????? s ?????????
                // j+1 ?????????????????????? t ??
                // k - a_j ? s + t < k ????????????
                // ??? k - a_j - s ? t ?? t ? k - s - 1 ?????? t ???????
                if (dp1[j, s])
                {
                    var lb = Math.Max(0, k - xs[j] - s);
                    var ub = k - s - 1;
                    if (sum[ub] - (lb == 0 ? 0 : sum[lb - 1]) > 0)
                    {
                        isNecessary = true;
                        break;
                    }
                }
            }

            if (!isNecessary)
            {
                count++;
            }
        }

        return count;
    }

    public FastSolver(int n, int k, long[] xs)
    {
        this.n = n;
        this.k = k;
        this.xs = xs.Select(x => (int)Math.Min(x, k)).OrderBy(x => x).ToArray();
    }
}

public class RandomChecker
{
    public void Run()
    {
        var random = new Random();

        for (var n = 1; n < 20; n++)
        {
            var xs = new long[n];

            for (var k = 1; k < n + 2; k++)
            {
                for (var i = 0; i < xs.Length; i++)
                {
                    xs[i] = random.Next(1, n + 1);
                }

                var bruteForceSolver = new BruteForceSolver(n, k, xs);
                var fastSolver = new FastSolver(n, k, xs);

                var expected = bruteForceSolver.Solve();
                var actual = fastSolver.Solve();
                if (actual != expected)
                {
                    Console.WriteLine("{0} {1}", n, k);
                    Console.WriteLine(string.Join(" ", xs));
                    Console.WriteLine("Expected {0}, actual {1}", expected, actual);
                    bruteForceSolver.Solve();
                    fastSolver.Solve();
                }
            }
        }
    }
}

public class Program
{
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

    int n, k;
    long[] xs;

    void Read()
    {
        var line = ReadLine(int.Parse);
        n = line[0];
        k = line[1];
        xs = ReadLine(long.Parse);
    }

    int Solve()
    {
        return new FastSolver(n, k, xs).Solve();
    }

    public void Run()
    {
        new RandomChecker().Run();

        Read();
        WriteLineOne(Solve());
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