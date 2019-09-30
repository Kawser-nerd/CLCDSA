using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Globalization;
using System.Diagnostics;
using static System.Console;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;

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


    void Solve()
    {
        int N = cin.Nextint;
        var S = new char[N][];
        for (int i = 0; i < N; i++)
        {
            S[i] = cin.Next.OrderBy(j => j).ToArray();
        }

        string ans = "";

        var M = new int[N];

      
        while (M[0] < S[0].Length)
        {
            var u = S[0][M[0]];
            bool flag = true;
            for (int i = 1; i < N; i++)
            {
                while(M[i] < S[i].Length && S[i][M[i]] < u)
                {
                    M[i]++;
                }
                if (M[i] >= S[i].Length)
                {
                    flag = false;
                    break;
                }

                if (S[i][M[i]] > u)
                {
                    flag = false;
                    break;
                }

            }
            if (flag)
            {
                M = M.Select(i => i + 1).ToArray();
                ans += u;
            }
            else
            {
                M[0]++;
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