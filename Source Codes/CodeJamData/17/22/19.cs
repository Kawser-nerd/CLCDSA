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
        SetIn(new StreamReader("B-small-attempt2.in"));
        SetOut(new StreamWriter("B_out.txt"));
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

    int N, R, Y, B ,O, G, V;
    void Solve()
    {
        N = cin.Nextint;
        R = cin.Nextint;
        O = cin.Nextint;
        Y = cin.Nextint;
        G = cin.Nextint;
        B = cin.Nextint;
        V = cin.Nextint;

        var Z = new int[N];

        for (int i = 0; i < N; i++)
        {
            if (i == 0)
            {
                if (R >= Y && R >= B)
                {
                    R--;
                    Z[i] = 1;
                }
                else if (Y >= R && Y >= B)
                {
                    Y--;
                    Z[i] = 2;
                }
                else
                {
                    B--;
                    Z[i] = 3;
                }           
            }
            else
            {
                if (Z[0] == 1)
                {
                    if (Z[i - 1] == 1)
                    {
                        if(Y == 0 && B == 0)
                        {
                            WriteLine("IMPOSSIBLE");
                            return;
                        }
                        if (Y >= B)
                        {
                            Y--;
                            Z[i] = 2;
                        }
                        else
                        {
                            B--;
                            Z[i] = 3;
                        }

                    }
                    else if (Z[i - 1] == 2)
                    {
                        if (R == 0 && B == 0)
                        {
                            WriteLine("IMPOSSIBLE");
                            return;
                        }
                        if (R >= B)
                        {
                            R--;
                            Z[i] = 1;
                        }
                        else
                        {
                            B--;
                            Z[i] = 3;
                        }
                    }
                    else
                    {
                        if (Y == 0 && R == 0)
                        {
                            WriteLine("IMPOSSIBLE");
                            return;
                        }
                        if (R >= Y)
                        {
                            R--;
                            Z[i] = 1;
                        }
                        else
                        {
                            Y--;
                            Z[i] = 2;
                        }
                    }
                }
                else if (Z[0] == 2)
                {
                    if (Z[i - 1] == 1)
                    {
                        if (Y == 0 && B == 0)
                        {
                            WriteLine("IMPOSSIBLE");
                            return;
                        }
                        if (Y >= B)
                        {
                            Y--;
                            Z[i] = 2;
                        }
                        else
                        {
                            B--;
                            Z[i] = 3;
                        }

                    }
                    else if (Z[i - 1] == 2)
                    {
                        if (R == 0 && B == 0)
                        {
                            WriteLine("IMPOSSIBLE");
                            return;
                        }
                        if (R >= B)
                        {
                            R--;
                            Z[i] = 1;
                        }
                        else
                        {
                            B--;
                            Z[i] = 3;
                        }
                    }
                    else
                    {
                        if (Y == 0 && R == 0)
                        {
                            WriteLine("IMPOSSIBLE");
                            return;
                        }
                        if (Y >= R)
                        {
                            Y--;
                            Z[i] = 2;
                        }
                        else
                        {
                            R--;
                            Z[i] = 1;
                        }
                    }
                }
                else
                {
                    if (Z[i - 1] == 1)
                    {
                        if (Y == 0 && B == 0)
                        {
                            WriteLine("IMPOSSIBLE");
                            return;
                        }
                        if (Y > B)
                        {
                            Y--;
                            Z[i] = 2;
                        }
                        else
                        {
                            B--;
                            Z[i] = 3;
                        }

                    }
                    else if (Z[i - 1] == 2)
                    {
                        if (R == 0 && B == 0)
                        {
                            WriteLine("IMPOSSIBLE");
                            return;
                        }
                        if (R > B)
                        {
                            R--;
                            Z[i] = 1;
                        }
                        else
                        {
                            B--;
                            Z[i] = 3;
                        }
                    }
                    else
                    {
                        if (Y == 0 && R == 0)
                        {
                            WriteLine("IMPOSSIBLE");
                            return;
                        }
                        if (R >= Y)
                        {
                            R--;
                            Z[i] = 1;
                        }
                        else
                        {
                            Y--;
                            Z[i] = 2;
                        }
                    }
                }
            }
           
        }
        if (Z[0] == Z[N -1])
        {
            WriteLine("IMPOSSIBLE");
            return;
        }
        foreach (var item in Z)
        {
            if (item == 1)
            {
                Write("R");
            }
            else if (item == 2)
            {
                Write("Y");
            }
            else
            {
                Write("B");
            }
        }
        WriteLine();
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