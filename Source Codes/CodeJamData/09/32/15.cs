using System;
using System.Collections.Generic;
using System.IO;


public class Round1CB
{
    static void Main(string[] args)
    {
        StreamReader si;
        StreamWriter sw;
        string line;

        double a, a0, a1, a2, b, b0, b1, b2, c, d, r, w;
        int i, n, p, t;

        string[] ss;

        si = new StreamReader("B-large.in");
        sw = new StreamWriter("B-large.out");

        line = si.ReadLine().Trim();
        t = Int32.Parse(line);

        for (p = 0; p < t; p++)
        {
            line = si.ReadLine().Trim();
            n = Int32.Parse(line);
            a0 = 0;
            a1 = 0;
            a2 = 0;
            b0 = 0;
            b1 = 0;
            b2 = 0;
            for (i = 0; i < n; i++)
            {
                line = si.ReadLine().Trim();
                ss = line.Split(' ');

                a0 += Int32.Parse(ss[0]);
                a1 += Int32.Parse(ss[1]);
                a2 += Int32.Parse(ss[2]);
                b0 += Int32.Parse(ss[3]);
                b1 += Int32.Parse(ss[4]);
                b2 += Int32.Parse(ss[5]);
            }

            a0 = a0 / n;
            a1 = a1 / n;
            a2 = a2 / n;

            b0 = b0 / n;
            b1 = b1 / n;
            b2 = b2 / n;

            a = b0 * b0 + b1 * b1 + b2 * b2;
            b = 2 * (a0 * b0 + a1 * b1 + a2 * b2);
            c = a0 * a0 + a1 * a1 + a2 * a2;

            if (Math.Abs(a) < 1e-9 && Math.Abs(b) < 1e-9)
            {
                r = 0;
                w = c;
                if (Math.Abs(w) < 1e-9) d = 0; else d = Math.Sqrt(w);
            } else if (Math.Abs(a) < 1e-9)
            {
                r = 0;
                w = c;
                if (Math.Abs(w) < 1e-9) d = 0; else d = Math.Sqrt(w);
            }
            else
            {
                r = -b / 2 / a;
                if (r > 0)
                {
                    w = (4 * a * c - b * b) / 4 / a;
                    if (Math.Abs(w) < 1e-9) d = 0; else d = Math.Sqrt(w);
                }
                else
                {
                    r = 0;
                    w = c;
                    if (Math.Abs(w) < 1e-9) d = 0; else d = Math.Sqrt(w);
                }
            }
            sw.WriteLine("Case #{0}: {1} {2}", p + 1, d.ToString("f8"), r.ToString("f8"));
        }
        sw.Close();
    }
}