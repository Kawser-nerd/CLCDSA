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
        var A = new Tuple<int, int, int>[N];
        var P = new List<Tuple<int, int, int>>();
        var Q = new List<pair>();
        var R = new List<pair>();


        for (int i = 0; i < N; i++)
        {
            int l = cin.nextint;
            int r = cin.nextint;
            A[i] = new Tuple<int, int, int>(l, r, i);
            //if (r < 0)
            //{
            //    P.Add(new pair(l, r));
            //}
            //else if (0 < l)
            //{
            //    Q.Add(new pair(l, r));
            //}
            //else
            //{
            //    R.Add(new pair(l, r));
            //}
        }

       // WriteLine($"P.Count={P.Count} Q.Count={Q.Count} R.Count={R.Count}");
        var B = A.OrderBy(i => i.Item2).ToArray();
        var C = A.OrderBy(i => -i.Item1).ToArray();

        var J = new bool[N];
        int now = 0;
        int b = 0;
        int c = 0;
        long ans = 0;

        //WriteLine();
        //B????????????
        for (int i = 0; i < N; i++)
        {
            int nl, nr;
            if (i % 2 == 0)
            {
                while (J[B[b].Item3]) b++;
                nl = B[b].Item1;
                nr = B[b].Item2;
                J[B[b].Item3] = true;
                //Write(nl + " " + nr + " " + B[b].Item3);
            }
            else
            {
                while (J[C[c].Item3]) c++;
                nl = C[c].Item1;
                nr = C[c].Item2;
                J[C[c].Item3] = true;
                //Write(nl + " " + nr + " " + C[c].Item3);
            }

            if (now < nl)
            {
                ans += nl - now;
                now = nl;
            }
            else if (nr < now)
            {
                ans += now - nr;
                now = nr;
            }
            //WriteLine(" " + ans);
            
        }
        var ret = ans + Math.Abs(now);

        //WriteLine();
        J = new bool[N];
        now = 0;
        b = 0;
        c = 0;
        ans = 0;
        //C??
        for (int i = 0; i < N; i++)
        {
            int nl, nr;
            if (i % 2 != 0)
            {
                while (J[B[b].Item3]) b++;
                nl = B[b].Item1;
                nr = B[b].Item2;
                J[B[b].Item3] = true;
                //WriteLine(nl + " " + nr + " " + B[b].Item3);
            }
            else
            {
                while (J[C[c].Item3]) c++;
                nl = C[c].Item1;
                nr = C[c].Item2;
                J[C[c].Item3] = true;
                //WriteLine(nl + " " + nr + " " + C[c].Item3);
            }

            if (now < nl)
            {
                ans += nl - now;
                now = nl;
            }
            else if (nr < now)
            {
                ans += now - nr;
                now = nr;
            }

        }

        chmax(ref ret, ans + Math.Abs(now));
        WriteLine(ret);
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