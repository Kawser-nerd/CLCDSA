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
        int K = NextInt();
        HashSet<int> yeah = new HashSet<int>();
        for (int i = 0; i < K; i++) yeah.Add(NextInt());
        for (int i = 1; i < N; i++)
        {
            int[] line = LineInt();
            HashSet<int> next = new HashSet<int>();

            foreach (int a in yeah)
            {
                foreach (int b in line)
                {
                    if (!next.Contains(a ^ b)) next.Add(a ^ b);
                }
            }
            yeah = new HashSet<int>(next);
        }
        Console.WriteLine((yeah.Contains(0) ? "Found" : "Nothing"));

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