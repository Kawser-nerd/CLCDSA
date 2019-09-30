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
        int[] A = LineInt();
        Array.Sort(A);
        HashSet<int> hash = new HashSet<int>();
        for (int i = 0; i < N; i++)
        {
            if (A[i] % 2 == 1) { hash.Add(A[i]); continue; }
            int a = A[i];
            while (a % 2 == 0) a /= 2;
            if (!hash.Contains(a)) hash.Add(a);
        }
        Console.WriteLine(hash.Count());
    }
}

public class Input
{
    private static Queue<string> queue = new Queue<string>();
    private static void Confirm() { if (queue.Count == 0) foreach (var s in Console.ReadLine().Split(' ')) queue.Enqueue(s); }
    public static int NextInt() { Confirm(); return int.Parse(queue.Dequeue()); }
    public static long NextLong() { Confirm(); return long.Parse(queue.Dequeue()); }
    public static string NextString() { Confirm(); return queue.Dequeue(); }
    public static double NextDouble() { Confirm(); return double.Parse(queue.Dequeue()); }
    public static int[] LineInt() { return Console.ReadLine().Split(' ').Select(int.Parse).ToArray(); }
    public static long[] LineLong() { return Console.ReadLine().Split(' ').Select(long.Parse).ToArray(); }
    public static string[] LineString() { return Console.ReadLine().Split(' ').ToArray(); }
    public static double[] LineDouble() { return Console.ReadLine().Split(' ').Select(double.Parse).ToArray(); }
}