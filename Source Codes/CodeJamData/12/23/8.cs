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
    const string inFile = "..\\..\\csmall.in";
    const string outFile = "..\\..\\csmall.out";

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
        Dictionary<int, int> f = new Dictionary<int, int>();

        int one = -1, two = -1;

        for (int i = 1; i < 1<<n; i++)
        {
            int temp = 0;
            for (int j = 0; j < n; j++)
            {
                if (isOn(i, j))
                {
                    temp += a[j];
                }
            }

            if (f.ContainsKey(temp))
            {
                int k = f[temp];

                if ((k & i) == 0)
                {
                    one = k;
                    two = i;
                    break;    
                }
            }
            else
            {
                f[temp] = i;
            }
        }

        if (one == -1)
        {
            return "Impossible";
        }

        string s = Environment.NewLine;
        s += calc(one, a);
        s += Environment.NewLine;
        s += calc(two, a);

        return s;
    }

    private string calc(int x, int[] a)
    {
        string s = "";
        for (int i = 0; i < a.Length; i++)
        {
            if (isOn(x, i))
            {
                if (s.Length > 0)
                {
                    s += " ";
                }
                s += a[i];
            }
        }

        return s;
    }

    bool isOn(int x, int b)
    {
        return (x & (1 << b)) > 0;
    }

    int turnOn(int x, int b)
    {
        return x | (1 << b);
    }

    int turnOff(int x, int b)
    {
        return x & ~(1 << b);
    }


    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}