using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections.Generic;
using System.Diagnostics;
using Enu = System.Linq.Enumerable;

public class Program
{
    static readonly int Mod = (int)1e9 + 7;

    public void Solve()
    {
        int N = Reader.Int(), X = Reader.Int(), Y = Reader.Int();
        var dic = new Dictionary<int, List<int>>();
        int[] C = new int[N], W = new int[N];
        for (int i = 0; i < N; i++)
        {
            C[i] = Reader.Int(); W[i] = Reader.Int();
            AddDic(dic, C[i], i);
        }
        if (dic.Count == 1) { Console.WriteLine(1); return; }

        var mins = new List<int>();
        var uf = new UnionFind(N);
        foreach (var A in dic.Values)
        {
            int minW = int.MaxValue, who = 0;
            foreach (int i in A)
                if (CheckMin(ref minW, W[i])) who = i;
            mins.Add(who);
            foreach (int i in A)
                if (minW + W[i] <= X) uf.Unite(who, i);
        }
        mins = mins.OrderBy(i => W[i]).ToList();
        foreach (var A in dic.Values)
            for (int mi = 0; mi < 2; mi++)
                if (C[mins[mi]] != C[A[0]])
                    foreach (int i in A)
                        if (W[mins[mi]] + W[i] <= Y) uf.Unite(mins[mi], i);
        long ans = 1;
        modC = new ModC(N, Mod);
        foreach (var A in uf.Components().Values)
        {
            var count = new Dictionary<int, List<int>>();
            foreach (int i in A) AddDic(count, C[i], 1);
            ans *= Count(count.Values.Select(v => v.Count).ToArray());
            ans %= Mod;
        }

        Console.WriteLine(ans);
    }


    ModC modC;
    long Count(int[] count)
    {
        int sum = count.Sum();
        long res = 1;
        foreach (int num in count)
        {
            res = res * modC[sum, num] % Mod;
            sum -= num;
        }
        return res;
    }

    bool CheckMin(ref int a, int b) { if (b < a) { a = b; return true; } return false; }

    void AddDic(Dictionary<int, List<int>> dic, int key, int val)
    {
        if (!dic.ContainsKey(key)) dic[key] = new List<int>();
        dic[key].Add(val);
    }
}

class ModC
{
    readonly long P;
    readonly long[] Fact, InvFact;

    public int this[int n, int k]
    {
        get
        {
            if (n < 0 || k < 0 || k > n) return 0;
            return (int)(Fact[n] * InvFact[k] % P * InvFact[n - k] % P);
        }
    }
    public ModC(int maxN, int p) // maxN < p, p is prime
    {
        P = p;
        Fact = new long[maxN + 1];
        InvFact = new long[maxN + 1];
        Fact[0] = 1;
        for (long i = 1; i <= maxN; i++)
            Fact[i] = Fact[i - 1] * i % P;
        InvFact[maxN] = ModPower(Fact[maxN], p - 2, p);
        for (int i = maxN - 1; i >= 0; i--)
            InvFact[i] = InvFact[i + 1] * (i + 1) % p;
    }
    long ModPower(long x, long n, long mod) // x ^ n
    {
        long res = 1;
        if ((x %= mod) < 0) x += mod;
        for (; n > 0; n >>= 1, x = x * x % mod)
            if ((n & 1) == 1) res = res * x % mod;
        return res;
    }
}

class UnionFind
{
    private int[] parent;
    private byte[] rank;

    public UnionFind(int N)
    {
        parent = new int[N];
        rank = new byte[N];
        for (int i = 0; i < N; i++) parent[i] = -1;
    }
    public int Root(int x)
    {
        if (parent[x] < 0) return x;
        return parent[x] = Root(parent[x]);
    }
    public bool Same(int x, int y)
    {
        return Root(x) == Root(y);
    }
    public int Count(int x)
    {
        return -parent[Root(x)];
    }
    public bool Unite(int x, int y)
    {
        x = Root(x); y = Root(y);
        if (x == y) return false;
        if (rank[x] > rank[y]) { var t = x; x = y; y = t; }
        if (rank[x] == rank[y]) rank[y]++;
        parent[y] += parent[x];
        parent[x] = y;
        return true;
    }
    public Dictionary<int, List<int>> Components()
    {
        var dic = new Dictionary<int, List<int>>();
        for (int i = 0; i < parent.Length; i++)
        {
            int root = Root(i);
            if (!dic.ContainsKey(root)) dic[root] = new List<int>();
            dic[root].Add(i);
        }
        return dic;
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
    static void Init() { Dispose(); A = new string[0]; }
    public static void Set(TextReader r) { Init(); reader = r; }
    public static void Set(string file) { Init(); reader = new StreamReader(file); }
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
    public static void Dispose() { reader.Dispose(); }
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