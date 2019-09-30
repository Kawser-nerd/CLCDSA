using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

class Program
{
    static string S, T;

    public static void Main(string[] args)
    {
        S = Input.NextString();
        T = Input.NextString();

        var CountS = new List<int>[26];
        var CountT = new List<int>[26];

        foreach (var i in Enumerable.Range(0, 26))
        {
            CountS[i] = new List<int>();
            CountT[i] = new List<int>();
        }
        for (int i = 0; i < S.Length; i++)
        {
            CountS[S[i] - 'a'].Add(i);
            CountT[T[i] - 'a'].Add(i);
        }

        var comp = new Comp();

        Array.Sort(CountS, comp);
        Array.Sort(CountT, comp);

        for (int i = 0; i < 26; i++)
        {
            var f = AEquals(CountS[i], CountT[i]);
            if (!f)
            {
                Console.WriteLine("No");
                return;
            }

        }

        Console.WriteLine("Yes");
        return;
    }

    static bool AEquals(List<int> x, List<int> y)
    {
        if (x.Count != y.Count)
            return false;

        for (int i = 0; i < x.Count; i++)
        {
            if (x[i] != y[i])
                return false;
        }

        return true;
    }

    class Comp : IComparer<List<int>>
    {
        public int Compare(List<int> x, List<int> y)
        {
            int ix = 0;
            int iy = 0;

            while (true)
            {
                if (x.Count <= ix && y.Count <= iy)
                    return 0;
                if (x.Count <= ix)
                    return 1;
                if (y.Count <= iy)
                    return -1;

                var cx = x[ix++];
                var cy = y[iy++];
                if (cx != cy)
                    return cx - cy;
            }
        }
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