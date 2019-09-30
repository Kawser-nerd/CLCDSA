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
        List<int[]> e = new List<int[]>();
        for (int i = 0; i < M; i++)
        {
            int[] b = IntLine();
            e.Add(b);
        }
        int ans = 0;
        foreach (var b in e)
        {
            UnionFind uf = new UnionFind(N+1);
            foreach (var a in e)
            {
                if (a == b) continue;
                uf.Unite(a[0], a[1]);
            }
            for (int i = 2; i <= N; i++) {
                if (!uf.Same(i, 1)) {
                    ans++;
                    break;
                }
            }
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
    public static long LCM(long a, long b)
    {
        long c = a * b;
        if (a < b) Swap(ref a, ref b);
        long d = a % b;
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
    public static int[] SpIntRead(char c)
    {
        return Console.ReadLine().Split(c).Select(int.Parse).ToArray();
    }
    public static string ToConvertBit(int N, int e)
    {
        string ret = "";
        int r = 0;
        while (N != 0)
        {
            r = N % e;
            ret += r.ToString();
            N -= r;
            N /= e;
        }
        ret = StrReverce(ret);
        return ret;
    }
    public static int IntRead()
    {
        return int.Parse(Console.ReadLine());
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