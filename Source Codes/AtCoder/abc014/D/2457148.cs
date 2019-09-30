using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
//using System.Text;
//using System.Text.RegularExpressions;
//using System.Globalization;
//using System.Diagnostics;
using static System.Console;
//using System.Numerics;
//using static System.Math;
//using pair = Pair<int, int>;

class Program
{
    static void Main()
    {
        SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 }; //????
    readonly int mod = 1000000007;
    void chmax<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? b : a; }
    void chmin<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? a : b; }

    void solve()
    {
        int N = cin.nextint;
        var D = new HLTree(N);
        for (int i = 0; i < N - 1; i++)
        {
            D.AddEdge(cin.nextint - 1, cin.nextint - 1);
        }
        D.Build();

        int Q = cin.nextint;
        for (int i = 0; i < Q; i++)
        {
            int u = cin.nextint - 1, v = cin.nextint - 1;
            WriteLine(D[u] + D[v] - D[D.GetLCA(u, v)] * 2 + 1);
        }
    }


}

class HLTree
{
    int n;
    List<int>[] G;
    int[] subtreeSize, maxsize, par, d;

    Chain[] go;
    int[] pos;
    List<Chain> chains;
    public HLTree(int N)
    {
        n = N;
        G = new List<int>[n];
        chains = new List<Chain>();
        for (int i = 0; i < n; i++)
            G[i] = new List<int>();
        subtreeSize = new int[n];
        maxsize = new int[n];
        par = new int[n];
        d = new int[n];
        go = new Chain[n];
        pos = new int[n];
    }
    public void AddEdge(int u, int v)
    {
        G[u].Add(v); G[v].Add(u);
    }
    public void Build(int root = 0)
    {
        computeSubtreeSize(root);
        Decomposite(-1, root, 0);
    }
    void computeSubtreeSize(int r)
    {
        var stack = new Stack<int>();
        stack.Push(r);
        var iter = new int[n];
        par[r] = -1;
        //dfs
        while (stack.Count > 0)
        {
            var cur = stack.Peek();
            if (iter[cur] == G[cur].Count)
            {
                stack.Pop();
                subtreeSize[cur]++;
                if (par[cur] != -1)
                {
                    subtreeSize[par[cur]] += subtreeSize[cur];
                    maxsize[par[cur]] = Math.Max(maxsize[par[cur]], subtreeSize[cur]);
                }
                continue;
            }
            var next = G[cur][iter[cur]++];
            if (next == par[cur]) continue;
            par[next] = cur;
            d[next] = d[cur] + 1;
            stack.Push(next);
        }
    }
    void Decomposite(int from, int cur, int lv)
    {
        var chain = new Chain(from, lv);
        chains.Add(chain);
        chain.Add(cur);
        while (cur != from)
        {
            var next = cur;
            go[cur] = chain;
            pos[cur] = chain.Count;
            foreach (var to in G[cur])
            {
                if (to == from) continue;
                if (maxsize[cur] == subtreeSize[to])
                {
                    maxsize[cur] = -1;
                    next = to;
                    chain.Add(to);
                }
                else Decomposite(cur, to, lv + 1);
            }

            from = cur;
            cur = next;

        }
        chain.Init();
    }
    public int GetLCA(int u, int v)
    {
        while (go[u] != go[v])
        {
            if (go[u].Level < go[v].Level) v = go[v].From;
            else u = go[u].From;
        }
        if (d[u] <= d[v]) return u;
        else return v;
    }
    class Chain
    {
        const bool DEBUG = true;
        public int From { get; set; }
        public int Level { get; set; }
        public int Count { get; private set; }
        List<int> heavy;
        public Chain(int from, int lv)
        {
            From = from;
            Level = lv;
            heavy = new List<int>();
        }
        public void Add(int v)
        {
            if (DEBUG)
                heavy.Add(v);
            Count++;
        }
        public void Init()
        {

        }
    }
    public int GetDist(int u)
    {
        return d[u];
    }
    public int this[int u]
    {
        get { return d[u]; }
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