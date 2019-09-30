using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;

class Problem
{
    const string inFile = "..\\..\\b-small.in";
    const string outFile = "..\\..\\b-small.out";

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
                    sw.WriteLine("Case #{0}: {1}", cas, Solve(ss[0], ss[1], ss[2]));
                }
            }
        }
    }

    bool ok(int a, int b)
    {
        for (int i = 0; i < all.Count && all[i] <= a && all[i] <= b; i++)
        {
            if (a % all[i] == 0 && b % all[i] == 0) return true;
        }

        return false;
    }

    int a, b;
    bool[,] f;
    bool[] visit;

    void dfs(int x)
    {
        visit[x] = true;
        for (int i = a; i <= b; i++)
        {
            if (f[x, i] && !visit[i])
                dfs(i);
        }
    }

    List<int> all;

    static bool IsPrime(int x)
    {
        if (x < 2) return false;
        int i = 2;
        while (i * i < x & x % i != 0) i++;
        return i * i > x;
    } 

    int Solve(int a, int b, int p)
    {
        all = new List<int>();
        for (int i = p; i <= b; ++i)
        {
            if (IsPrime(i)) all.Add(i);
        }

        this.a = a;
        this.b = b;
        this.f = new bool[b + 1, b+1];
        this.visit = new bool[b + 1];
        for (int i = a; i <= b; i++)
        {
            f[i,i] = true;
            for (int j = a; j < i; ++j)
            {
                f[i, j] = f[j, i] = ok(i, j);
            }
        }

        int res = 0;
        for (int i = a; i <= b; i++)
        {
            if (!visit[i])
            {
                res++;
                dfs(i);
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