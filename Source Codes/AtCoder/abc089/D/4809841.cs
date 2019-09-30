using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    private const long INFINITY = 9223372036854775807;
    private struct Pair { public int x, y; }
    public static void Main()
    {
        //input
        int H = NextInt();
        int W = NextInt();
        int D = NextInt();
        Pair[] pos = new Pair[H * W + 1];
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                int n = NextInt();
                pos[n].x = j;
                pos[n].y = i;
            }
        }

        int M = H * W;
        int[] dp = new int[M + 1];
        dp[0] = 0;
        for (int i = D + 1; i <= M; i++)
        {
            dp[i] = dp[i - D] + Math.Abs(pos[i].x - pos[i - D].x) + Math.Abs(pos[i].y - pos[i - D].y);
        }

        int Q = NextInt();

        for (int i = 0; i < Q; i++)
        {
            int L = NextInt();
            int R = NextInt();
            Console.WriteLine(dp[R] - dp[L]);
        }
    }
}

public class Input
{
    private static Queue<string> q = new Queue<string>();
    private static void Confirm() { if (q.Count == 0) foreach (var s in Console.ReadLine().Split(' ')) q.Enqueue(s); }
    public static int NextInt() { Confirm(); return int.Parse(q.Dequeue()); }
    public static long NextLong() { Confirm(); return long.Parse(q.Dequeue()); }
    public static char NextChar() { Confirm(); return char.Parse(q.Dequeue()); }
    public static string NextString() { Confirm(); return q.Dequeue(); }
    public static double NextDouble() { Confirm(); return double.Parse(q.Dequeue()); }
    public static int[] LineInt() { return Console.ReadLine().Split(' ').Select(int.Parse).ToArray(); }
    public static long[] LineLong() { return Console.ReadLine().Split(' ').Select(long.Parse).ToArray(); }
    public static string[] LineString() { return Console.ReadLine().Split(' ').ToArray(); }
    public static double[] LineDouble() { return Console.ReadLine().Split(' ').Select(double.Parse).ToArray(); }
}