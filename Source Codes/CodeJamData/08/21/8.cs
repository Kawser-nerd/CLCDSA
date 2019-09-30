using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;

class Problem
{
    const string inFile = "..\\..\\a-small-attempt0.in";
    const string outFile = "..\\..\\a-small.out";

    public void Process()
    {
        using (StreamReader sr = new StreamReader(inFile))
        {
            using (StreamWriter sw = new StreamWriter(outFile))
            {
                int numCases = int.Parse(sr.ReadLine());
                for (int cas = 1; cas <= numCases; cas++)
                {
                    int[] ss = Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), int.Parse);
                    sw.WriteLine("Case #{0}: {1}", cas, Solve(ss[0], ss[1], ss[2], ss[3], ss[4], ss[5], ss[6], ss[7]));
                }
            }
        }
    }

    long Solve(int n, int A, int B, int C, int D, int x0, int y0, int M)
    {
//        X = x0, Y = y0
//print X, Y
//for i = 1 to n-1
//  X = (A * X + B) mod M
//  Y = (C * Y + D) mod M
//  print X, Y

        long[] px = new long[n];
        long[] py = new long[n];
        px[0] = x0;
        py[0] = y0;
        for (int i = 1; i < n; i++)
        {
            px[i] = (((long)A * px[i-1] + B) % M);
            py[i] = (((long)C * py[i-1] + D) % M);
        }

        long res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                for (int k = 0; k < j; k++)
                {
                    if ((px[i] + px[j] + px[k]) % 3 == 0 &&
                            (py[i] + py[j] + py[k]) % 3 == 0)
                    {
                        res++;
                    }
                }
            }
        }

        return res;
    }

    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}