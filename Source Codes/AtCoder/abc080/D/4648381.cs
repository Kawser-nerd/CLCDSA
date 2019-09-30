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
        int C = NextInt();
        int[,] list = new int[C + 1, 2 * 100000 + 10];
        for (int i = 0; i < N; i++)
        {
            int s = NextInt() * 2 - 1;
            int t = NextInt() * 2;
            int c = NextInt();
            list[c, s] = 1;
            list[c, t] = -1;
        }
        for (int i = 1; i <= C; i++)
        {
            for (int j = 1; j <= 2 * 100000; j++) list[i, j] += list[i, j - 1];
        }
        int ans = 0;
        for (int i = 0; i <= 2 * 100000; i++)
        {
            int sc = 0;
            for (int j = 1; j <= C; j++) if (list[j, i] > 0) sc++;
            ans = Math.Max(ans, sc);
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