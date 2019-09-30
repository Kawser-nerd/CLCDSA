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
        var S = ReadLine();
        int X = cin.nextint + 8000;
        int Y = cin.nextint + 8000;
        int N = S.Length;

        var A = new List<int>();
        var B = new List<int>();

        bool first = true;
        bool modetate = false;
        int cnt = 0;
        for (int i = 0; i <= N; i++)
        {
            if (i == N)
            {
                if (cnt > 0)
                {
                    if (modetate)
                    {
                        B.Add(cnt);
                    }
                    else
                    {
                        A.Add(cnt);
                    }
                }
            }
            else if (first)
            {
                if (S[i] == 'F')
                {
                    X--;
                }
                else
                {
                    first = false;
                    modetate = true;
                    cnt = 0;
                }
            }
            else if (modetate)
            {
                if (S[i] == 'F')
                {
                    cnt++;
                }
                else
                {
                    if (cnt > 0)
                    {
                        B.Add(cnt);
                    }
                    modetate = false;
                    cnt = 0;
                }
            }
            else
            {
                if (S[i] == 'F')
                {
                    cnt++;
                }
                else
                {
                    if (cnt > 0)
                    {
                        A.Add(cnt);
                    }
                    modetate = true;
                    cnt = 0;
                }
            }

        }
        //WriteLine();
        //WriteLine(X + " " +  Y);
        //WriteLine(string.Join(" ", A.ToArray()));
        //WriteLine(string.Join(" ", B.ToArray()));

        var J = new bool[A.Count + 1, 16000 + 1];
        J[0, 8000] = true;
        for (int i = 0; i < A.Count; i++)
        {
            for (int j = 0; j < 16000 + 1; j++)
            {
                if (J[i, j])
                {
                    //WriteLine(i + " " + j + " " + A[i] + "x");
                    J[i + 1, j + A[i]] = true;
                    J[i + 1, j - A[i]] = true;
                }
            }
        }
        var K = new bool[B.Count + 1, 16000 + 1];
        K[0, 8000] = true;
        for (int i = 0; i < B.Count; i++)
        {
            for (int j = 0; j < 16000 + 1; j++)
            {
                if (K[i, j])
                {
                    //WriteLine(i + " " + j + " " + B[i] + "y");
                    K[i + 1, j + B[i]] = true;
                    K[i + 1, j - B[i]] = true;
                }
            }
        }

        if (X < 0)
        {
            WriteLine("No");
        }
        else if (J[A.Count, X] && K[B.Count, Y])
        {
            WriteLine("Yes");
        }
        else
        {
            WriteLine("No");
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