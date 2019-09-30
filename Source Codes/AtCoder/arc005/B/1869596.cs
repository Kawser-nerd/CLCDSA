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
        int x = cin.nextint - 1;
        int y = cin.nextint - 1;
        var W = cin.next;
        var S = new string[9];
        for (int i = 0; i < 9; i++)
        {
            S[i] = cin.next;
        }
        int dy = 0, dx = 0;
        if (W == "R")
        {
            dx = 1;
        }
        if (W == "L")
        {
            dx = -1;
        }
        if (W == "U")
        {
            dy = -1;
        }
        if (W == "D")
        {
            dy = 1;
        }
        if (W == "RU")
        {
            dx = 1;
            dy = -1;
        }
        if (W == "RD")
        {
            dx = 1;
            dy = 1;
        }
        if (W == "LU")
        {
            dx = -1;
            dy = -1;
        }
        if (W == "LD")
        {
            dx = -1;
            dy = 1;
        }

        for (int i = 0; i < 4; i++)
        {
            Write(S[y][x]);

            int ty = y + dy;
            int tx = x + dx;
            if (ty < 0 || ty >= 9 || tx < 0 || tx >= 9)
            {
                if (ty < 0 || ty >= 9)
                {
                    dy *= -1;
                }
                if (tx < 0 || tx >= 9)
                {
                    dx *= -1;
                }
                ty = y + dy;
                tx = x + dx;
            }
            y = ty;
            x = tx;
        }
        WriteLine();
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