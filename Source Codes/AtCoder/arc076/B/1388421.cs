using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Globalization;
using System.Diagnostics;
using static System.Console;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;
//using System.Numerics;

class Program
{
    static void Main()
    {
        //SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().Solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    Random rnd = new Random();
    Stopwatch sw = new Stopwatch();
    readonly int[] dd = { 0, 1, 0, -1, 0 };
    readonly int mod = 1000000007;
    readonly string alfa = "abcdefghijklmnopqrstuvwxyz";

    int N;
    void Solve()
    {
        N = cin.Nextint;
        var X = new int[N];
        var Y = new int[N];
        var A = Enumerable.Range(0, N).ToArray();
        var B = Enumerable.Range(0, N).ToArray();
        for (int i = 0; i < N; i++)
        {
            X[i] = cin.Nextint;
            Y[i] = cin.Nextint;
        }
        Array.Sort(X, A);
        Array.Sort(Y, B);
        int idx = 0;
        var Cost = new int[2 * N - 2];
        var P = new Pair[2 * N - 2];

        for (int i = 1; i < N; i++)
        {
            Cost[idx] = X[i] - X[i - 1];
            P[idx] = new Pair(A[i - 1], A[i]);
            idx++;
        }
        for (int i = 1; i < N; i++)
        {
            Cost[idx] = Y[i] - Y[i - 1];
            P[idx] = new Pair(B[i - 1], B[i]);
            idx++;
        }

        Array.Sort(Cost, P);

        long ans = 0;
        var U = new UnionFind(N);
        for (int i = 0; i < idx; i++)
        {
            if (!U.Same(P[i].Key, P[i].Value))
            {
                U.Unite(P[i].Key, P[i].Value);
                ans += Cost[i];
            }
        }

        WriteLine(ans);
    }

}

class UnionFind
{
    internal int[] rank;
    internal int[] p;
    internal int[] weight;
    public UnionFind(int size)
    {
        rank = new int[size];
        p = new int[size];
        weight = new int[size];
        for (int i = 0; i < size; i++)
        {
            rank[i] = 0;
            p[i] = i;
            weight[i] = 1;
        }
    }
    public void Unite(int x, int y)
    {
        x = FindSet(x);
        y = FindSet(y);
        if (x == y) return;
        if (rank[x] > rank[y])
        {
            p[y] = x;
            weight[x] += weight[y];
        }

        if (rank[x] < rank[y])
        {
            p[x] = y;
            weight[y] += weight[x];
        }
        if (rank[x] == rank[y])
        {
            p[x] = y;
            rank[y]++;
            weight[y] += weight[x];
        }
    }
    public bool Same(int x, int y)
    {
        return FindSet(x) == FindSet(y);
    }
    public int FindSet(int x)
    {
        var H = new HashSet<int>();
        while (p[x] != x)
        {
            H.Add(x);
            x = p[x];
        }
        foreach (var h in H)
        {
            p[h] = x;
        }
        return x;
    }
    public int Weight(int x)
    {
        return weight[FindSet(x)];
    }
}

class Scanner
{
    string[] s; int i;
    char[] cs = new char[] { ' ' };
    public Scanner() { s = new string[0]; i = 0; }
    public string[] Scan { get { return ReadLine().Split(); } }
    public int[] Scanint { get { return Array.ConvertAll(Scan, int.Parse); } }
    public long[] Scanlong { get { return Array.ConvertAll(Scan, long.Parse); } }
    public double[] Scandouble { get { return Array.ConvertAll(Scan, double.Parse); } }
    public string Next
    {
        get
        {
            if (i < s.Length) return s[i++];
            string st = ReadLine();
            while (st == "") st = ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
            return Next;
        }
    }
    public int Nextint { get { return int.Parse(Next); } }
    public long Nextlong { get { return long.Parse(Next); } }
    public double Nextdouble { get { return double.Parse(Next); } }
}