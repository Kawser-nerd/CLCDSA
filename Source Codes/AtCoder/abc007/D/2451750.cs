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
        //?dp
        var A = cin.next;
        var B = cin.next;

        var dpr = new long[B.Length + 1, 2, 2];//pos, less, have4||have9
        dpr[0, 0, 0] = 1;
        for (int i = 0; i < B.Length; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int lim = (j == 1) ? 9 : B[i] - '0';
                for (int k = 0; k < 2; k++)
                {
                    for (int d = 0; d <= lim; d++)
                    {
                        dpr[i + 1, (j == 1 || d < lim) ? 1 : 0, (k == 1 || d == 4 || d == 9) ? 1 : 0] += dpr[i, j, k];
                    }
                }

            }
        }

        var dpl = new long[A.Length + 1, 2, 2];//pos, less, have4||have9
        dpl[0, 0, 0] = 1;
        for (int i = 0; i < A.Length; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int lim = (j == 1) ? 9 : A[i] - '0';
                for (int k = 0; k < 2; k++)
                {
                    for (int d = 0; d <= lim; d++)
                    {
                        dpl[i + 1, (j == 1 || d < lim) ? 1 : 0, (k == 1 || d == 4 || d == 9) ? 1 : 0] += dpl[i, j, k];
                    }
                }

            }
        }

        //A???????less = 0????? 
        WriteLine(dpr[B.Length, 0, 1] + dpr[B.Length, 1, 1] - dpl[A.Length, 1, 1]);

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