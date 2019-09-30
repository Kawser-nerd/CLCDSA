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
    Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 }; //????
    readonly int mod = 1000000007;


    void solve()
    {
        int N = cin.nextint;
        var A = new bool[N];
        for (int i = 0; i < N; i++)
        {
            A[i] = (1 == cin.nextint);
        }
        if (A.All(i => i == true) || A.All(i => i == false))
        {
            WriteLine(-1);
            return;
        }

        int id = 0;
        for (; id < N; id++)
        {
            if (A[id] != A[(id - 1 + N) % N]) break;
        }

        int cnt = 1;
        int max = 0;
        int now = id + 1;
        while (id != now % N)
        {
            if (A[now % N] != A[(now - 1) % N])
            {
                max = Math.Max(cnt, max);
                cnt = 1;
            }
            else
            {
                cnt++;
            }
            now++;
        }
        max = Math.Max(cnt, max);

        int ans = 1;
        if(max >= 3)
        {
            ans++;
            max -= 3;
        }
        ans += max / 2;
        WriteLine(ans);
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