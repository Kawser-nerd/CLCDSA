using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;
using static System.Console;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;

class Program
{
    static void Main()
    {
        var sw = new StreamWriter(OpenStandardOutput()) { AutoFlush = false };
        SetOut(sw);
        new Program().solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 };
    readonly int mod = 1000000007;
    readonly string alfa = "abcdefghijklmnopqrstuvwxyz";


    void solve()
    {

        var A = cin.scanlong;
        long cnt = 0;

        if (A[0] > 0 && A[3] > 0 && A[4] > 0)
        {
            cnt = Math.Min((A[0] % 2 + A[3] % 2 + A[4] % 2), ((A[0] - 1) % 2 + (A[3] - 1) % 2 + (A[4] - 1) % 2));
        }
        else
        {
            cnt = A[0] % 2 + A[3] % 2 + A[4] % 2;
        }

       
        WriteLine(Math.Max(0, A.Sum() - A[2] - A[5] - A[6] - cnt));
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