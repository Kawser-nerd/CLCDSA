using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;
using static System.Console;
//using System.Numerics;
using static System.Math;

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
        int N = cin.nextint;
        var T = cin.scanint;
        var V = cin.scanint;
        V = V.Concat(new int[] { 0 }).ToArray();
        var time = T.Sum();

        var B = new int[N + 1];
        B[N] = 0;
        int nowtime = 0;
        for (int i = N - 1; i >= 1; i--)
        {
            nowtime += T[i];
            int limit = Min(V[i], V[i - 1]);
            B[i] = Min(B[i + 1] + T[i], limit);
        }

        int speed = 0;
        double ans = 0;
        for (int i = 0; i < N; i++)
        {

            int nextspeed = Min(Min(V[i], V[i + 1]), Min(B[i + 1], speed + T[i]));
            var a = (T[i] + nextspeed - speed) / (double)2;
            var b = T[i] - a;
            var maxspeed = speed + a;
            if (maxspeed > V[i])
            {
                ans -= (maxspeed - V[i]) * (maxspeed - V[i]);
            }
            ans += (speed + maxspeed) * a / 2 + (maxspeed + nextspeed) * b / 2;

            speed = nextspeed;
        }
        WriteLine(ans.ToString("F4"));
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