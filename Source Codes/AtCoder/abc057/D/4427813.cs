using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    public static void Main()
    {
        int N = NextInt();
        int A = NextInt();
        int B = NextInt();
        long[] v = LineLong();
        Array.Sort(v);
        Array.Reverse(v);
        Dictionary<D, long> d = new Dictionary<D, long>();
        for (int t = A; t <= B; t++)
        {
            long last = v[t - 1];
            long before = A - v.Take(A).Count(_ => _ == last);
            long r = t - before;
            long n = v.Count(_ => _ == last);
            long F = v.Take(t).Sum();
            long S = t;
            //??????????
            bool f = false;
            D test = new D();
            foreach (var dd in d)
            {
                if (dd.Key.First * S == dd.Key.Second * F)
                {
                    //???
                    d[dd.Key] += Combination(n, r);
                    f = true;
                    break;
                }
            }
            if (f) continue;
            test.First = F;
            test.Second = S;
            d[test] = Combination(n, r);
        }
        double ans_A = 0;
        double ans_B = 0;
        foreach (var dd in d)
        {
            double a = (dd.Key.First + .0) / (dd.Key.Second + .0);
            if (a > ans_A)
            {
                ans_A = a;
                ans_B = dd.Value;
            }
        }
        Console.WriteLine(ans_A);
        Console.WriteLine(ans_B.ToString("R"));
    }

    private struct D
    {
        public long First;
        public long Second;
    }

    public static long Combination(long n, long r)
    {
        long comb = 1;
        long oh = 1;
        for (long k = 0; k < r; k++)
        {
            comb *= (n - k);
            oh *= (k + 1);
            if (comb % oh == 0)
            {
                comb /= oh;
                oh = 1;
            }
        }
        return (comb / oh);
    }
}


public class Input
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