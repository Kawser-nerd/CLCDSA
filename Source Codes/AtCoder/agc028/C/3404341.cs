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
using pair = Pair<int, int>;

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
        var ID = new int[2 * N];
        var P = new int[2 * N];
        var J = new pair[N];
        long red = 0;
        long blue = 0;
        for (int i = 0; i < N; i++)
        {
            ID[2 * i] = i;
            ID[2 * i + 1] = i;
            P[2 * i] = cin.nextint;
            P[2 * i + 1] = cin.nextint;
            red += P[2 * i];
            blue += P[2 * i + 1];
            J[i] = new pair(P[2 * i], P[2 * i + 1]);
        }

        long ans = Math.Min(red, blue);
        Array.Sort(P, ID);
        var cnt = new int[N];

        long sum = 0;
        for (int i = 0; i < N; i++)
        {
            cnt[ID[i]]++;
            sum += P[i];
        }

        for (int i = 0; i < N; i++)
        {
            if (cnt[i] == 2)
            {
                chmin(ref ans, sum);
            }
            else if (cnt[i] == 1)
            {
                if (ID[N - 1] == i)
                {
                    chmin(ref ans, sum - P[N - 2] + Math.Max(J[i].f, J[i].s));
                }
                else
                {
                    chmin(ref ans, sum - P[N - 1] + Math.Max(J[i].f, J[i].s));
                }
            }
            else
            {
                chmin(ref ans, sum - P[N - 1] - P[N - 2] + J[i].f + J[i].s);
            }
        }

        WriteLine(ans);
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
    public string join<T>(IEnumerable<T> values) { return string.Join(" ", values); }
}