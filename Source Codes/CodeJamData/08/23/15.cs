using System;
using System.IO;

public class Round1BC
{
    static void Main(string[] args)
    {
        int i, j, k, mode, n, p, t;
        StreamReader sr;
        StreamWriter sw;
        string line;
        string[] ss;
        int[] a = new int[1000001];
        int[] d = new int[100];

        sr = new StreamReader("C-small-attempt0.in");
        sw = File.CreateText("C-small-attempt0.out");
        line = sr.ReadLine().Trim();
        t = Int32.Parse(line);
        for (mode = 0; mode < t; mode++)
        {
            line = sr.ReadLine();
            line = line.Trim();
            k = Int32.Parse(line);

            line = sr.ReadLine();
            line = line.Trim();
            ss = line.Split(' ');
            n = Int32.Parse(ss[0]);

            for (i = 0; i < n; i++)
            {
                d[i] = Int32.Parse(ss[i + 1]);
            }

            p = 0;
            for (i = 1; i <= k; i++)
            {
                a[i] = 0;
            }
            for (i = 1; i < k; i++)
            {
                for (j = 1; j <= i; j++)
                {
                    do
                    {
                        p++;
                        if (p > k) p -= k;
                    } while (a[p] != 0);
                }
                a[p] = i;
            }
            for (i = 1; i <= k; i++)
                if (a[i] == 0)
                {
                    a[i] = k;
                    break;
                }
            sw.Write("Case #{0}:", mode + 1);
            for (i = 0; i < n; i++)
                sw.Write(" {0}", a[d[i]]);
            sw.WriteLine("");
        }
        sw.Close();
    }
}