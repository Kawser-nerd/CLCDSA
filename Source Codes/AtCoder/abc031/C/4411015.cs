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
        int[] a = LineInt();
        a.Reverse();
        //N??????????????
        int ans = -INF;
        for (int T = 0; T < N; T++)
        {
            int dA = 0;
            int dAc = -INF;
            for (int A = 0; A < N; A++)
            {
                if (A == T) continue;
                int j = Math.Max(A, T) - Math.Min(A, T) + 1;
                int m = Math.Min(A, T);
                int cost = 0;
                for (int i = 0; i < j; i++)
                {
                    if (i % 2 == 1) cost += a[m + i];
                }
                if (cost > dAc) { dAc = cost; dA = A; }
            }
            int k = Math.Max(dA, T) - Math.Min(dA, T) + 1;
            int o = Math.Min(dA, T);
            int Tc = 0;
            for (int l = 0; l < k; l++)
            {
                if (l % 2 == 0) Tc += a[o + l];
            }
            ans = Math.Max(ans, Tc);
        }
        Console.WriteLine(ans);
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