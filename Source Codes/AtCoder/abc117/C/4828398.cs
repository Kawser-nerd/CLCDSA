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
    static int N, M;
    static int[] X;

    public static void Main(string[] args)
    {
        N = Input.NextInt();
        M = Input.NextInt();

        if (N >= M)
        {
            Console.WriteLine(0);
            return;
        }

        X = Input.LineInt();
        Array.Sort(X);

        var hasamerikazu = N - 1;
        var kankaku = new int[M - 1];

        for (int i = 0; i < kankaku.Length; i++)
            kankaku[i] = X[i + 1] - X[i];

        Array.Sort(kankaku);
        Array.Reverse(kankaku);

        int sum = 0;
        for (int i = hasamerikazu; i < kankaku.Length; i++)
        {
            sum = sum + kankaku[i];
        }

        Console.WriteLine(sum);
    }
}