using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;

class Problem
{
    const string inFile = "..\\..\\csmall.in";
    const string outFile = "..\\..\\csmall.out";
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
                    string[] a = new string[m];
                    for (int i = 0; i < m; i++)
                    {
                        string s = sr.ReadLine();
                        a[i] = s;
                    }

                    string res = Solve(m, n, a);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }

    string[] a;

    int[, , ,] f;
    int m, n;

    void init()
    {
        int l0 = f.GetLength(0);
        int l1 = f.GetLength(1);
        int l2 = f.GetLength(2);
        int l3 = f.GetLength(3);
        for (int i = 0; i < l0; i++)
        {
            for (int j = 0; j < l1; j++)
            {
                for (int u = 0; u < l2; u++)
                {
                    for (int v = 0; v < l3; v++)
                    {
                        f[i, j, u, v] = -1;
                    }
                }
            }
        }
    }

    bool on(int x, int bit)
    {
        return (x & (1 << bit)) > 0;
    }

    int turnOn(int x, int bit)
    {
        return x | (1 << bit);
    }

    int turnOff(int x, int bit)
    {
        return x & ~(1 << bit);
    }

    int calc(int mask, int left, int x, int y)
    {
        if (y >= n)
        {
            x++;
            y = 0;
        }

        if (x >= m)
        {
            return 0;
        }

        if (f[mask, left, x, y] != -1) return f[mask, left, x, y];
        int res = 0;

        if (y == 0)
        {
            res = calc(mask, 0, x, y+1);

            if (a[x][y] == '.' && !on(mask, 1))
            {
                res = Math.Max(res, 1 + calc(mask, 1, x, y+1));
            }
        }
        else if (y == n - 1)
        {
            int nmask = mask;
            if (left == 1)
                nmask = turnOn(nmask, n-2);
            if (on(nmask, n-1))
            {
                nmask = turnOff(nmask, n-1);
            }
            res = calc(nmask, 0, x+1, 0);

            if (a[x][y] == '.' && left == 0 && !on(mask, n-2))
            {
                nmask = mask;
                nmask = turnOn(nmask, n-1);
                res = Math.Max(res, 1 + calc(nmask, 0, x+1, 0));
            }
        }
        else
        {
            int nmask = mask;
            if (left == 0)
            {
                nmask = turnOff(nmask, y - 1);
            }
            else
            {
                nmask = turnOn(nmask, y - 1);
            }
            res = calc(nmask, 0, x, y + 1);

            if (a[x][y] == '.' && left == 0 && !on(mask, y - 1) && !on(mask, y + 1))
            {
                res = Math.Max(res, 1 + calc(nmask, 1, x, y + 1));
            }
        }

        return f[mask, left, x, y] = res;
    }


    string Solve(int m, int n, string[] a)
    {
        this.a = a;
        this.m = m;
        this.n = n;
        f = new int[1 << n, 2, m, n];
        init();
        int res = calc(0, 0, 0, 0);
        return res.ToString();
    }

    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}