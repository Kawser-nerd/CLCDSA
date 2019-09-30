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
        //a2 ???????a1????????????
        int N = cin.nextint;
        var A = cin.scanint;
        int min = int.MaxValue; int minid = -1;
        int max = int.MinValue; int maxid = -1;

        for (int i = 0; i < N; i++)
        {
            if (A[i] < min)
            {
                min = A[i];
                minid = i;
            }
            if (max < A[i])
            {
                max = A[i];
                maxid = i;
            }
        }
        var sb = new StringBuilder();
        int cnt = 0;
        int mode = -1;
        if (0 <= min)
        {
            mode = 1;
        }
        else if (max <= 0)
        {
            mode = 2;
        }
        else
        {
            if (Math.Abs(min) <= Math.Abs(max))
            {
                mode = 1;
                for (int i = 0; i < N; i++)
                {
                    if (A[i] < 0)
                    {
                        A[i] += max;
                        sb.AppendLine($"{maxid + 1} {i + 1}");
                        cnt++;
                    }
                }
            }
            else
            {
                mode = 2;
                for (int i = 0; i < N; i++)
                {
                    if (A[i] > 0)
                    {
                        A[i] += min;
                        sb.AppendLine($"{minid + 1} {i + 1}");
                        cnt++;
                    }
                }
            }
        }
        if (mode == 1)
        {
            for (int i = 1; i < N; i++)
            {
                if (A[i - 1] <= A[i]) continue;
                while (A[i - 1] > A[i])
                {
                    A[i] += A[i - 1];
                    sb.AppendLine($"{i} {i + 1}");
                    cnt++;
                }
            }
        }
        else
        {
            for (int i = N - 1; i >= 1; i--)
            {
                if (A[i - 1] <= A[i]) continue;
                while (A[i - 1] > A[i])
                {
                    A[i - 1] += A[i];
                    sb.AppendLine($"{i + 1} {i}");
                    cnt++;
                }
            }
        }
        WriteLine(cnt);
        Write(sb);
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