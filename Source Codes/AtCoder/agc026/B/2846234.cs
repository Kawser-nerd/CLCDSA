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
        SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
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
        int T = cin.nextint;
        for (int i = 0; i < T; i++)
        {
            var A = cin.nextlong;
            var B = cin.nextlong;
            var C = cin.nextlong;
            var D = cin.nextlong;
            WriteLine(calc(A, B, C, D));
        }
    }

    string calc(long A, long B, long C, long D)
    {
        if (A < B || D < B) return "No";
        if (C >= B - 1) return "Yes";

        //??1??B-1????
        //????????
        //??C+1??B-1????

        var N = A % B;
        var M = D % B;


        var L = C + 1 - N;
        while (L < 0) L += B;
        var R = B - 1 - N;
        while (R < L) R += B;
        if (M == 0)
        {
            if (C + 1 <= N && N <= B - 1)
            {
                return "No";
            }
            else
            {
                return "Yes";
            }
        }
        if (R - L + 1 >= M) return "No";


        var K = M;
        long r = N;
        var H = new HashSet<long>();
        H.Add(r);
        while (true)
        {
            var X = (C + 1 - r + M - 1) / M;
            var Z = M * X + r;
            if (C + 1 <= Z && Z <= B - 1) return "No";
            var Y = (B - r + M - 1) / M;
            var W = M * Y + r;
            r = W % B;
            if (H.Contains(r)) return "Yes";
            H.Add(r);
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