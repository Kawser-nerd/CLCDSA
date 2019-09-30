using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;

class Problem
{

    const string inFile = "..\\..\\a-large.in";
    const string outFile = "..\\..\\a-large.out";

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

                    int M = ss[0];
                    int V = ss[1];

                    int[] gate = new int[M];
                    bool[] can = new bool[M];
                    for (int i = 0; i < (M-1) / 2; i++)
                    {
                        ss = Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), int.Parse);
                        gate[i] = ss[0];
                        can[i] = ss[1] == 1;
                    }

                    for (int i = 0; i < (M+1)/2; i++)
                    {
                        int t = int.Parse(sr.ReadLine());
                        gate[(M - 1) / 2 + i] = t;
                        can[(M - 1) / 2 + i] = false;
                    }

                    string res = Solve(M, V, gate, can);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }

    int[,] f;
    int n;

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

    const int INF = 10000000;

    int calc(int x, int state)
    {
        if (f[x, state] != -1) return f[x, state];
        int res = INF;

        if (x * 2 + 1 < n)
        {
            for (int i = 0; i < 2; i++)
            {
                if (can[x] || gate[x] == i)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        for (int k = 0; k < 2; k++)
                        {
                            if (i == 1 && j * k == state ||
                                i == 0 && (state == 1 && j + k > 0 || state == 0 && j + k == 0))
                            {
                                int left = calc(x * 2 + 1, j);
                                int right = calc(x * 2 + 2, k);
                                int cost = left + right;
                                if (gate[x] != i)
                                    cost++;
                                res = Math.Min(res, cost);
                            }
                        }
                    }
                }
            }
        }
        else
        {
            res = state == gate[x] ? 0 : INF;
        }

        return f[x, state] = res;
    }

    int[] gate;
    bool[] can;

    string Solve(int n, int V, int[] gate, bool[] can)
    {
        this.n = n;
        f = new int[n,2];
        init();
        this.gate = gate;
        this.can = can;
        int res = calc(0, V);
        if (res >= INF) return "IMPOSSIBLE";
        else return res.ToString();
    }

    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}