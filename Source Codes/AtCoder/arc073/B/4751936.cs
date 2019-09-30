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
        //w1??3?????????
        int N = NextInt();
        long W = NextLong();
        long[] w = new long[N];
        int[] v = new int[N];
        long w1 = NextInt();
        w[0] = 0;
        v[0] = NextInt();
        for (int i = 1; i < N; i++)
        {
            w[i] = NextInt() - w1;
            v[i] = NextInt();
        }
        // i ????????? , ??? , w1?????????????
        long[,,] dp = new long[N + 1, N + 1, 500];
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= N; j++)
                for (int k = 0; k < 500; k++) dp[i, j, k] = -INF;
        dp[0, 0, 0] = 0;

        for (int i = 0; i < N; i++)
            for (int j = N; j != -1; j--)
                for (int k = 400; k != -1; k--)
                {
                    if (dp[i, j, k] == -INF) continue;
                    dp[i + 1, j, k] = dp[i, j, k];
                    //??j???????? = k
                    if ((j + 1) * w1 + k + w[i] > W) continue;
                    dp[i + 1, j + 1, k + w[i]] = Math.Max(dp[i, j + 1, k + w[i]], dp[i + 1, j, k] + v[i]);
                }

        long ans = 0;
        for (int j = 0; j <= N; j++)
            for (int k = 0; k < 500; k++) ans = Math.Max(dp[N, j, k], ans);
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