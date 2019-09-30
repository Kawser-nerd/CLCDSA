using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Globalization;
using System.Diagnostics;
using static System.Console;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;
//using System.Numerics;
//using static System.Math;

class Program
{
    static void Main()
    {
        //SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 };
    readonly int mod = 1000000007;
    readonly string alfa = "abcdefghijklmnopqrstuvwxyz";
    readonly string ALFA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int N, K, L;
    void solve()
    {
        N = cin.nextint;
        K = cin.nextint;
        L = cin.nextint;
        var W = new UnionFind(N);
        var R = new UnionFind(N);
        for (int i = 0; i < K; i++)
        {
            W.Unite(cin.nextint - 1, cin.nextint - 1);
        }
        for (int i = 0; i < L; i++)
        {
            R.Unite(cin.nextint - 1, cin.nextint - 1);
        }
        var H = new pair<pair<int, int>, int>[N];
        for (int i = 0; i < N; i++)
        {
            //WriteLine(W.FindSet(i) + " " + R.FindSet(i) + " " + i);
            H[i] = new pair<pair<int, int>, int>(new pair<int, int>(W.FindSet(i), R.FindSet(i)), i);
        }
        Array.Sort(H);
        var A = new int[N];
        for (int i = 0; i < N; i++)
        {
            A[i] = 1;
        }

        for (int i = 0; i < N - 1; i++)
        {
            int j = i;
            //WriteLine(H[i].v1.v1 + " " + H[i].v1.v2 + " " + i);
            while (i < N - 1 && H[i].v1.v1 == H[i + 1].v1.v1 && H[i].v1.v2 == H[i + 1].v1.v2)
            {
                i++;
            }
            int cnt = i - j;
            //WriteLine(j + " " + i + " " + cnt);
            for (int k = j; k < i + 1; k++)
            {
                A[H[k].v2] += cnt;
            }
        }

        WriteLine(string.Join(" ", A));
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
class pair<T, U> : IComparable<pair<T, U>> where T : IComparable<T> where U : IComparable<U>
{
    public T v1;
    public U v2;
    public pair(T v1, U v2)
    {
        this.v1 = v1;
        this.v2 = v2;
    }
    public int CompareTo(pair<T, U> a)
    {
        return v1.CompareTo(a.v1) != 0 ? v1.CompareTo(a.v1) : v2.CompareTo(a.v2);
    }
    public override string ToString()
    {
        return v1 + " " + v2;
    }
}
class Scanner
{
    string[] s; int i;
    char[] cs = new char[] { ' ' };
    public Scanner() { s = new string[0]; i = 0; }
    public string[] scan { get { return ReadLine().Split(); } }
    public int[] scanint { get { return Array.ConvertAll(scan, int.Parse); } }
    public long[] scanlong { get { return Array.ConvertAll(scan, long.Parse); } }
    public double[] scandouble { get { return Array.ConvertAll(scan, double.Parse); } }
    public string next
    {
        get
        {
            if (i < s.Length) return s[i++];
            string st = ReadLine();
            while (st == "") st = ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
            return next;
        }
    }
    public int nextint { get { return int.Parse(next); } }
    public long nextlong { get { return long.Parse(next); } }
    public double nextdouble { get { return double.Parse(next); } }
}