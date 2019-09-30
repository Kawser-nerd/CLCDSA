using System;
using System.Collections.Generic;
using System.IO;


public class Round1CA
{
    static void Main(string[] args)
    {
        StreamReader si;
        StreamWriter sw;
        string line;
        int i, j, p, t;
        long l, r, sum;
        long[] a = new long[100];

        si = new StreamReader("A-large.in");
        sw = new StreamWriter("A-large.out");

        line = si.ReadLine().Trim();
        t = Int32.Parse(line);
        for (p = 0; p < t; p++)
        {
            line = si.ReadLine().Trim();
            List<char> symbol = new List<char>();
            for (i = 0; i < line.Length; i++)
            {
                j = symbol.IndexOf(line[i]);
                if (j < 0)
                {
                    symbol.Add(line[i]);
                    j = symbol.IndexOf(line[i]);
                }
                a[i] = j;
            }
            sum = 0;
            r = 1;
            for (i = 0; i < line.Length; i++)
            {
                if (a[i] == 0)
                {
                    a[i] = 1;
                } else if (a[i] == 1)
                {
                    a[i] = 0;
                }
            }
            l = Math.Max(symbol.Count, 2);
            for (i = line.Length - 1; i >= 0; i--)
            {
                sum += r * a[i];
                r *= l;
            }
            sw.WriteLine("Case #{0}: {1}", p + 1, sum);
        }
        sw.Close();
    }
}