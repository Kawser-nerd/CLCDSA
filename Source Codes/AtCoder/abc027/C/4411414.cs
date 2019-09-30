using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    public static void Main()
    {
        long N = NextLong();
        int x = (int)Math.Log(N, 2);
        if (x % 2 == 0)
        {
            long n = 1;
            bool t = true;
            while (n <= N)
            {
                if (t) { n = (n * 2) + 1; t = false; }
                else { n *= 2; t = true; }
            }
            if (t) Console.WriteLine("Takahashi");
            else Console.WriteLine("Aoki");
        }
        else
        {
            long n = 1;
            bool t = true;
            while (n <= N)
            {
                if (t) { n *= 2; t = false; }
                else { n = (n * 2) + 1; t = true; }
            }
            if (t) Console.WriteLine("Takahashi");
            else Console.WriteLine("Aoki");
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