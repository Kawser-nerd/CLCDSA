using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    public static void Main()
    {
        int W = NextInt();
        int H = NextInt();
        //????????
        long ans = 0;
        //(W + H - 2)???????????????????
        long x0 = 1;
        int M = W + H - 2;
        for (int i = 1; i <= M; i++) x0 = (x0 * i) % INF;

        //???
        long x1 = 1;
        for (int i = 1; i < W; i++) x1 = (x1 * i) % INF;
        long x2 = 1;
        for (int i = 1; i < H; i++) x2 = (x2 * i) % INF;

        long ax = (RepPow(x1, INF - 2) % INF) * (RepPow(x2, INF - 2) % INF);
        Console.WriteLine(x0 * (ax%INF) % INF);
    }
    private static long RepPow(long x, long p, long m = 1000000007)
    {
        if (p == 0) return 1;
        if (p % 2 == 0)
        {
            long a = RepPow(x, (p / 2)) % m;
            return a * a % m;
        }
        else { return (x * RepPow(x, p - 1) % m); }
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