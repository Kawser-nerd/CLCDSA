using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;

class Bipartite
{
    static int m = 0, n = 0;
    static bool[] visited;
    static int[] f;
    static bool[,] a;
    static bool go(int x)
    {
        for (int i = 0; i < n; i++)
            if (!visited[i] && a[x, i])
            {
                visited[i] = true;
                if (f[i] == -1 || go(f[i])) { f[i] = x; return true; }
            }
        return false;
    }
    public static int FindMatch(bool[,] a)
    {
        Bipartite.a = a;
        m = a.GetLength(0); n = a.GetLength(1);
        f = new int[n]; visited = new bool[n];
        int res = 0;
        for (int i = 0; i < n; i++) f[i] = -1;
        for (int i = 0; i < m; i++)
        {
            Array.Clear(visited, 0, n);
            if (go(i)) res++;
        }
        return res;
    }
}


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

                    int n = ss[0];
                    int k = ss[1];

                    int[][] a = new int[n][];
                    for (int i = 0; i < n; i++)
                    {
                        a[i] = Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), int.Parse);
                    }

                    string res = Solve(n, k, a);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }

    string Solve(int n, int k, int[][] a)
    {
        bool[,] can = new bool[n, n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j) continue;

                bool good = true;
                for (int t = 0; t < k; t++)
                {
                    if (a[i][t] >= a[j][t])
                    {
                        good = false;
                        break;
                    }
                }

                can[i, j] = good;
            }
        }

        int res = n - Bipartite.FindMatch(can);
        return res.ToString();
    }

    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}