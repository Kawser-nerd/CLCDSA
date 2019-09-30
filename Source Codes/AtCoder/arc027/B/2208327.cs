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
        var X = ReadLine();
        var Y = ReadLine();

        var A = new Dictionary<char, char>();
        //var B = new Dictionary<char, char>();
        for (int i = 0; i < N; i++)
        {
            if ('0' <= X[i] && X[i] <= '9')
            {
                A[X[i]] = X[i];
                A[Y[i]] = X[i];
            }
            else if ('0' <= Y[i] && Y[i] <= '9')
            {
                A[X[i]] = Y[i];
                A[Y[i]] = Y[i];
            }
        }

        long ans = 1;
        for (int i = 0; i < N; i++)
        {
            bool flag = true;
            while (flag)
            {
                flag = false;
                for (int j = 0; j < N; j++)
                {
                    if (A.ContainsKey(X[j]) && !A.ContainsKey(Y[j]))
                    {
                        A[Y[j]] = A[X[j]];
                        flag = true;
                    }
                    else if (!A.ContainsKey(X[j]) && A.ContainsKey(Y[j]))
                    {
                        A[X[j]] = A[Y[j]];
                        flag = true;
                    }
                }
            }
            if (i == 0)
            {
                if (!A.ContainsKey(X[i]) && !A.ContainsKey(Y[i]))
                {
                    A[X[i]] = '!';
                    A[Y[i]] = '!';
                    ans = 9;
                }

            }
            else
            {
                if (!A.ContainsKey(X[i]) && !A.ContainsKey(Y[i]))
                {
                    A[X[i]] = '?';
                    A[Y[i]] = '?';
                    ans *= 10;
                }
            }
        }

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