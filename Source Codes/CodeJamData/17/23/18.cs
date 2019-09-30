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
        SetIn(new StreamReader("C-large.in"));
        SetOut(new StreamWriter("c_out.txt"));
        int T = int.Parse(ReadLine());
        for (int i = 0; i < T; i++)
        {
            Write("Case #" + (i + 1) + ": ");
            new Program().Solve();
        }
        Out.Flush();
    }
    Scanner cin = new Scanner();
    Random rnd = new Random();
    Stopwatch sw = new Stopwatch();
    readonly int[] dd = { 0, 1, 0, -1, 0 };
    readonly int mod = 1000000007;
    readonly string alfa = "abcdefghijklmnopqrstuvwxyz";
    long INF = long.MaxValue / 3;
    int N, Q;
    void Solve()
    {
        N = cin.Nextint;
        Q = cin.Nextint;
        var E = new int[N];
        var S = new int[N];
        for (int i = 0; i < N; i++)
        {
            E[i] = cin.Nextint;
            S[i] = cin.Nextint;
        }

        var G = Enumerable.Range(0, N).Select(i => new List<Pair>()).ToArray();
        var C = new double[N, N];

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                C[i, j] = cin.Nextint;
                if (C[i, j] == -1)
                {
                    C[i, j] = INF;
                    // G[i].Add(new Pair(j, C[i, j]));
                }
                if (i == j)
                {
                    C[i, j] = 0;
                }
            }
        }


        for (int k = 0; k < N; k++)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    C[i, j] = Math.Min(C[i, j], C[i, k] + C[k, j]);
                }
            }
        }

        var D = new double[N, N];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (C[i, j] <= E[i])
                {
                    D[i, j] = C[i, j] / S[i];
                }
                else
                {
                    D[i, j] = INF;
                }
            }
        }

        for (int k = 0; k < N; k++)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    D[i, j] = Math.Min(D[i, j], D[i, k] + D[k, j]);
                }
            }
        }


        for (int i = 0; i < Q; i++)
        {
            int U = cin.Nextint - 1;
            int V = cin.Nextint - 1;
            if (i != 0) Write(" ");
            Write(D[U, V].ToString("f7"));

        }
        WriteLine();

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