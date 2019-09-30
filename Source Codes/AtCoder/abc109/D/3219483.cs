using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
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
    Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 }; //????
    readonly int mod = 1000000007;
    void chmax<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? b : a; }
    void chmin<T>(ref T a, T b) where T : IComparable<T> { a = a.CompareTo(b) < 0 ? a : b; }

    void solve()
    {
        int H = cin.nextint;
        int W = cin.nextint;
        var A = new int[H][];
        for (int i = 0; i < H; i++)
        {
            A[i] = cin.scanint;
        }

        int cnt = 0;
        var SB = new StringBuilder();
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (A[i][j] % 2 == 1)
                {
                    if (j == W - 1)
                    {
                        if (i != H - 1)
                        {
                            cnt++;
                            SB.AppendLine($"{i + 1} {j + 1} {i + 2} {j + 1}");
                            A[i + 1][j]++;
                        }
                    }
                    else
                    {
                        cnt++;
                        SB.AppendLine($"{i + 1} {j + 1} {i + 1} {j + 2}");
                        A[i][j + 1]++;
                    }
                }
 
            }
        }
        WriteLine(cnt);
        Write(SB);
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