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

    int cnt = 0;
    bool[,] B;
    int riku;
    char[,] A;
    void Solve()
    {
        A = new char[10, 10];
        for (int i = 0; i < 10; i++)
        {
            var k = cin.Next;
            for (int j = 0; j < 10; j++)
            {
                A[i, j] = k[j];
                if (k[j] == 'o') cnt++;
            }
        }

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (A[i, j] == 'o') continue;
                A[i, j] = 'o';
                B = new bool[10, 10];
                riku = 0;
                B[i, j] = true;
                dfs(i, j);
                if (riku == cnt)
                {
                    WriteLine("YES");
                    return;
                }
                /*if (i == 5 && j == 4)
                {
                    WriteLine($"{riku} {cnt}");
                }*/
                A[i, j] = 'x';
            }
        }
        WriteLine("NO");
    }
    
    void dfs(int ty, int tx)
    {
        for (int r = 0; r < 4; r++)
        {
            int y = ty + dd[r];
            int x = tx + dd[r + 1];
            if (y < 0 || y >= 10 || x < 0 || x >= 10) continue;
            if (B[y, x]) continue;
            if (A[y, x] == 'x') continue;
            riku++;
            B[y, x] = true;
            dfs(y, x);
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