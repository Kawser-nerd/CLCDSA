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
    const string inFile = "..\\..\\bsmall2.in";
    const string outFile = "..\\..\\bsmall2.out";

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
                    int D = ss[0];
                    int I = ss[1];
                    int M = ss[2];
                    int n = ss[3];

                    ss = Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), int.Parse);

                    string res = Solve(D, I, M, ss);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }

    int D, I, M;
    int[] a;

    int[,,] f;
    int n;

    const int Flag = 260;

    void init()
    {
        int l0 = f.GetLength(0);
        int l1 = f.GetLength(1);
        int l2 = f.GetLength(2);
        for (int i = 0; i < l0; i++)
        {
            for (int j = 0; j < l1; j++)
            {
                for (int k = 0; k < l2; k++)
                {
                    f[i, j, k] = -1;
                }
            }
        }
    }

    int calc(int x, int last, int insert)
    {
        if (x >= n) return 0;

        if (f[x, last, insert] != -1) return f[x, last, insert];
        int res = int.MaxValue;

        if (last == Flag || Math.Abs(last - a[x]) <= M)
        {
            // keep the same
            res = calc(x + 1, a[x], 0);
        }

        // delete this
        res = Math.Min(res, D + calc(x + 1, last, 0));

        // change value
        for (int i = 0; i <= 255; i++)
        {
            if (last == Flag || Math.Abs(last - i) <= M)
            {
                int temp = calc(x + 1, i, 0);
                res = Math.Min(res, temp + Math.Abs(a[x] - i));
            }
        }

        // insert value
        if (last != Flag && insert != 1 && M != 0)
        {
            if (a[x] > last)
            {
                int dif = a[x] - last;
                int need = (dif + M - 1) / M;
                need = Math.Max(0, need - 1);

                int over = last + M * need;
                if (over != last)
                {
                    int temp = calc(x, over, 1);
                    res = Math.Min(res, temp + need * I);
                }

                over = last + M * (need + 1);
                if (over <= 255 && over != last)
                {
                    int temp = calc(x, over, 1);
                    res = Math.Min(res, temp + (need + 1) * I);
                }
            }
            else if (a[x] < last)
            {
                int dif = last - a[x];
                int need = (dif + M - 1) / M;
                need = Math.Max(0, need - 1);

                int over = last - M * need;
                if (over >= 0 && over != last)
                {
                    int temp = calc(x, over, 1);
                    res = Math.Min(res, temp + need * I);
                }

                over = last - M * (need + 1);
                if (over >= 0 && over != last)
                {
                    int temp = calc(x, over, 1);
                    res = Math.Min(res, temp + (need + 1) * I);
                }
            }
        }

        return f[x, last, insert] = res;
    }

    private string Solve(int D, int I, int M, int[] ss)
    {
        int n = ss.Length;
        this.D = D;
        this.I = I;
        this.M = M;
        this.a = ss;
        this.n = n;

        this.f = new int[n, 300, 2];
        init();

        int res = Math.Min(calc(0, Flag, 0), n * D);

        return res.ToString();
    }

    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}