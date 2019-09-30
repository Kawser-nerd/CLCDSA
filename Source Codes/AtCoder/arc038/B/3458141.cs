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
        //SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().solve();
        Out.Flush();
    }
    readonly Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 }; //????
    readonly int mod = 1000000007;
    void chmax<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? b : a; }
    void chmin<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? a : b; }

    int H, W;
    int[][] memo;
    char[][] S;

    //???????????1, ????-1
    int calc(int y, int x)
    {
        if (memo[y][x] != 0)
        {
            return memo[y][x];
        }
        int ret = -1;
        if (y + 1 < H && S[y + 1][x] != '#' && calc(y + 1, x) == -1)
        {
            ret = 1;
        }
        if (x + 1 < W && S[y][x + 1] != '#' && calc(y, x + 1) == -1)
        {
            ret = 1;
        }
        if (y + 1 < H && x + 1 < W && S[y + 1][x + 1] != '#' && calc(y + 1, x + 1) == -1)
        {
            ret = 1;
        }

        return memo[y][x] = ret;
    }
    void solve()
    {
        H = cin.nextint;
        W = cin.nextint;

        S = new char[H][];
        memo = new int[H][];
        for (int i = 0; i < H; i++)
        {
            S[i] = ReadLine().ToCharArray();
            memo[i] = new int[W];
        }

        if(calc(0, 0) == 1)
        {
            WriteLine("First");
        }
        else
        {
            WriteLine("Second");
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