using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text.RegularExpressions;

class ProblemC
{
    private static StreamReader input;
    private static StreamWriter output;

    public static void Main(string[] args)
    {
        input = new StreamReader(args[0] + ".in");
        output = new StreamWriter(args[0] + ".out");
        solution();
        output.Close();
        input.Close();
    }

    static void solution()
    {
        int T = readInt();
        for (int i = 1; i <= T; i++)
            doCase(i);
    }

    static void doCase(int caseNum)
    {
        int[] tmp = readInts();
        int n = tmp[0], k = tmp[1];
        int[][] prices = new int[n][];
        for (int i = 0; i < n; i++)
            prices[i] = readInts();
        bool[,] cross = new bool[n, n];
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                bool over = false, under = false;
                for (int l = 0; l < k; l++)
                {
                    over |= prices[j][l] >= prices[i][l];
                    under |= prices[j][l] <= prices[i][l];
                }
                cross[i, j] = cross[j, i] = over && under;
            }
        }
        int res = maxcs(cross) + 1;
        output.WriteLine("Case #{0}: {1}", caseNum, res);
    }

    static int maxcs(bool[,] edges)
    {
        int r = 0, n = edges.GetLength(0);
        for (int i = 0; i < n; i++)
        {
            List<int> l = new List<int>();
            for (int j = i+1; j < n; j++)
                if (edges[i, j])
                    l.Add(j);
            if (l.Count != 0 && r == 0) r = 1;
            if (l.Count <= r) continue;
            int x = find(edges, l);
            if (x > r) r = x;
        }
        return r;
    }

    static int find(bool[,] edges, List<int> l)
    {
        int r = 0, n = edges.GetLength(0);
        foreach (int i in l)
        {
            var l2 = l.Where(j => edges[i, j]).ToList();
            if (l2.Count > r)
            {
                int t = find(edges, l2);
                if (t > r) r = t;
            }
        }
        return r + 1;
    }

    static string readLine()
    {
        return input.ReadLine();
    }

    static int readInt()
    {
        return int.Parse(readLine());
    }

    static string[] readWords()
    {
        return readLine().Split();
    }

    static int[] readInts()
    {
        return Array.ConvertAll(readWords(), int.Parse);
    }
}
