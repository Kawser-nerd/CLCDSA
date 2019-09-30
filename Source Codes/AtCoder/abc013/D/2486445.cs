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

    void swap<T>(ref T a, ref T b)
    {
        var t = a;
        a = b;
        b = t;
    }

    void solve()
    {
        int N = cin.nextint;
        int M = cin.nextint;
        int D = cin.nextint;

        int i;
        var L = new List<int[]> { Enumerable.Range(0, N).ToArray() };
        if (M > 0)
        {
            var T = cin.scanint;
            foreach (var v in T)
            {
                swap(ref L[0][v - 1], ref L[0][v]);
            }

        }

        for (i = 1; 1 << i <= D; i++)
        {
            L.Add(new int[N]);
            for (int j = 0; j < N; j++)
            {
                L[i][j] = L[i - 1][L[i - 1][j]];
            }
        }
        //WriteLine(string.Join(" ", L[0]));
        var ans = Enumerable.Range(0, N).ToArray();
        var memo = Enumerable.Range(0, N).ToArray();
        while (D > 0)
        {
            if (1 << i <= D)
            {
                for (int j = 0; j < N; j++)
                {
                    ans[j] = memo[L[i][j]];
                }
                ans.CopyTo(memo, 0);
                D -= 1 << i;
            }
            i--;
        }

        var A = new int[N];
        for (int k = 0; k < N; k++)
        {
            A[ans[k]] = k + 1;
        }
        foreach (var item in A)
        {
            WriteLine(item);
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