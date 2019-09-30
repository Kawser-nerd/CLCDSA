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
    Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 }; //????
    readonly int mod = 1000000007;
    void chmax<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? b : a; }
    void chmin<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? a : b; }

    void solve()
    {
        int N = cin.nextint;
        int M = cin.nextint;
        var X = new long[N];
        var Y = new long[N];
        var Z = new long[N];
        var P = new Tuple<long, long, long>[N];
        for (int i = 0; i < N; i++)
        {
            X[i] = cin.nextlong;
            Y[i] = cin.nextlong;
            Z[i] = cin.nextlong;
            P[i] = new Tuple<long, long, long>(X[i], Y[i], Z[i]);
        }

        long ans = 0;
        foreach (var i in new[] { -1, 1 })
        {
            foreach (var j in new[] { -1, 1 })
            {
                foreach(var k in new[] { -1, 1 })
                {
                    var L = new long[N];
                    for (int p = 0; p < N; p++)
                    {
                        L[p] = X[p] * i + Y[p] * j + Z[p] * k;  
                    }

                    chmax(ref ans, L.OrderByDescending(t => t).Take(M).Sum());
                }
            }
        }
        WriteLine(ans);

        //long ans = 0;
        //for (int i = 0; i < N; i++)
        //{
        //    long x = X[i], y = Y[i], z = Z[i];
        //    for (int j = i + 1; j < N; j++)
        //    {
        //        if (Abs(x + X[j]) + Abs(y + Y[j]) + Abs(z + Z[j]) > Abs(x) + Abs(y) + Abs(z))
        //        {
        //            x += X[j];
        //            y += Y[j];
        //            z += Z[j];
        //        }
        //    }
        //    chmax(ref ans, Abs(x) + Abs(y) + Abs(z));
        //    if (ans == 77)
        //    {
        //        WriteLine(i);
        //    }
        //}
        //WriteLine(ans);



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