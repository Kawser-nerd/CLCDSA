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
        int M = NextInt();
        int Q = NextInt();
        int[,] data = new int[N + 1, N + 1];

        for (int i = 0; i < M; i++)
        {
            int L = NextInt();
            int R = NextInt();
            data[L, R] += 1;
        }

        for (int i = 0; i <= N; i++)
            for (int j = 1; j <= N; j++)
                data[i, j] += data[i, j - 1];
        for (int i = 0; i <= N; i++)
            for (int j = N - 1; j > 0; j--)
                data[j, i] += data[j + 1, i];


        for (int i = 0; i < Q; i++)
        {
            int p = NextInt();
            int q = NextInt();
            Console.WriteLine(data[p, q]);
        }
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