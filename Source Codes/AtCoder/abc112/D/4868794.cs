using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program
{
    static int N;
    static int M;

    public static void Main(string[] args)
    {
        N = Input.NextInt();
        M = Input.NextInt();

        var divisors = GetDivisors(M).ToArray();
        Array.Sort(divisors);
        int div = 0;
        for (int i = 0; i < divisors.Length; i++)
        {
            div = divisors[i];
            if (div < N)
                continue;
            if ((M % div) == 0)
            {
                break;
            }
        }

        Console.WriteLine(M / div);
    }

    public static IEnumerable<int> GetDivisors(int n)
    {
        for (int i = 1; i < (int)Math.Sqrt(n) + 1; i++)
        {
            if ((n % i) == 0)
            {
                yield return i;
                if (i != n / i)
                {
                    yield return n / i;
                }
            }
        }
        yield break;
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