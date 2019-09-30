using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;

class Problem
{
    const string inFile = "..\\..\\clarge.in";
    const string outFile = "..\\..\\clarge.out";

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

                    string res = Solve(ss[0], ss[1]);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }

    long[,] D;

    double[] f;
    int N;
    int C;

    void init()
    {
        int l0 = f.GetLength(0);
        for (int i = 0; i < l0; i++)
        {
            f[i] = -1;
        }
    }

    double calc(int x)
    {
        if (x >= C) return 0;
        
        if (f[x] != -1) return f[x];
        double res = 0;

        int left = C - x;

        if (x == 0)
        {
            res = 1 + calc(N);
        }
        else
        {
            if (x >= N)
            {
                double total = 0;
                for (int i = 0; i < N; i++)
                {
                    int j = N - i;
                    if (j > left) continue;

                    double chance = (1.0 * D[x, i] * D[left, j]) / D[C, N];
                    total += chance * (1 + calc(x + j));
                }

                double p2 = D[x, N] * 1.0 / D[C, N];

                res = (total + p2)/ (1 - p2);
            }
            else
            {
                for (int i = 0; i <= x; i++)
                {
                    int j = N - i;
                    if (j > left) continue;

                    double chance = (1.0 * D[x,i] * D[left,j]) / D[C, N];
                    res += chance * (1 + calc(x + j));
                }
            }
        }

        return f[x] = res;
    }

    string Solve(int C, int N)
    {
        D = new long[45, 45];
        D[0, 0] = 1;
        for (int i = 1; i < 45; i++)
        {
            D[i, 0] = D[i, i] = 1;
            for (int j = 1; j < i; j++) D[i, j] = D[i - 1, j] + D[i - 1, j - 1];
        }

        this.C = C;
        this.N = N;
        f = new double[C + 5];
        init();
        return calc(0).ToString();
    }

    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}