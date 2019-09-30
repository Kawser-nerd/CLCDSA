using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;

class Problem
{
    const string inFile = "..\\..\\dsmall.in";
    const string outFile = "..\\..\\dsmall.out";
    const int INF = 987654321;

    public void Process()
    {
        using (StreamReader sr = new StreamReader(inFile))
        {
            using (StreamWriter sw = new StreamWriter(outFile))
            {
                int numCases = int.Parse(sr.ReadLine());
                Console.WriteLine("There are {0} test cases.", numCases);
                for (int @case = 1; @case <= numCases; @case++)
                {
                    int[] ss = Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), int.Parse);

                    int m = ss[0];
                    int n = ss[1];
                    int r = ss[2];
                    bool[,] a = new bool[m, n];
                    for (int i = 0; i < r; i++)
                    {
                        ss = Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), int.Parse);
                        a[ss[0]-1, ss[1]-1] = true;
                    }

                    string res = Solve(m, n, a);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }

    int[,] f;
    int m, n;
    bool[,] a;

    void init()
    {
        int l0 = f.GetLength(0);
        int l1 = f.GetLength(1);
        for (int i = 0; i < l0; i++)
        {
            for (int j = 0; j < l1; j++)
            {
                f[i, j] = -1;
            }
        }
    }

    const int Mod = 10007;

    int calc(int x, int y)
    {
        if (x >= m || y >= n) return 0;
        if (x == m - 1 && y == n - 1) return 1;
        if (a[x,y]) return 0;

        if (f[x, y] != -1) return f[x, y];
        int res = 0;
        
        res = (res + calc(x + 2, y + 1)) % Mod;
        res = (res + calc(x + 1, y + 2)) % Mod;

        return f[x, y] = res;
    }

    string Solve(int m, int n, bool[,] a)
    {
        this.a = a;
        this.m = m;
        this.n = n;
        f = new int[m, n];
        init();
        int res = calc(0, 0);
        return res.ToString();
    }

    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}