using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using System.Diagnostics;
using System.Numerics;
using Enu = System.Linq.Enumerable;

public class Program
{
    public void Solve()
    {
        int N = Reader.Int(), A = Reader.Int() - 1, B = Reader.Int() - 1;
        var P = Reader.IntTable(N).Select(a => new[] { a[0] + a[1], a[0] - a[1] }).ToArray();
        long D = Math.Max(Math.Abs(P[A][0] - P[B][0]), Math.Abs(P[A][1] - P[B][1]));
        var uf = new UnionFind(N);
        var deg = new long[N];
        Calc(P, D, uf, deg, 0);
        foreach (var p in P) Swap(ref p[0], ref p[1]);
        Calc(P, D, uf, deg, 1);
        long ans = deg.Where((d, i) => uf.Same(i, A)).Sum() / 2;
        Console.WriteLine(ans);
    }

    void Calc(int[][] P, long D, UnionFind uf, long[] deg, int offset)
    {
        var dic = new Dictionary<long, List<Point>>();
        for (int i = 0; i < P.Length; i++)
            AddDic(dic, P[i][0], new Point(P[i][1], i));
        foreach (var a in dic.Values) a.Sort();

        for (int i = 0; i < P.Length; i++)
            for (long dx = -D; dx <= D; dx += D * 2)
            {
                long x = P[i][0] + dx, y = P[i][1];
                if (!dic.ContainsKey(x)) continue;
                int a = LowerBound(dic[x], new Point(y - D + offset, 0));
                int b = LowerBound(dic[x], new Point(y + D - offset + 1, 0));
                deg[i] += b - a;
                if (a < b) uf.Unite(i, dic[x][a].id);
            }
    }

    struct Point : IComparable<Point>
    {
        public long p;
        public int id;
        public Point(long p, int id)
        {
            this.p = p;
            this.id = id;
        }
        public int CompareTo(Point other)
        {
            return p != other.p ? Math.Sign(p - other.p) : id - other.id;
        }
        public override string ToString()
        {
            return "p:" + p + " id:" + id;
        }
    }

    static void Swap<T>(ref T a, ref T b) { T t = a; a = b; b = t; }

    void AddDic(Dictionary<long, List<Point>> dic, long key, Point val)
    {
        if (!dic.ContainsKey(key)) dic[key] = new List<Point>();
        dic[key].Add(val);
    }

    static int LowerBound(List<Point> A, Point val, int L = 0, int R = -1)
    {
        if (R == -1) R = A.Count;
        while (R - L >= 1)
        {
            int mid = (L + R) / 2;
            if (A[mid].CompareTo(val) >= 0) R = mid;
            else L = mid + 1;
        }
        return R;
    }
}

class UnionFind
{
    private int[] parent;
    private int[] rank;

    public UnionFind(int N)
    {
        parent = new int[N];
        rank = new int[N];
        for (int i = 0; i < N; i++)
            parent[i] = i;
    }
    public int Root(int x)
    {
        if (parent[x] == x) return x;
        return parent[x] = Root(parent[x]);
    }
    public bool Same(int x, int y)
    {
        return Root(x) == Root(y);
    }
    public bool Unite(int x, int y)
    {
        x = Root(x); y = Root(y);
        if (x == y) return false;
        if (rank[x] > rank[y]) { var t = x; x = y; y = t; }
        if (rank[x] == rank[y]) rank[y]++;
        parent[x] = y;
        return true;
    }
}


class Entry { static void Main() { new Program().Solve(); } }
class Reader
{
    static TextReader reader = Console.In;
    static readonly char[] separator = { ' ' };
    static readonly StringSplitOptions op = StringSplitOptions.RemoveEmptyEntries;
    static string[] A = new string[0];
    static int i;
    static void Init() { A = new string[0]; }
    public static void Set(TextReader r) { reader = r; Init(); }
    public static void Set(string file) { reader = new StreamReader(file); Init(); }
    public static bool HasNext() { return CheckNext(); }
    public static string String() { return Next(); }
    public static int Int() { return int.Parse(Next()); }
    public static long Long() { return long.Parse(Next()); }
    public static double Double() { return double.Parse(Next()); }
    public static int[] IntLine() { return Array.ConvertAll(Split(Line()), int.Parse); }
    public static int[] IntArray(int N) { return Range(N, Int); }
    public static int[][] IntTable(int H) { return Range(H, IntLine); }
    public static string[] StringArray(int N) { return Range(N, Next); }
    public static string[][] StringTable(int N) { return Range(N, () => Split(Line())); }
    public static string Line() { return reader.ReadLine().Trim(); }
    public static T[] Range<T>(int N, Func<T> f) { var r = new T[N]; for (int i = 0; i < N; r[i++] = f()) ; return r; }
    static string[] Split(string s) { return s.Split(separator, op); }
    static string Next() { CheckNext(); return A[i++]; }
    static bool CheckNext()
    {
        if (i < A.Length) return true;
        string line = reader.ReadLine();
        if (line == null) return false;
        if (line == "") return CheckNext();
        A = Split(line);
        i = 0;
        return true;
    }
}