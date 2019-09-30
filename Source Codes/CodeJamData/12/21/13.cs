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
    const string inFile = "..\\..\\alarge.in";
    const string outFile = "..\\..\\alarge.out";

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
                    int[] a = new int[n];
                    Array.Copy(ss, 1, a, 0, n);

                    string res = Solve(n, a);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }

    private string Solve(int n, int[] a)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
        }

        string[] res = new string[n];
        for (int i = 0; i < n; i++)
        {
            double temp = calc(i, a, sum, n);
            res[i] = (temp * 100).ToString();
        }

        return string.Join(" ", res);
    }

    private double calc(int x, int[] a, int sum, int n)
    {
        double left = 0;
        double right = 1;
        for (int i = 0; i < 100; i++)
        {
            double middle = (left + right)/2;
            if (good(middle, x, a, sum, n))
            {
                right = middle;
            }
            else
            {
                left = middle;
            }
        }

        return (left + right) / 2;
    }

    private bool good(double percent, int x, int[] a, int sum, int n)
    {
        double thisPoint = a[x] + percent * sum;

        double neededPercent = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == x)
            {
                neededPercent += percent;
            }
            else
            {
                if (a[i] < thisPoint)
                {
                    double boost = (thisPoint - a[i]) / sum;
                    neededPercent += boost;
                }
            }
        }

        return neededPercent >= 1;
    }

    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}