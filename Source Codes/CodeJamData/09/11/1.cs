using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;

class Problem
{
    const string inFile = "..\\..\\asmall.in";
    const string outFile = "..\\..\\asmall.out";

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
                    string res = Solve(ss);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }

    int dp(int x, int b)
    {
        if (f[b, x] > 0) return f[b, x];
        int res = 0;

        int y = x;
        while (y > 0)
        {
            int rem = y % b;
            res += rem * rem;
            y /= b;
        }

        f[b, x] = res;
        return res;
    }

    int calc(int x, int b)
    {
        int counter = 0;
        while (counter < b * 4)
        {
            counter++;
            x = dp(x, b);
            if (x == 1) break;
        }
        return x;
    }

    const int max = 100000;
    int[,] f = new int[11, max];
    
    string Solve(int[] S)
    {
        int n = S.Length;
        
        for (int i = 2; i < max; i++)
        {
            //Console.WriteLine("at = " + i);
            int firstBase = S[0];
            int t = calc(i, firstBase);
            if (t == 1)
            {
                bool good = true;
                for (int j = 1; j < S.Length; j++)
                {
                    int secondBase = S[j];
                    int tem = calc(i, secondBase);
                    if (tem != 1)
                    {
                        good = false;
                        break;
                    }
                }

                if (good)
                {
                    return i.ToString();
                }
            }
        }

        return null;
    }

    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}