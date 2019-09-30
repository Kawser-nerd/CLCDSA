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
        int[] p = LineInt();
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            if (i < N - 1 && p[i] == (i + 1))
            {
                int box = p[i];
                p[i] = p[i + 1];
                p[i + 1] = box;
                ans++;
                //Console.WriteLine(i + " swap");
            }
            else if (i != 0 && p[i] == (i + 1))
            {
                int box = p[i];
                p[i] = p[i - 1];
                p[i - 1] = box;
                ans++;
                //Console.WriteLine(i + " swap");
            }
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