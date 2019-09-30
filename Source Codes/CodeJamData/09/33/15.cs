using System;
using System.Collections.Generic;
using System.IO;


public class Round1CC
{
    static int min, p, q;
    static int[] a = new int[101];
    static bool[] b = new bool[101];
    static int[] prison = new int[101];
    static bool[] mark = new bool[101];

    static void search(int i, int sum)
    {
        int j, sum1;
        a[i] = 0;
        while (a[i] < q)
        {
            if (!b[a[i]])
            {
                b[a[i]] = true;
                sum1 = sum;
                for (j = prison[a[i]] - 1; j >= 0; j--)
                {
                    if (mark[j])
                    {
                        break;
                    }
                    sum1++;
                }
                for (j = prison[a[i]] + 1; j < p; j++)
                {
                    if (mark[j])
                    {
                        break;
                    }
                    sum1++;
                }
                b[a[i]] = true;
                mark[prison[a[i]]] = true;
                if (i == q - 1)
                {
                    if (sum1 < min) min = sum1;
                }
                else
                {
                    search(i + 1, sum1);
                }
                mark[prison[a[i]]] = false;
                b[a[i]] = false;
            }
            a[i]++;
        }
    }

    static void Main(string[] args)
    {
        StreamReader si;
        StreamWriter sw;
        string line;

        int i, j, n;


        si = new StreamReader("C-small-attempt0.in");
        sw = new StreamWriter("C-small-attempt0.out");

        line = si.ReadLine().Trim();
        n = Int32.Parse(line);

        for (i = 0; i < n; i++)
        {
            line = si.ReadLine().Trim();
            string[] ss = line.Split(' ');
            p = Int32.Parse(ss[0]);
            q = Int32.Parse(ss[1]);
            line = si.ReadLine().Trim();
            ss = line.Split(' ');
            for (j = 0; j < q; j++)
            {
                prison[j] = Int32.Parse(ss[j]) - 1;
            }
            min = int.MaxValue;
            search(0, 0);
            sw.WriteLine("Case #{0}: {1}", i + 1, min);
        }
        sw.Close();
    }
}