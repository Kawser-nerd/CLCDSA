using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;
using System.Numerics;

class Problem
{
    const string inFile = "..\\..\\blarge.in";
    const string outFile = "..\\..\\blarge.out";

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
                    int P = int.Parse(sr.ReadLine());

                    int[] M = Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), int.Parse);

                    int[][] a = new int[P][];
                    for (int i = 0; i < P; i++)
                    {
                        a[i] = Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), int.Parse);
                    }

                    string res = Solve(P, M, a);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }

    int[] M;
    int P;
    int[][] a;

    int[,] f;

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

    int calc(int x, int y, int miss)
    {
        if (x == 0)
        {
            if (miss + 1 <= M[y * 2] && miss + 1 <= M[y * 2 + 1]) return 0;
            else if (miss <= M[y * 2] && miss <= M[y * 2 + 1]) return a[x][y];
            else return int.MaxValue;
        }

        int k = map[x][y];
        if (f[k, miss] != -1) return f[k, miss];
        int res = int.MaxValue;

        for (int i = 0; i < 2; i++)
        {
            int newMiss = miss;
            int total = 0;
            if (i == 0)
            {
                total += a[x][y];
            }
            else
            {
                newMiss++;
            }

            int totalLeft = calc(x - 1, y * 2, newMiss);
            int totalRight = calc(x - 1, y * 2 + 1, newMiss);

            if (totalLeft < int.MaxValue && totalRight < int.MaxValue)
            {
                total += totalLeft + totalRight;
                res = Math.Min(res, total);
            }
        }

        return f[k, miss] = res;
    }

    int[][] map;

    private string Solve(int P, int[] M, int[][] a)
    {
        this.P = P;
        this.M = M;
        this.a = a;

        int total = 1 << P;
        f = new int[total, P+1];
        init();

        map = new int[P][];
        int running = 0;
        for (int i = 0; i < P; i++)
        {
            map[i] = new int[a[i].Length];
            for (int j = 0; j < a[i].Length; j++)
            {
                map[i][j] = running++;
            }
        }

        int res = calc(P - 1, 0, 0);
        return res.ToString();
    }

    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }

    bool isOn(int x, int b)
    {
        return (x & (1 << b)) > 0;
    }

    int turnOn(int x, int b)
    {
        return x | (1 << b);
    }

    int turnOff(int x, int b)
    {
        return x & ~(1 << b);
    }

}