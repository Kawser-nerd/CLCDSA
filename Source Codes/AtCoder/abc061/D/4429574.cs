using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    private const long INFINITY = 100000000000007;
    public static void Main()
    {
        int N = NextInt();
        int M = NextInt();
        //?????????????????????...?
        int[] a = new int[M];
        int[] b = new int[M];
        long[] c = new long[M];
        for (int i = 0; i < M; i++)
        {
            a[i] = NextInt() - 1;
            b[i] = NextInt() - 1;
            c[i] = -NextInt();
        }

        long[] cost = Enumerable.Repeat<long>(INFINITY, N).ToArray();
        cost[0] = 0;
        BellmanFord(cost, a, b, c);
        long ans = -cost[N - 1];
        BellmanFord(cost, a, b, c);
        if (ans == -cost[N - 1]) { Console.WriteLine(ans); }
        else Console.WriteLine("inf");
    }
    private static void BellmanFord(long[] cost, int[] s, int[] g, long[] c)
    {
        for (int i = 0; i < cost.Length; i++)
        {
            for (int j = 0; j < s.Length; j++)
            {
                cost[g[j]] = Math.Min(cost[g[j]], cost[s[j]] + c[j]);
            }
        }
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