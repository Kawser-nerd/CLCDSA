using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;
using static System.Console;
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
    readonly int[] dd = { 0, 1, 0, -1, 0 }; //????
    readonly int mod = 1000000007;


    void solve()
    {
        int N = cin.nextint;

        var D = new Dinic(N + 2);
        long exp = 0;
        for (int i = 1; i <= N; i++)
        {
            var a = cin.nextlong;
            if (a < 0)
            {
                D.add_edge(0, i, -a);
            }
            else
            {
                D.add_edge(i, N + 1, a);
                exp += a;
            }
            int j = 2 * i;
            while (j <= N)
            {
                D.add_edge(i, j, Dinic.INF);
                j += i;
            }
        }
        var mincut = D.max_flow(0, N + 1);
        WriteLine(exp - mincut);
    }

}

class Dinic
{
    // ??????????????????
    class Edge_
    {
        public int to;
        public long cap;
        public int rev;
        public Edge_(int to, long cap, int rev)
        {
            this.to = to;
            this.cap = cap;
            this.rev = rev;
        }
    }

    public const long INF = long.MaxValue / 3;
    List<Edge_>[] G; // ???????????
    int[] level;    // s?????
    int[] iter;     // ???????????

    public Dinic(int V)
    {
        G = new List<Edge_>[V];
        for (int i = 0; i < V; i++) G[i] = new List<Edge_>();
        level = new int[V];
        iter = new int[V];
    }

    // from??to????????BFS?????
    public void add_edge(int from, int to, long cap)
    {
        G[from].Add(new Edge_(to, cap, G[to].Count));
        G[to].Add(new Edge_(from, 0, G[from].Count - 1));
    }

    // s????????BFS?????
    void bfs(int s)
    {
        for (int i = 0; i < level.Length; i++) level[i] = -1;
        var que = new Queue<int>();
        level[s] = 0;
        que.Enqueue(s);
        while (que.Any())
        {
            int v = que.Dequeue();
            foreach (Edge_ e in G[v])
            {
                if (e.cap > 0 && level[e.to] < 0)
                {
                    level[e.to] = level[v] + 1;
                    que.Enqueue(e.to);
                }
            }
        }
    }

    //?????DFS???
    long dfs(int v, int t, long f)
    {
        if (v == t) return f;
        for (int i = iter[v]; i < G[v].Count; i++)
        {
            Edge_ e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to])
            {
                long d = dfs(e.to, t, Math.Min(f, e.cap));
                if (d > 0)
                {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    // s??t?????????
    public long max_flow(int s, int t)
    {
        long flow = 0;
        while (true)
        {
            bfs(s);
            if (level[t] < 0) return flow;
            for (int i = 0; i < iter.Length; i++) iter[i] = 0;
            while(true)
            {
                long f = dfs(s, t, INF);
                if (f <= 0) break;
                flow += f;
            }
        }
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