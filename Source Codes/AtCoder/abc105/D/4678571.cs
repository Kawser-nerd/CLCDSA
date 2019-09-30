using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    private const long INFINITY = 9223372036854775807;
    private static int[] make_cost = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
    public static void Main()
    {
        int N = NextInt();
        int M = NextInt();
        int[] A = LineInt();
        for (int i = 0; i < N; i++) A[i] %= M;
        List<int> B = new List<int>();
        B.Add(0);
        for (int i = 0; i < N; i++) B.Add((B[i] + A[i]) % M);
        B.Sort();
        long ans = 0;
        for (int i = 0; i <= N;)
        {
            int b = B[i];
            long c = 0;
            for (; i <= N; i++)
            {
                if (B[i] != b) break;
                c++;
            }
            ans += c * (c - 1) / 2;
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