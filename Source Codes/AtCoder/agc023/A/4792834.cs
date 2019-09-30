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
        //input
        int N = NextInt();
        long[] A = LineLong();
        for (int i = 1; i < N; i++) A[i] += A[i - 1];
        Dictionary<long, long> dic = new Dictionary<long, long>();
        for (int i = 0; i < N; i++)
        {
            if (!dic.ContainsKey(A[i])) dic[A[i]] = 0;
            dic[A[i]]++;
        }
        if (dic.ContainsKey(0)) dic[0]++;
        long ans = 0;
        foreach (var d in dic)
        {
            if (d.Value < 2) continue;
            ans += d.Value  * (d.Value - 1) / 2;
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
    public static char NextChar() { Confirm(); return char.Parse(q.Dequeue()); }
    public static string NextString() { Confirm(); return q.Dequeue(); }
    public static double NextDouble() { Confirm(); return double.Parse(q.Dequeue()); }
    public static int[] LineInt() { return Console.ReadLine().Split(' ').Select(int.Parse).ToArray(); }
    public static long[] LineLong() { return Console.ReadLine().Split(' ').Select(long.Parse).ToArray(); }
    public static string[] LineString() { return Console.ReadLine().Split(' ').ToArray(); }
    public static double[] LineDouble() { return Console.ReadLine().Split(' ').Select(double.Parse).ToArray(); }
}