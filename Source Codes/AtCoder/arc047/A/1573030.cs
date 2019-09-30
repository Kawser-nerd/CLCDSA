using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Globalization;
using System.Diagnostics;
using static System.Console;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;
//using System.Numerics;

class Program
{
    static void Main()
    {
        //SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    Random rnd = new Random();
    Stopwatch sw = new Stopwatch();
    readonly int[] dd = { 0, 1, 0, -1, 0 };
    readonly int mod = 1000000007;
    readonly string alfa = "abcdefghijklmnopqrstuvwxyz";
    readonly string ALFA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int N;
    void solve()
    {
        N = cin.nextint;
        int L = cin.nextint;
        var S = cin.next;
        int tab = 1;
        int cnt = 0;
        for (int i = 0; i < N; i++)
        {
            if (S[i] == '+')
            {
                tab++;
            }
            else
            {
                tab--;
            }
            if (tab > L)
            {
                cnt++;
                tab = 1;
            }
            
        }
        WriteLine(cnt);
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