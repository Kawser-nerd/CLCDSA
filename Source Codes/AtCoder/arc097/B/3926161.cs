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
        int[] NM = IntLine();
        int N = NM[0], M = NM[1];
        int[] ps = IntLine();
        UnionFind tree = new UnionFind(N);

        for (int i = 0; i < M; i++)
        {
            int[] box = IntLine().Select(v => v - 1).ToArray(); ;
            tree.Unite(box[0], box[1]);
        }

        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            if (tree.Same(i, ps[i] - 1)) ans++;
        }
        Console.WriteLine(ans);
    }
}

public class UnionFind
{
    public List<int> parent = new List<int>();

    public UnionFind(int N)
    {
        for (int i = 0; i < N; i++) parent.Add(i);
    }

    private int Root(int a)
    {
        if (parent[a] == a) return a;
        else return parent[a] = Root(parent[a]);
    }

    public void Unite(int a, int b)
    {
        a = Root(a);
        b = Root(b);
        if (a == b) return;
        parent[a] = parent[b];
    }

    public bool Same(int a, int b) { return (Root(a) == Root(b)); }
}

public class Atcoder
{
    public static void Swap<T>(ref T a, ref T b)
    {
        var t = a;
        a = b;
        b = t;
    }
    public static int LCM(int a, int b)
    {
        int c = a * b;
        if (a < b) Swap(ref a, ref b);
        int d = a % b;
        while (d != 0)
        {
            a = b;
            b = d;
            d = a % b;
        }
        return c / b;
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