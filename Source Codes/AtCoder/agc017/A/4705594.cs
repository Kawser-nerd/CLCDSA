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
        int P = NextInt();
        int[] A = LineInt();
        long[,] dp = new long[N + 1, 2];
        dp[0, 0] = 1;
        dp[0, 1] = 0;
        for (int i = 0; i < N; i++)
        {
            //????take?????????
            if (A[i] % 2 == 0)
            {
                dp[i + 1, 0] = dp[i, 0] * 2;
                dp[i + 1, 1] = dp[i, 1] * 2;
            }
            else {
                dp[i + 1, 0] = dp[i, 1] + dp[i, 0];
                dp[i + 1, 1] = dp[i, 1] + dp[i, 0];
            }
        }
        Console.WriteLine(dp[N,P]);
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