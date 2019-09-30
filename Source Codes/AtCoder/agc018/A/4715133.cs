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
        int K = NextInt();
        int[] A = LineInt();
        Array.Sort(A);
        if (A.All(v => v % 2 == 1))
        {
            if (A[N - 1] >= K) { Console.WriteLine("POSSIBLE"); }
            else { Console.WriteLine("IMPOSSIBLE"); }
            return;
        }
        else if (A.All(v => v % 2 == 0))
        {
            long min = A[0];
            for (int i = 1; i < N; i++) min = GCD(min, A[i]);
            bool f = false;
            for (int i = 0; i < N; i++)
            {
                if (A[i] < K) continue;
                if ((A[i] - K) % min == 0) f = true;
            }
            if (f) { Console.WriteLine("POSSIBLE"); }
            else { Console.WriteLine("IMPOSSIBLE"); }
            return;
        }
        else {
            long min = A[0];
            for (int i = 1; i < N; i++) min = GCD(min, A[i]);
            bool f = false;
            for (int i = 0; i < N; i++)
            {
                if (A[i] < K) continue;
                if ((A[i] - K) % min == 0) f = true;
            }
            if (f) { Console.WriteLine("POSSIBLE"); }
            else { Console.WriteLine("IMPOSSIBLE"); }
            return;
        }
    }
    public static long GCD(long a, long b)
    {
        if (a < b) GCD(b, a);
        long d = a % b;
        while (b != 0)
        {
            d = a % b;
            a = b;
            b = d;
        }
        return a;
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