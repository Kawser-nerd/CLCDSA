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
        //SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 }; //????
    readonly int mod = 1000000007;
    void chmax<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? b : a; }
    void chmin<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? a : b; }


    void calc(int u)
    {
        bool ta = false;
        bool tb = false;
        foreach (var v in G[u])
        {
            if (S[v] == 'A' && B[v] >= 0)
            {
                ta = true;
            }
            else if (S[v] == 'B' && B[v] >= 0)
            {
                tb = true;
            }
            if (ta && tb)
            {
                B[u] = 1;
                return;
            }
        }
        B[u] = -1;
        foreach (var v in G[u])
        {
            if (B[v] >= 0)
            {
                calc(v);
            }
        }
    }

    int N, M;
    string S;
    int[] B;
    List<int>[] G;
    void solve()
    {
        N = cin.nextint;
        M = cin.nextint;
        S = ReadLine();
        G = Enumerable.Range(0, N).Select(i => new List<int>()).ToArray();
        B = new int[N];
        for (int i = 0; i < M; i++)
        {
            int a = cin.nextint - 1;
            int b = cin.nextint - 1;
            G[a].Add(b);
            G[b].Add(a);
        }

        for (int i = 0; i < N; i++)
        {
            if (B[i] == 0)
            {
                calc(i);
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (B[i] == 1)
            {
                WriteLine("Yes");
                return;
            }
        }
        WriteLine("No");
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