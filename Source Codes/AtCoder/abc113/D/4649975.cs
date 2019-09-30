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
        int H = NextInt();
        int W = NextInt();
        int K = NextInt() - 1;
        int[] dp = new int[W];
        dp[0] = 1;
        for (int row = 0; row < H; row++)
        {
            int[] nxdp = new int[W];

            //bit???
            int M = (int)Math.Pow(2, (W - 1));
            for (int bit = 0; bit < M; bit++)
            {
                bool f = false;
                bool can = true;
                int[] _dp = new int[W];
                for (int i = 0; i < W; i++) _dp[i] = dp[i];
                for (int shift = 0; shift < (W - 1); shift++)
                {

                    if ((1 & bit >> shift) == 1)
                    {
                        if (f) { can = false; break; }
                        _dp[shift + 1] = dp[shift];
                        _dp[shift] = dp[shift + 1];
                        f = true;
                    }
                    else { f = false;}
                }
                if (!can) continue;
                for (int i = 0; i < W; i++)
                {
                    nxdp[i] += _dp[i];
                    nxdp[i] %= INF;
                }
            }
            dp = nxdp;
        }
        Console.WriteLine(dp[K]);
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