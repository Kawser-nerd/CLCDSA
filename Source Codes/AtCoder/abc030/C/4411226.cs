using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    public static void Main()
    {
        int N = NextInt();
        int M = NextInt();
        int X = NextInt();
        int Y = NextInt();
        int[] a = LineInt();
        List<int> ai = a.ToList();
        a = LineInt();
        List<int> bi = a.ToList();

        int now = 0;
        int ans = 0;
        bool air_a = true;
        while (true)
        {
            if (air_a)
            {
                //A?????
                int x = MoreSearch(ai, now);
                if (x == N) break;
                now = ai[x] + X;
                air_a = false;
            }
            else
            {
                int x = MoreSearch(bi, now);
                if (x == M) break;
                now = bi[x] + Y;
                ans += 1;
                air_a = true;
            }
        }
        Console.WriteLine(ans);
    }
    private static int MoreSearch(List<int> list, long n)
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