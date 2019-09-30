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
        if (N == 3) { Console.WriteLine(61); return; }
        int[,,,] dp = new int[110, 4, 4, 4];
        dp[0, 3, 3, 3] = 1;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++)
                    for (int l = 0; l < 4; l++)
                        for (int n = 0; n < 4; n++)
                        {
                            if (n == 2 && j == 1 && k == 0) continue;
                            if (n == 2 && j == 0 && k == 1) continue;
                            if (n == 1 && j == 2 && k == 0) continue;
                            if (n == 2 && j == 1 && l == 0) continue;
                            if (n == 2 && k == 1 && l == 0) continue;
                            dp[i + 1, n, j, k] += dp[i, j, k, l];
                            dp[i + 1, n, j, k] %= INF;
                        }
        long ans = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++)
                {
                    ans += dp[N, i, j, k];
                    ans %= INF;
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