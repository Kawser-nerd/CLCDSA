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
        SetIn(new StreamReader("A-large.in"));
        SetOut(new StreamWriter("a_out_1.txt"));
        int T = int.Parse(ReadLine());
        for (int i = 0; i < T; i++)
        {
            Write("Case #" + (i + 1) + ": ");
            new Program().Solve();
        }
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
        int P = cin.Nextint;
        var A = cin.Scanint;

        if (P == 2)
        {
            int odd = 0;
            int even = 0;
            for (int i = 0; i < N; i++)
            {
                if (A[i] % 2 == 0)
                {
                    even++;
                }
                else
                {
                    odd++;
                }
            }
            int ans = even + (odd + 1) / 2;
            WriteLine(ans);
        }
        if (P == 3)
        {
            var B = new int[3];
            for (int i = 0; i < N; i++)
            {
                if (A[i] % 3 == 0)
                {
                    B[0]++;
                }
                else if (A[i] % 3 == 1)
                {
                    B[1]++;
                }
                else
                {
                    B[2]++;
                }
            }
            int ans = B[0] + Math.Min(B[1], B[2]);
            if (B[1] > B[2])
            {
                B[1] -= B[2];
                ans += (B[1] + 2) / 3;
            }
            else if (B[2] > B[1])
            {
                B[2] -= B[1];
                ans += (B[2] + 2) / 3;
            }

            WriteLine(ans);
        }


        if (P == 4)
        {
            var B = new int[4];
            bool flag = false;
            for (int i = 0; i < N; i++)
            {
                if (A[i] % 4 == 0)
                {
                    B[0]++;
                }
                else if (A[i] % 4 == 1)
                {
                    B[1]++;
                }
                else if (A[i] % 4 == 2)
                {
                    B[2]++;
                }
                else
                {
                    B[3]++;
                }
            }
            if (B[2] % 2 == 1)
            {
                flag = true;
            }

            int ans = B[0] + B[2] / 2 + Math.Min(B[1], B[3]);
            if (B[1] == B[3])
            {
                if (flag) ans++;
            }
            else
            {
                int d = Math.Max(B[1], B[3]) - Math.Min(B[1], B[3]);
                if (flag && d >= 2)
                {
                    ans++;
                    d -= 2;
                }
                ans += (d + 3) / 4;
            }

            WriteLine(ans);

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