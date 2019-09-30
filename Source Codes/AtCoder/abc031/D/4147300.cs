using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using SB = System.Text.StringBuilder;
//using System.Text.RegularExpressions;
//using System.Globalization;
//using System.Diagnostics;
using static System.Console;
using System.Numerics;
using static System.Math;
using pair = Pair<long, long>;

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
    readonly int dom = 998244353;
    bool chmax<T>(ref T a, T b) where T : IComparable<T> { if (a.CompareTo(b) < 0) { a = b; return true; } return false; }
    bool chmin<T>(ref T a, T b) where T : IComparable<T> { if (b.CompareTo(a) < 0) { a = b; return true; } return false; }

    void solve()
    {
        int K = cin.nextint;
        int N = cin.nextint;
        var V = new string[N];
        var W = new string[N];
        for (int i = 0; i < N; i++)
        {
            V[i] = cin.next;
            W[i] = cin.next;
        }

        int S = 1;
        for (int i = 0; i < K; i++)
        {
            S *= 3;
        }


        for (int s = 0; s < S; s++)
        {
            var D = new int[K];
            int t = s;
            for (int i = 0; i < K; i++)
            {
                D[i] = t % 3 + 1;
                t /= 3;
            }

            var ANS = new string[K];
            
            for (int i = 0; i < N; i++)
            {
                int idx = 0;
                foreach (var v in V[i])
                {
                    int n = v - '1';
                    if (idx + D[n] > W[i].Length)
                    {
                        goto label;
                    }
                    var tmp = W[i].Substring(idx, D[n]);

                    if(ANS[n] != default(string) && ANS[n] != tmp)
                    {
                        goto label;
                    }

                    ANS[n] = tmp;
                    idx += D[n];
                }
                if (idx != W[i].Length)
                {
                    goto label;
                }
            }
            foreach (var item in ANS)
            {
                if (item == default(string))
                {
                    WriteLine('a');
                }
                else
                {
                    WriteLine(item);
                }
            }
            return;
           
            label:;
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
        return $"{f} {s}";
    }
}

static class Ex
{
    public static void join<T>(this IEnumerable<T> values) { WriteLine(string.Join(" ", values)); }
    public static string join<T>(this IEnumerable<T> values, string sep) { return string.Join(sep, values); }
    public static string concat<T>(this IEnumerable<T> values) { return string.Concat(values); }
    public static string reverse(this string s) { return s.Reverse().concat(); }

    public static int lower_bound<T>(this IList<T> arr, T val) where T : IComparable<T>
    {
        int low = 0, high = arr.Count();
        int mid;

        while (low < high)
        {
            mid = ((high - low) >> 1) + low;
            if (arr[mid].CompareTo(val) < 0) low = mid + 1;
            else high = mid;
        }
        return low;
    }
    public static int upper_bound<T>(this IList<T> arr, T val) where T : IComparable<T>
    {
        int low = 0, high = arr.Count();
        int mid;

        while (low < high)
        {
            mid = ((high - low) >> 1) + low;
            if (arr[mid].CompareTo(val) <= 0) low = mid + 1;
            else high = mid;
        }
        return low;
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
}