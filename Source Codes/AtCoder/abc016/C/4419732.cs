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
        List<int>[] wf = new List<int>[N];
        for (int i = 0; i < N; i++) wf[i] = Enumerable.Repeat(INF, N).ToList();
        for (int i = 0; i < N; i++) wf[i][i] = 0;
        for (int i = 0; i < M; i++)
        {
            int a = NextInt() - 1, b = NextInt() - 1;
            wf[a][b] = 1;
            wf[b][a] = 1;
        }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    wf[j][k] = Math.Min(wf[j][k], wf[j][i] + wf[i][k]);
        for (int i = 0; i < N; i++) {
            int ans = 0;
            for (int j = 0; j < N; j++) {
                if (wf[i][j] == 2) ans++;
            }
            Console.WriteLine(ans);
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