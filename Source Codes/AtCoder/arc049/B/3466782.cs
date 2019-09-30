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

    int M = 100000;
    int N;
    int[] X, Y, C;
    void solve()
    {
        N = cin.nextint;

        X = new int[N];
        Y = new int[N];
        C = new int[N];

        for (int i = 0; i < N; i++)
        {
            X[i] = cin.nextint;
            Y[i] = cin.nextint;
            C[i] = cin.nextint;
        }

        double lx = -M;
        double rx = M;
        for (int i = 0; i < 100; i++)
        {
            var first = (lx * 2 + rx) / 3;
            var second = (lx + rx * 2) / 3;
            if (search(first) < search(second))
            {
                rx = second;
            }
            else
            {
                lx = first;
            }
        }

        WriteLine(search((lx + rx) / 2).ToString("F5"));
    }

    double search(double px)
    {
        double ly = -M;
        double ry = M;
        for (int i = 0; i < 100; i++)
        {
            var first = (ly * 2 + ry) / 3;
            var second = (ly + ry * 2) / 3;
            if (calc(px, first) < calc(px, second))
            {
                ry = second;
            }
            else
            {
                ly = first;
            }
        }

        return calc(px, (ly + ry) / 2);
    }

    double calc(double px, double py)
    {
        double ret = 0;
        for (int i = 0; i < N; i++)
        {
            chmax(ref ret, Max(Abs(px - X[i]), Abs(py - Y[i])) * C[i]);
        }
        return ret;
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