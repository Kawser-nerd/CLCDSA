using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text.RegularExpressions;

class ProblemA
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
        int N = readInt();
        int[] grid = new int[N];
        int[] tmp = null;
        for (int i = 0; i < N; i++)
        {
            tmp = Array.ConvertAll(readLine().ToCharArray(), c => (int)(c - '0'));
            grid[i] = Array.LastIndexOf(tmp, 1);
        }
        int res = 0;
        for (int i = 0; i < N; i++)
            res += sort(grid, i);
        output.WriteLine("Case #{0}: {1}", caseNum, res);
    }

    static int sort(int[] g, int r)
    {
        if (g[r] <= r) return 0;
        for (int i = r + 1; i < g.Length; i++)
        {
            if (g[i] > r) continue;
            for (int j = i; j > r; j--)
            {
                int t = g[j];
                g[j] = g[j - 1];
                g[j - 1] = t;
            }
            return i - r;
        }
        throw new Exception("Lies!");
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
