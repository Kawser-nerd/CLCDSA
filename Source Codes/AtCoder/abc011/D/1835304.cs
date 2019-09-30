using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;
using static System.Console;
//using System.Numerics;
//using static System.Math;

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
        long N = cin.nextint;
        var D = cin.nextlong;
        var X = cin.nextlong;
        var Y = cin.nextlong;

        if (X % D != 0 || Y % D != 0)
        {
            WriteLine(0);
            return;
        }

        long diff = Y / D;
        double ans = 0;
        for (long i = 0; i <= N; i++)
        {
            //???j,k,l ?????
            long j = (i * D - X) / D;
            if (((N - i - j) + diff) % 2 == 1) continue;
            long k = ((N - i - j) + diff) / 2;
            long l = k - diff;
            if (j < 0 || k < 0 || l < 0) continue;
            if(i + j + k + l == N)
            {
                double tmp = 1;
                for (int t = 1; t <= N; t++)
                {
                    tmp *= t;
                    if (t <= i) tmp /= t;
                    else if (t <= i + j) tmp /= t - i;
                    else if (t <= i + j + k) tmp /= t - i - j;
                    else tmp /= t - i - j - k;
                    tmp /= 4;
                }
                ans += tmp;
            }
        }
        WriteLine(ans.ToString("F10"));
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