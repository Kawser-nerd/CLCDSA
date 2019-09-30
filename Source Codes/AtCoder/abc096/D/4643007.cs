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
        SieveOfEratosthenes sieve = new SieveOfEratosthenes(55555);
        sieve.Run();
        foreach (var v in sieve.list)
        {
            if (v % 5 == 2)
            {
                Console.Write(v + " ");
                N--;
            }
            if (N == 0) break;
        }
        Console.WriteLine();
    }
}
public class SieveOfEratosthenes
{
    public HashSet<int> list { get; private set; } = new HashSet<int>();
    private static bool[] memo;
    private int M, root;
    public SieveOfEratosthenes(int N)
    {
        M = (int)Math.Ceiling((double)N / 2);
        root = (int)Math.Ceiling((Math.Sqrt(N) + .1)) / 2;
        memo = new bool[M];
    }
    public void Run()
    {
        memo[0] = false;
        for (int i = 1; i < M; i++) memo[i] = true;
        list.Add(2);
        for (int i = 1; i < root; i++)
        {
            if (!memo[i]) continue;
            for (int j = 2 * i * (i + 1); j < M; j += (2 * i + 1)) memo[j] = false;
        }
        for (int i = 0; i < M; i++) if (memo[i]) list.Add(i * 2 + 1);
    }
    public bool IsPrime(int N)
    {
        return list.Contains(N);
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