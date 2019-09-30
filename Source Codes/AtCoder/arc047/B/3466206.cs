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
using static System.Math;
//using pair = Pair<int, int>;

class Program
{
    static void Main()
    {
        //SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().solve();
        Out.Flush();
    }
    readonly Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 }; //????
    readonly int mod = 1000000007;
    void chmax<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? b : a; }
    void chmin<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? a : b; }

    void solve()
    {
        int N = cin.nextint;
        var x = new int[N];
        var y = new int[N];
        var X = new int[N];
        var Y = new int[N];

        for (int i = 0; i < N; i++)
        {
            x[i] = cin.nextint;
            y[i] = cin.nextint;
            X[i] = x[i] + y[i];
            Y[i] = x[i] - y[i];
        }

        int D = Max(X.Max() - X.Min(), Y.Max() - Y.Min());

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int px = X.Max() - D / 2;
                if (i == 0) px = X.Min() + D / 2;
                int py = Y.Max() - D / 2;
                if (j == 0) py = Y.Min() + D / 2;

                int tx = (px + py) / 2;
                int ty = (px - py) / 2;
                bool flag = true;
                for (int r = 0; r < N; r++)
                {
                    if (Abs(x[r] - tx) + Abs(y[r] - ty) != Abs(x[0] - tx) + Abs(y[0] - ty))
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    WriteLine(tx + " " + ty);
                    return;
                }
            }
        }
    }

}

class Scanner
{
    string[] s; int i;
    readonly char[] cs = new char[] { ' ' };
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
    public void join<T>(IEnumerable<T> values) { WriteLine(string.Join(" ", values)); }
}