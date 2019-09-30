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
        int N = cin.nextint;
        int L = cin.nextint;
        var S = new string[L + 1];
        for (int i = 0; i < L + 1; i++)
        {
            S[i] = ReadLine();
        }
        int x = -1;
        for (int i = L; i >= 0; i--)
        {
            if (i == L)
            {
                for (int j = 0; j < S[i].Length; j++)
                {
                    if (S[i][j] == 'o')
                    {
                        x = j;
                        break;
                    }
                }
            }
            else
            {
                if (0 <= x - 1 && S[i][x - 1] == '-')
                {
                    x -= 2;
                }
                else if (x + 1 < S[i].Length && S[i][x + 1] == '-')
                {
                    x += 2;
                }
            }
            //WriteLine(x);
        }
        WriteLine(x/ 2 + 1);
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