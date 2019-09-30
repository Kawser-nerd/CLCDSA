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
        int N = NextInt();
        List<int> a = new List<int>();
        for (int i = 0; i < N; i++) a.Add(NextInt());
        a.Sort();
        int ans_n = a[N - 1];
        a.RemoveAt(N - 1);
        int r = ans_n / 2;
        int sf1 = LessSearch(a, r);
        int sf2 = MoreSearch(a, r);
        int ans_r = 0;
        if (sf1 == -1) ans_r = a[sf2];
        else if (sf2 == N - 1) ans_r = a[sf1];
        else ans_r = (r - a[sf1] < a[sf2] - r ? a[sf1] : a[sf2]);
        Console.WriteLine(ans_n + " " + ans_r);
    }
    private static int MoreSearch(List<int> list, int n)
    {
        int a = 0, b = list.Count();
        if (list[a] >= n) return a;
        else if (list[b - 1] < n) return b;
        while (b - a != 1)
        {
            int x = (a + b) / 2;
            if (list[x] >= n) b = x;
            else a = x;
        }
        return b;
    }
    private static int LessSearch(List<int> list, int n)
    {
        int a = 0, b = list.Count();
        if (list[b - 1] <= n) return b - 1;
        else if (list[a] > n) return -1;
        while (b - a != 1)
        {
            int x = (a + b) / 2;
            if (list[x] <= n) a = x;
            else b = x;
        }
        return a;
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