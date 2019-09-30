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
        SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().solve();
        Out.Flush();
    }
    readonly Scanner cin = new Scanner();
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
        double A = cin.nextint;
        double B = cin.nextint;
        if (A < B)
        {
            swap(ref A, ref B);
        }
        int N = cin.nextint;

        for (int i = 0; i < N; i++)
        {
            double C = cin.nextint;
            double D = cin.nextint;


            if ((A <= C && B <= D) || (A <= D && B <= C))
            {
                WriteLine("YES");
                continue;
            }

            if (D < C)
            {
                swap(ref C, ref D);
            }
            double l = 0;
            double r = Acos(B / Sqrt(A * A + B * B));
            //WriteLine(l + " " + (r / PI * 180));
            for (int j = 0; j < 100; j++)
            {
                var mid = (l + r) / 2;
                var height = A * Sin(mid) + B * Cos(mid);
                if (height < D)
                {
                    l = mid;
                }
                else
                {
                    r = mid;
                }
            }

            var width = A * Cos(r) + B * Sin(r);
            if (width <= C)
            {
                WriteLine("YES");
            }
            else
            {
                WriteLine("NO");
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