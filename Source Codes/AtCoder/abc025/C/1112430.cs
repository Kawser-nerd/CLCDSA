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
        SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().Solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 };
    readonly int mod = 1000000007;
    readonly string alfa = "abcdefghijklmnopqrstuvwxyz";

    //?????
    int[,] B, C;
    Dictionary<string, int> D;
    void Solve()
    {
        B = new int[2, 3];
        C = new int[3, 2];
        D = new Dictionary<string, int>();
        int sum = 0;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                B[i, j] = cin.Nextint;
                sum += B[i, j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                C[i, j] = cin.Nextint;
                sum += C[i, j];
            }
        }
        var Z = new int[3, 3];
        int K = Dfs(0, Z);
        WriteLine((sum + K) / 2);
        WriteLine((sum - K) / 2);

    }
    int Dfs(int n, int[,] Z)
    {
        var k = Concat(Z);
        if (D.ContainsKey(k)) return D[k];

        if (n == 9)
        {
            int score = 0;
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (Z[i, j] == Z[i + 1, j]) score += B[i, j];
                    else score -= B[i, j];
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    if (Z[i, j] == Z[i, j + 1]) score += C[i, j];
                    else score -= C[i, j];
                }
            }
            D[k] = score;
            return score;
        }
        int turn = (n % 2 == 0) ? 1 : -1;
        int mark = (n % 2 == 0) ? 1 : 2;
        int maxscore = int.MinValue;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (Z[i, j] != 0) continue;
                Z[i, j] = mark;
                maxscore = Math.Max(maxscore, Dfs(n + 1, Z) * turn);
                Z[i, j] = 0;
            }
        }
        D[k] = maxscore * turn;
        return maxscore * turn;
    }
    string Concat(int[,] Z)
    {
        var s = "";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                s += Z[i, j];
            }
        }
        return s;
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