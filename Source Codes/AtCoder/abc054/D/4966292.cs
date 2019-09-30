using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static int N;
    static int Ma, Mb;
    static int[] a;
    static int[] b;
    static int[] c;
    public static void Main(string[] args)
    {
        checked
        {
            N = Input.NextInt();
            Ma = Input.NextInt();
            Mb = Input.NextInt();

            a = new int[N];
            b = new int[N];
            c = new int[N];

            for (int i = 0; i < N; i++)
            {
                var s = Input.LineInt();
                a[i] = s[0];
                b[i] = s[1];
                c[i] = s[2];
            }

            var maxa = a.Sum();
            var maxb = b.Sum();

            DPs = new Dictionary<Tuple<int, int, int>, int>();

            int minCost = BigValue;
            for (int i = 1; ; i++)
            {
                var mma = Ma * i;
                var mmb = Mb * i;
                if (mma > maxa)
                    break;
                if (mmb > maxb)
                    break;

                var cost = DP(N, mma, mmb);
                minCost = Math.Min(minCost, cost);
            }

            if (minCost == BigValue)
                minCost = -1;

            Console.WriteLine(minCost);
        }
    }

    public const int BigValue = int.MaxValue;

    static Dictionary<Tuple<int, int, int>, int> DPs;

    static int DP(int i, int ca, int cb)
    {
        var key = new Tuple<int, int, int>(i, ca, cb);
        if (DPs.ContainsKey(key))
            return DPs[key];

        if (i == 0)
        {
            if (ca == 0 && cb == 0)
                return 0;
            else
                return BigValue;
        }

        int cost1;
        {
            var key1 = new Tuple<int, int, int>(i - 1, ca, cb);
            cost1 = DP(i - 1, ca, cb);
        }

        int cost2;
        {
            var mca = ca - a[i - 1];
            var mcb = cb - b[i - 1];
            if (mca < 0 || mcb < 0)
            {
                cost2 = BigValue;
            }
            else
            {
                var key2 = new Tuple<int, int, int>(i - 1, mca, mcb);
                cost2 = DP(i - 1, mca, mcb);
                if (cost2 != BigValue)
                    cost2 += c[i - 1];
            }
        }

        var cost = Math.Min(cost1, cost2);
        DPs[key] = cost;
        return cost;
    }
}

public class MathLib
{
    /// <summary>
    /// ?????????
    /// </summary>
    /// <param name="a"></param>
    /// <param name="b"></param>
    /// <returns></returns>
    public static long Gcd(long a, long b)
    {
        return (a < b) ? Gcd(b, a)
             : (b > 0) ? Gcd(b, a % b)
                       : a;
    }

    /// <summary>
    /// ?????????
    /// </summary>
    /// <param name="a"></param>
    /// <param name="b"></param>
    /// <returns></returns>
    public static long Lcm(long a, long b)
    {
        return a / Gcd(a, b) * b;
    }

    /// <summary>
    /// ???????????????????<b>??</b>?
    /// </summary>
    /// <param name="n">????????</param>
    /// <returns><paramref name="n"/> ??????</returns>
    public static IEnumerable<int> GetDivisors(int n)
    {
        for (int i = 1; i < (int)Math.Sqrt(n) + 1; i++)
        {
            if ((n % i) == 0)
            {
                yield return i;
                if (i != n / i)
                {
                    yield return n / i;
                }
            }
        }
        yield break;
    }
}

public static class Input
{
    private static Queue<string> q = new Queue<string>();
    private static void Confirm() { if (q.Count == 0) foreach (var s in Console.ReadLine().Split(' ')) q.Enqueue(s); }
    public static int NextInt() { Confirm(); return int.Parse(q.Dequeue()); }
    public static long NextLong() { Confirm(); return long.Parse(q.Dequeue()); }
    public static string NextString() { Confirm(); return q.Dequeue(); }
    public static double NextDouble() { Confirm(); return double.Parse(q.Dequeue()); }
    public static int[] LineInt() { return Console.ReadLine().Split(' ').Select(int.Parse).ToArray(); }
    public static long[] LineLong() { return Console.ReadLine().Split(' ').Select(long.Parse).ToArray(); }
    public static string[] LineString() { return Console.ReadLine().Split(' ').ToArray(); }
    public static double[] LineDouble() { return Console.ReadLine().Split(' ').Select(double.Parse).ToArray(); }
}