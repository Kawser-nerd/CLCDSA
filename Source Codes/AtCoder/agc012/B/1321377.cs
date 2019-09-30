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
        SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().Solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    Random rnd = new Random();
    Stopwatch sw = new Stopwatch();
    readonly int[] dd = { 0, 1, 0, -1, 0 };
    readonly int mod = 1000000007;
    readonly string alfa = "abcdefghijklmnopqrstuvwxyz";

    List<int>[] G;
    int N, M, Q;
    int[] v, d, c;
    int[] A;
    int[] color;
    void dfs(int u, int dis, int c)
    {
        if (dis <= A[u]) return;
        A[u] = dis;
        if (color[u] == 0) color[u] = c;
        foreach (var v in G[u])
        {
            if (dis - 1 <= A[v]) continue;
            dfs(v, dis - 1, c);
        }
    }
    void Solve()
    {
        N = cin.Nextint;
        M = cin.Nextint;
        G = Enumerable.Range(0, N).Select(i => new List<int>()).ToArray();
        for (int i = 0; i < M; i++)
        {
            int a = cin.Nextint - 1;
            int b = cin.Nextint - 1;
            G[a].Add(b);
            G[b].Add(a);
        }
        Q = cin.Nextint;
        v = new int[Q];
        d = new int[Q];
        c = new int[Q];

        for (int i = 0; i < Q; i++)
        {
            v[i] = cin.Nextint - 1;
            d[i] = cin.Nextint;
            c[i] = cin.Nextint;
        }

        A = Enumerable.Repeat(-1, N).ToArray();
        color = new int[N];
        for (int i = Q - 1; i >= 0; i--)
        {
            //dfs(v[i], d[i], c[i]);
            var X = new Queue<int>();
            var Y = new Queue<int>();
            X.Enqueue(v[i]);
            Y.Enqueue(d[i]);
            while (X.Any())
            {
                int u = X.Dequeue();
                int dis = Y.Dequeue();
                if (dis <= A[u]) continue;
                A[u] = dis;
                if (color[u] == 0) color[u] = c[i];
                foreach (var k in G[u])
                {
                    X.Enqueue(k);
                    Y.Enqueue(dis - 1);
                }

            }

        }

        foreach (var k in color)
        {
            WriteLine(k);
        }
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