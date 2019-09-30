using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;

class Problem
{
    const string inFile = "..\\..\\dsmall2.in";
    const string outFile = "..\\..\\dsmall2.out";

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
                    int r = ss[0];
                    int c = ss[1];
                    string[] a = new string[r];
                    for (int i = 0; i < r; i++)
                    {
                        a[i] = sr.ReadLine();
                    }

                    string res = Solve(r, c, a);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }


    int[,] f;

    int[] dx = new int[] { -1, -1, 0, 1, 1, 1, 0, -1 };
    int[] dy = new int[] { 0, 1, 1, 1, 0, -1, -1, -1 };


    int calc(int mask, int last)
    {
        if (f[mask, last] != 0) return f[mask, last];
        int res = 1;

        int x = last / c;
        int y = last % c;
        for (int t = 0; t < 8; t++)
        {
            int u = x + dx[t];
            int v = y + dy[t];
            if (u >= 0 && v >= 0 && u < r && v < c)
            {
                int k = u * c + v;

                if (isOn(mask, k))
                {
                    int tem = calc(turnOff(mask, k), k);
                    if (tem == 1)
                    {
                        res = 2;
                    }
                }
            }
        }

        return f[mask, last] = res;
    }

    int r, c;

    string Solve(int r, int c, string[] a)
    {
        this.r = r;
        this.c = c;
        int n = r * c;
        f = new int[1 << n, n];

        int state = 0;
        int k = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (a[i][j] == '.')
                    state = turnOn(state, i * c + j);
                if (a[i][j] == 'K')
                    k = i * c + j;
            }
        }

        return calc(state, k) == 2 ? "A" : "B";
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


    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}