using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;

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
                    int n = int.Parse(sr.ReadLine());
                    string[] s = new string[n];
                    for (int i = 0; i < n; i++)
                    {
                        s[i] = sr.ReadLine();
                    }

                    string res = Solve(n, s);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }

    bool good(string s, int k)
    {
        for (int i = k+1; i < s.Length; i++)
        {
            if (s[i] == '1') return false;
        }

        return true;
    }

    string Solve(int n, string[] s)
    {
        int res = 0;
        for (int i = 0; i < n-1; i++)
        {
            if (good(s[i], i)) continue;
            for (int j = i+1; j < n; j++)
            {
                if (good(s[j], i))
                {
                    string tmp = s[j];
                    for (int k = j; k > i; k--)
                    {
                        s[k] = s[k - 1];
                    }
                    s[i] = tmp;
                    res += (j - i);
                    break;
                }
            }
        }

        return res.ToString();
    }

    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}