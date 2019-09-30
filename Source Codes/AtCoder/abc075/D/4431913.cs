using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    private const long INFINITY = 9223372036854775807;
    public static void Main()
    {
        int N = NextInt();
        int K = NextInt();
        long[] x = new long[N];
        long[] y = new long[N];
        for (int i = 0; i < N; i++)
        {
            x[i] = NextInt();
            y[i] = NextInt();
        }
        long ans = INFINITY;
        for (int x1 = 0; x1 < N; x1++)
            for (int x2 = 0; x2 < N; x2++)
                for (int y1 = 0; y1 < N; y1++)
                    for (int y2 = 0; y2 < N; y2++)
                    {
                        long xl = x[x1], xr = x[x2];
                        long yl = y[y1], yr = y[y2];
                        int count = 0;
                        for (int i = 0; i < N; i++)
                        {
                            if (xl <= x[i] && x[i] <= xr && yl <= y[i] && y[i] <= yr) count++;
                        }
                        if (count >= K)
                        {
                            long rect = (Math.Max(xl, xr) - Math.Min(xl, xr)) *
                                (Math.Max(yl, yr) - Math.Min(yl, yr));
                            ans = Math.Min(ans,rect);
                        }
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