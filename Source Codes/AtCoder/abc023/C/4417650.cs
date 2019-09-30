using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    public static void Main()
    {
        int R = NextInt();
        int C = NextInt();
        int K = NextInt();
        int N = NextInt();
        List<int> D1 = Enumerable.Repeat(0, R).ToList();
        List<int> D2 = Enumerable.Repeat(0, C).ToList();
        int[,] data = new int[N, 2];
        for (int i = 0; i < N; i++)
        {
            int r = NextInt() - 1, c = NextInt() - 1;
            data[i, 0] = r;
            data[i, 1] = c;
            D1[r]++;
            D2[c]++;
        }
        Dictionary<int, int> dic1 = new Dictionary<int, int>();
        for (int i = 0; i < 100010; i++) dic1[i] = 0;
        foreach (var d1 in D1) { dic1[d1]++; }
        long ans = 0;
        foreach (var d2 in D2)
        {
            if (K - d2 >= 0) ans += dic1[K - d2];
        }

        for (int i = 0; i < N; i++)
        {
            int r = data[i, 0];
            int c = data[i, 1];
            int box = D1[r] + D2[c];
            if (box == K) ans--;
            else if (box == K + 1) ans++;
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