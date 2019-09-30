using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static int N;
    static int T;
    static int A;
    static int[] H;

    public static void Main(string[] args)
    {
        N = Input.NextInt();
        T = Input.NextInt();
        A = Input.NextInt();
        H = Input.LineInt();

        double currMin = double.MaxValue;
        int ans = -1;
        for (int i = 0; i < N; i++)
        {
            var h = H[i];
            var t = T - h * 0.006;
            var dif = Math.Abs(t - A);
            if (currMin > dif)
            {
                ans = i + 1;
                currMin = dif;
            }
        }
        Console.WriteLine(ans);
    }
}

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