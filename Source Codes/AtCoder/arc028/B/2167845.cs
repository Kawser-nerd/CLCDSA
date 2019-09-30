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
        SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 }; //????
    readonly int mod = 1000000007;


    void solve()
    {
        int N = cin.nextint;
        int K = cin.nextint;
        var A = cin.scanint;
        var J = new int[N];
        for (int i = 0; i < N; i++)
        {
            A[i]--;
            J[A[i]] = i + 1;
        }

        //K????Set
        var H = new SortedSet<int>();
        for (int i = 0; i < K; i++)
        {
            H.Add(-A[i]);
        }
        var L = -H.First();
        WriteLine(J[L]);


        for (int i = K; i < N; i++)
        {
            if (A[i] < L)
            {
                H.Remove(-L);
                H.Add(-A[i]);
                L = -H.First();
            }
            WriteLine(J[L]);
        }

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