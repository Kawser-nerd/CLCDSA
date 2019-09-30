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
                    int k = ss[1];
                    string[] a = new string[n];
                    for (int i = 0; i < n; i++)
                    {
                        a[i] = sr.ReadLine();
                    }

                    string res = Solve(n, k, a);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }

    private string Solve(int n, int k, string[] s)
    {
        char[,] a = new char[n, n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i, j] = s[n-1-j][i];
            }
        }

        for (int i = 0; i < n; i++)
        {
            int j = n - 1;
            int t = n - 1;
            while (j >= 0)
            {
                if (a[j, i] == '.')
                {
                    j--;
                }
                else
                {
                    a[t, i] = a[j, i];
                    j--;
                    t--;
                }
            }
            while (t >= 0)
            {
                a[t, i] = '.';
                t--;
            }
        }

        bool Red = false;
        bool Blue = false;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (check(a, i, j, 'B', n, k))
                {
                    Blue = true;
                }

                if (check(a, i, j, 'R', n, k))
                {
                    Red = true;
                }

                if (Red && Blue) break;
            }

            if (Red && Blue) break;
        }

        if (Red && Blue)
            return "Both";
        else if (Red && !Blue)
            return "Red";
        else if (!Red && Blue)
            return "Blue";
        else
            return "Neither";
    }

    private bool check(char[,] a, int i, int j, char p, int n, int k)
    {
        {
            int t = i;
            int c = 0;
            while (c < k && t < n && a[t, j] == p)
            {
                c++;
                t++;
            }
            if (c == k) return true;
        }

        {
            int t = j;
            int c = 0;
            while (c < k && t < n && a[i, t] == p)
            {
                c++;
                t++;
            }
            if (c == k) return true;
        }

        {
            int t = i;
            int v = j;
            int c = 0;
            while (c < k && t < n && v < n && a[t, v] == p)
            {
                c++;
                t++;
                v++;
            }
            if (c == k) return true;
        }

        {
            int t = i;
            int v = j;
            int c = 0;
            while (c < k && t < n && v >= 0 && a[t, v] == p)
            {
                c++;
                t++;
                v--;
            }
            if (c == k) return true;
        }

        return false;
    }



    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}