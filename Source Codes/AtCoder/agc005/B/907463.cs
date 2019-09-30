using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using System.Diagnostics;
using Enu = System.Linq.Enumerable;

public class Program
{
    public void Solve()
    {
        int N = Reader.Int();
        var A = Reader.IntArray(N);
        long ans = 0;
        var uf = new UnionFind(N);
        var at = new int[N + 2];

        for (int i = 0; i < N; i++)
            at[A[i]] = i;
        for (int num = N; num >= 1; num--)
        {
            int x = at[num];
            bool isL = x > 0 && A[x - 1] > num;
            bool isR = x < N - 1 && A[x + 1] > num;
            int L = isL ? uf.NumElements(x - 1) : 0;
            int R = isR ? uf.NumElements(x + 1) : 0;
            ans += (long)num * (L + 1) * (R + 1);
            if (isL) uf.Unite(x, x - 1);
            if (isR) uf.Unite(x, x + 1);
        }

        Console.WriteLine(ans);
    }

    class UnionFind
    {
        private int[] parent;
        private int[] rank;
        private int[] numElements;

        public UnionFind(int N)
        {
            parent = new int[N];
            rank = new int[N];
            numElements = new int[N];
            for (int i = 0; i < N; i++)
            {
                parent[i] = i;
                numElements[i] = 1;
            }
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
        public int NumElements(int x)
        {
            return numElements[Root(x)];
        }
        public bool Unite(int x, int y)
        {
            x = Root(x); y = Root(y);
            if (x == y) return false;
            if (rank[x] > rank[y]) { var t = x; x = y; y = t; }
            if (rank[x] == rank[y]) rank[y]++;
            parent[x] = y;
            numElements[y] += numElements[x];
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
    static string[] Split(string s) { return s.Split(separator, op); }
    static T[] Range<T>(int N, Func<T> f) { var r = new T[N]; for (int i = 0; i < N; r[i++] = f()) ; return r; }
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