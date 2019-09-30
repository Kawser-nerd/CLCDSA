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
using pair = Pair<long, long>;
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


    void solve()
    {
        int K = cin.nextint;
        var A = cin.scanlong;
        Array.Reverse(A);
        if (A[0] != 2)
        {
            WriteLine(-1);
            return;
        }
        var dp = new pair[K];

        for (int i = 0; i < K; i++)
        {
            if (i == 0)
            {
                dp[i] = new pair(2, 3);
            }
            else
            {
                long min = -1;
                //if (dp[i - 1].f < A[i])
                //{
                //    if (A[i] > dp[i - 1].s)
                //    {
                //        WriteLine(-1);
                //        return;
                //    }
                //    min = A[i];
                //}
                //else if (dp[i - 1].f == A[i])
                //{
                //    min = A[i];
                //}
                //else
                //{
                //    var d = (dp[i - 1].f + A[i] - 1) / A[i];
                //    if (A[i] * d > dp[i - 1].s)
                //    {
                //        WriteLine(-1);
                //        return;
                //    }
                //    min = A[i] * d;
                //}
                var d = (dp[i - 1].f + A[i] - 1) / A[i];
                if (A[i] * d > dp[i - 1].s)
                {
                    WriteLine(-1);
                    return;
                }
                min = A[i] * d;

                long max = -1;
                if (dp[i - 1].s < A[i])
                {
                    WriteLine(-1);
                    return;
                }
                else if (dp[i - 1].s == A[i])
                {
                    max = A[i] + (A[i] - 1);
                }
                else // A[i] < dp[i - 1].s
                {
                    var t = dp[i - 1].s / A[i];
                    if (A[i] * t < dp[i - 1].f)
                    {
                        WriteLine(-1);
                        return;
                    }
                    max = A[i] * t + (A[i] - 1);
                }
                dp[i] = new pair(min, max);
            }
        }
        WriteLine(dp[K - 1].ToString());
    }

}

class Pair<T, U> : IComparable<Pair<T, U>> where T : IComparable<T> where U : IComparable<U>
{
    public T f;
    public U s;
    public Pair(T f, U s)
    {
        this.f = f;
        this.s = s;
    }
    public int CompareTo(Pair<T, U> a)
    {
        return f.CompareTo(a.f) != 0 ? f.CompareTo(a.f) : s.CompareTo(a.s);
    }
    public override string ToString()
    {
        return f + " " + s;
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