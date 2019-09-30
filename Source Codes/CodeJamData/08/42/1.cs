using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;

class Problem
{
    const string inFile = "..\\..\\bsmall.in";
    const string outFile = "..\\..\\bsmall.out";

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
                    long[] ss = Array.ConvertAll<string, long>(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), long.Parse);
                    string res = Solve(ss[0], ss[1], ss[2]);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }

    // calculate double the area
    int area(int x1, int y1, int x2, int y2, int x3, int y3)
    {
        int u1 = x2 - x1;
        int v1 = y2 - y1;

        int u2 = x3 - x1;
        int v2 = y3 - y1;

        return Math.Abs(u1 * v2 - u2 * v1);
    }

    string Solve(long N, long M, long A)
    {
        if (A > M * N) return "IMPOSSIBLE";

        for (int x1 = 0; x1 <= N; x1++)
        {
            for (int x2 = 0; x2 <= N; x2++)
            {
                for (int y1 = 0; y1 <= M; y1++)
                {
                    for (int y2 = 0; y2 <= M; y2++)
                    {
                        if (area(0, 0, x1, y1, x2, y2) == A)
                        {
                            return string.Format("{0} {1} {2} {3} {4} {5}", 0, 0, x1, y1, x2, y2);
                        }
                    }
                }
            }
        }
        return "IMPOSSIBLE";
    }

    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}