using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
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

    List<int>[] G;
    int N, M;
    int[] L, R, D;
    bool[] used_n;
    bool[] used_m;
    Queue<int> Q;
    int[] A;

    bool ans = true;
    void solve()
    {
        N = cin.nextint;
        M = cin.nextint;
        Q = new Queue<int>();
        used_n = new bool[N];
        used_m = new bool[M];
        G = Enumerable.Range(0, N).Select(i => new List<int>()).ToArray();
        L = new int[M];
        R = new int[M];
        D = new int[M];
        for (int i = 0; i < M; i++)
        {
            L[i] = cin.nextint - 1;
            R[i] = cin.nextint - 1;
            D[i] = cin.nextint;

            G[L[i]].Add(i);
            G[R[i]].Add(i);
        }
        A = Enumerable.Repeat(int.MaxValue, N).ToArray(); //i???k???
        for (int i = 0; i < N; i++)
        {
            if (used_n[i]) continue;
       
            A[i] = 0;
            Q.Enqueue(i);

            while (Q.Any())
            {
                int d = Q.Dequeue();
                if (used_n[d]) continue;
                calc(d);
                used_n[d] = true;
            }

        }
        WriteLine(ans ? "Yes" : "No");
    }
    void calc(int u)
    {
        foreach (var v in G[u])
        {
            if (used_m[v]) continue;
            used_m[v] = true;
            if (L[v] == u)
            {
                if (A[R[v]] != int.MaxValue)
                {
                    if (A[R[v]] != A[u] + D[v])
                    {
                        ans = false;
                    }
                }
                else
                {
                    A[R[v]] = A[u] + D[v];
                    Q.Enqueue(R[v]);
                }
            }
            else
            {
                if (A[L[v]] != int.MaxValue)
                {
                    if (A[L[v]] != A[u] - D[v])
                    {
                        ans = false;
                    }
                }
                else
                {
                    A[L[v]] = A[u] - D[v];
                    Q.Enqueue(L[v]);
                }
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