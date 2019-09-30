using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static int N;
    static long X;

    static long[] a = new long[50 + 1];

    static void InitA()
    {
        A(50);
    }

    static long A(int l)
    {
        if (l == 0)
        {
            return a[l] = 1;
        }

        return a[l] = (A(l - 1) * 2 + 3);
    }

    public static void Main(string[] args)
    {
        InitA();

        N = Input.NextInt();
        X = Input.NextLong();

        var asn = F(N, X);
        Console.WriteLine(asn);
    }

    static Dictionary<Tuple<int, long>, long> FTable = new Dictionary<Tuple<int, long>, long>();

    static long F(int l, long x)
    {
        if (l == 0)
            return 1;

        var key = new Tuple<int, long>(l, x);
        if (FTable.ContainsKey(key))
            return FTable[key];

        long ans;
        if (x == 1)
            ans = 0;
        else if (2 <= x && x <= (a[l] - 3) / 2 + 1)
            ans = F(l - 1, x - 1);
        else if (x == ((a[l] - 3) / 2 + 2))
            ans = F(l - 1, a[l - 1]) + 1;
        else
            ans = F(l - 1, a[l - 1]) + 1 + F(l - 1, x - 2 - a[l - 1]);

        FTable[key] = ans;
        return ans;
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