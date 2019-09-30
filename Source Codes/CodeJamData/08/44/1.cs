using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;

class Problem
{
    const string inFile = "..\\..\\d-large.in";
    const string outFile = "..\\..\\d-large.out";

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
                    int k = int.Parse(sr.ReadLine());
                    string s = sr.ReadLine();

                    string res = Solve(k, s);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }

    int[, ,] f;
    int k;

    void init()
    {
        int l0 = f.GetLength(0);
        int l1 = f.GetLength(1);
        int l2 = f.GetLength(2);
        for (int i = 0; i < l0; i++)
        {
            for (int j = 0; j < l1; j++)
            {
                for (int u = 0; u < l2; u++)
                {
                    f[i, j, u] = -1;
                }
            }
        }
    }

    int calc(int mask, int last, int first)
    {
        if (mask == 0) return c[first, last];

        if (f[mask, last, first] != -1) return f[mask, last, first];
        int res = 1000000;

        for (int i = 0; i < k; i++)
        {
            if ((mask & (1 << i)) > 0)
            {
                int cost = calc(mask ^ (1 << i), i, first);
                if (last < k)
                {
                    cost += b[i, last];
                }
                res = Math.Min(res, cost);
            }
        }

        return f[mask, last, first] = res;
    }

    int[,] b, c;

    string Solve(int k, string s)
    {
        this.k = k;

        int n = s.Length;

        b = new int[k, k];
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (i == j) continue;
                for (int t = 0; t < s.Length; t += k)
                {
                    if (s[t + i] != s[t + j])
                    {
                        b[i, j]++;
                    }
                }
            }
        }

        c = new int[k, k];
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (i == j) continue;
                for (int t = k; t < s.Length; t += k)
                {
                    if (s[t + i] != s[t - k + j])
                    {
                        c[i, j]++;
                    }
                }
            }
        }

        f = new int[1 << k, k, k];
        init();

        int res = 1000000;
        for (int i = 0; i < k; i++)
        {
            res = Math.Min(res, calc(((1 << k) - 1) ^ (1 << i), i, i));
        }
        return (res+1).ToString();
    }

    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}