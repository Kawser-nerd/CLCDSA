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
        new Program().Solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    Random rnd = new Random();
    Stopwatch sw = new Stopwatch();
    readonly int[] dd = { 0, 1, 0, -1, 0 };
    readonly int mod = 1000000007;
    readonly string alfa = "abcdefghijklmnopqrstuvwxyz";

    int N;
    int[] A;
    void Solve()
    {
        N = cin.Nextint;
        A = cin.Scanint;
        Array.Sort(A);
        if (A[N - 1] - A[0] >= 2)
        {
            WriteLine("No");
            return;
        }
        //int need = A[0];
        if (A[0] == A[N - 1] && A[0] == 1)
        {
            WriteLine("Yes");
            return;
        }

        Array.Reverse(A);
        int cnt = 0;
        int dnt = 0;
        for (int i = 0; i < N; i++)
        {
            if (A[i] == A[0]) cnt++;
            else dnt++;
        }

        if (dnt == 0)
        {
            if (cnt == A[0] + 1 || cnt >= A[0] * 2)
            {
                WriteLine("Yes");
                return;
            }
            else
            {
                WriteLine("No");
                return;
            }
        }



        if (cnt >= 2)
        {
            if (dnt == A[0] - 1)
            {
                WriteLine("Yes");
                return;
            }
            if (dnt == 1 && cnt >= (A[0] - 1) * 2)
            {
                WriteLine("Yes");
                return;
            }
            if (dnt < A[0] - 1 && cnt >= (A[0] - dnt) * 2)
            {
                WriteLine("Yes");
                return;
            }

            else
            {
                WriteLine("No");
                return;
            }
        }




        if (cnt == 1)
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
    public string[] Scan { get { return ReadLine().Split(); } }
    public int[] Scanint { get { return Array.ConvertAll(Scan, int.Parse); } }
    public long[] Scanlong { get { return Array.ConvertAll(Scan, long.Parse); } }
    public double[] Scandouble { get { return Array.ConvertAll(Scan, double.Parse); } }
    public string Next
    {
        get
        {
            if (i < s.Length) return s[i++];
            string st = ReadLine();
            while (st == "") st = ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
            return Next;
        }
    }
    public int Nextint { get { return int.Parse(Next); } }
    public long Nextlong { get { return long.Parse(Next); } }
    public double Nextdouble { get { return double.Parse(Next); } }
}