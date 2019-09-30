using System;
using System.Collections.Generic;
using System.Linq;
using static Input;

public class Prog
{
    private const int INF = 1000000007;
    public static void Main()
    {
        int N = Cin<int>();
        SieveOfEratosthenes soe = new SieveOfEratosthenes(1000010);
        soe.Run();
        Console.WriteLine(soe.IsPrime(N) ? "YES" : "NO");
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
    private static Queue<string> queue = new Queue<string>();
    public static T Cin<T>()
    {
        if (queue.Count == 0) foreach (var s in Console.ReadLine().Split(' ')) queue.Enqueue(s);
        if (typeof(T) == typeof(int)) return (T)(object)int.Parse(queue.Dequeue());
        else if (typeof(T) == typeof(long)) return (T)(object)long.Parse(queue.Dequeue());
        else if (typeof(T) == typeof(string)) return (T)(object)(queue.Dequeue());
        else if (typeof(T) == typeof(double)) return (T)(object)double.Parse(queue.Dequeue());
        else return (T)(object)(-1);
    }
    public static T Line<T>()
    {
        if (typeof(T) == typeof(int[]))
        {
            return (T)(object)Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        }
        else if (typeof(T) == typeof(long[]))
        {
            return (T)(object)Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        }
        else if (typeof(T) == typeof(string[]))
        {
            return (T)(object)Console.ReadLine().Split(' ').ToArray();
        }
        else if (typeof(T) == typeof(double[]))
        {
            return (T)(object)Console.ReadLine().Split(' ').Select(double.Parse).ToArray();
        }
        else return (T)(object)(-1);
    }
}