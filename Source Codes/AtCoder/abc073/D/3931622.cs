using System;
using System.Collections.Generic;
using System.Linq;
using static Atcoder;
using System.Threading.Tasks;
using System.ComponentModel;

public class Hello
{
    private const int INF = 1000000007;
    public static void Main()
    {
        int[] NMR = IntLine();
        int N = NMR[0], M = NMR[1], R = NMR[2];
        int[] rR = IntLine().Select(v => v - 1).ToArray();
        int[,] Edge = new int[N, N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                Edge[i, j] = (i == j ? 0 : INF);
        for (int i = 0; i < M; i++)
        {
            int[] box = IntLine();
            Edge[box[0] - 1, box[1] - 1] = Math.Min(Edge[box[0] - 1, box[1] - 1], box[2]);
            Edge[box[1] - 1, box[0] - 1] = Math.Min(Edge[box[1] - 1, box[0] - 1], box[2]);
        }
        //WF
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    Edge[j, k] = Math.Min(Edge[j, k], Edge[j, i] + Edge[i, k]);

        Permutation p = new Permutation(rR.ToList());
        p.PermList = new List<List<int>>();
        p.Calc(new List<int>());
        long ans = INF;
        foreach (var l in p.PermList)
        {
            long b = 0;
            for (int i = 1; i < R; i++)
            {
                b += Edge[l[i - 1], l[i]];
            }
            ans = Math.Min(ans, b);
        }
        Console.WriteLine(ans);
    }
}

public class Permutation
{
    private static List<int> line;
    public List<List<int>> PermList { get; set; }

    public Permutation(List<int> list) { line = new List<int>(list); }

    public void Calc(List<int> list)
    {
        if (list.Count == line.Count())
        {
            PermList.Add(list);
            return;
        }
        foreach (int i in line)
        {
            if (!list.Contains(i))
            {
                List<int> nextlist = new List<int>(list);
                nextlist.Add(i);
                Calc(nextlist);
            }
        }
    }

    public void Draw()
    {
        foreach (var l in PermList)
        {
            l.ForEach(v => Console.Write(v + " "));
            Console.WriteLine();
        }
    }
}

public class Atcoder
{
    public static void Swap<T>(ref T a, ref T b)
    {
        var t = a;
        a = b;
        b = t;
    }
    public static int GCD(int a, int b)
    {
        if (a < b) Swap(ref a, ref b);
        int d = a % b;
        while (b != 0)
        {
            d = a % b;
            a = b;
            b = d;
        }
        return a;
    }
    public static long LCM(int a, int b)
    {
        return (long)a * b / GCD(a, b);
    }
    public static string StrReverce(string s)
    {
        return new string(s.Reverse().ToArray());
    }
    public static int IntRead()
    {
        return int.Parse(Console.ReadLine());
    }
    public static bool IsPrime(int n)
    {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;

        //double sqrtNum = Math.Sqrt(n);
        for (int i = 3; i < n; i += 2)
        {
            if (n % i == 0) return false;
        }
        return true;
    }
    public static string[] SpRead(char c)
    {
        return Console.ReadLine().Split(c);
    }
    public static long[] LSRead()
    {
        return Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
    }
    public static long Combination(int n, int r)
    {
        if (n == r) return 1;
        return
            Enumerable.Range((n - r + 1), r).ToList().Aggregate((now, next) => now * next) /
            Enumerable.Range(1, r).ToList().Aggregate((now, next) => now * next);
    }
    public static long Permutation(int n, int r)
    {
        if (n == r) return 1;
        return
            Enumerable.Range((n - r), r).ToList().Aggregate((now, next) => now * next);
    }
    public static long LongRead()
    {
        return long.Parse(Console.ReadLine());
    }
    public static long[] LongLine()
    {
        return Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
    }
    public static int[] IntLine()
    {
        return Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
    }
}