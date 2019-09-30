using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Globalization;
using System.Diagnostics;
using static System.Console;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;

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

    int N, M, from, to;
    List<int>[] G;
    Stack<int> S;
    Queue<int> Q;

    bool[] B;
    void Solve()
    {
        N = cin.Nextint;
        M = cin.Nextint;
        int s=-1, g=-1;
        G = Enumerable.Range(0, N).Select(i => new List<int>()).ToArray();
        for (int i = 0; i < M; i++)
        {
            int a = cin.Nextint - 1;
            int b = cin.Nextint - 1;
            G[a].Add(b);
            G[b].Add(a);
            s = a;
            g = b;
        }

        B = new bool[N];
        B[s] = true; B[g] = true;
        S = new Stack<int>();
        Q = new Queue<int>();
        S.Push(s);
        Q.Enqueue(g);
        Dfs(s, 0);
        Dfs(g, 1);
        WriteLine(S.Count + Q.Count);
        foreach (var v in S)
        {
            Write((v + 1) + " ");
        }
        foreach (var v in Q)
        {
            Write((v + 1) + " ");
        }
        WriteLine();

    }
    void Dfs(int u, int p)
    {
        foreach (var v in G[u])
        {
            if (B[v]) continue;
            else
            {
                B[v] = true;
                if (p == 0) S.Push(v);
                else Q.Enqueue(v);
                Dfs(v, p);
                break;
            }
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