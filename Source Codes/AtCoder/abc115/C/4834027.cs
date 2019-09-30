using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public static class Input
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

class Program
{
    static int N, K;
    static int[] h;

    public static void Main(string[] args)
    {
        N = Input.NextInt();
        K = Input.NextInt();
        h = new int[N];
        for (int i = 0; i < N; i++)
            h[i] = Input.NextInt();

        Array.Sort(h);
        Array.Reverse(h);
        int min = int.MaxValue;
        for (int i = 0; i <= h.Length - K; i++)
        {
             min = Math.Min(min, h[i] - h[i + K - 1]);
        }

        Console.WriteLine(min);
    }
}