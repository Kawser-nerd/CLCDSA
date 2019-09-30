using System;
using System.IO;
using System.Collections.Generic;
using System.Text.RegularExpressions;

class ProblemD
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
        int C = readInt();
        for (int i = 1; i <= C; i++)
            doCase(i);
    }

    static void doCase(int caseNum)
    {
        int N = readInt();
        int[] X = new int[N], Y = new int[N], R = new int[N];
        int maxR = -1;
        for (int i = 0; i < N; i++)
        {
            int[] tmp = readInts();
            X[i] = tmp[0];
            Y[i] = tmp[1];
            R[i] = tmp[2];
            if (R[i] > maxR) maxR = R[i];
        }
        double res = maxR;
        if (N == 3)
        {
            res = double.PositiveInfinity;
            double tmp = Math.Max(R[0] * 2, R[1] + R[2] + dist(X[1], X[2], Y[1], Y[2]));
            res = Math.Min(res, tmp);
            tmp = Math.Max(R[1] * 2, R[0] + R[2] + dist(X[0], X[2], Y[0], Y[2]));
            res = Math.Min(res, tmp);
            tmp = Math.Max(R[2] * 2, R[0] + R[1] + dist(X[0], X[1], Y[0], Y[1]));
            res = Math.Min(res, tmp);
            res /= 2;
        }
        output.WriteLine("Case #{0}: {1}", caseNum, res);
    }

    static double dist(int x1, int x2, int y1, int y2)
    {
        int dx = x1 - x2;
        int dy = y1 - y2;
        return Math.Sqrt(dx * dx + dy * dy);
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
