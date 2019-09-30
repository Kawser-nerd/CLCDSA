using System;
using System.IO;

public class Round1BA
{
    static void Main(string[] args)
    {
        long a, b, c, d, m, sum;
        int i, j, k, l, mode, n, t;
        bool flag;
        StreamReader sr;
        StreamWriter sw;
        string line;
        string[] ss;
        long[] x = new long[100];
        long[] y = new long[100];

        sr = new StreamReader("A-small-attempt0.in");
        sw = File.CreateText("A-small-attempt0.out");
        line = sr.ReadLine().Trim();
        t = Int32.Parse(line);
        for (mode = 0; mode < t; mode++)
        {
            line = sr.ReadLine();
            line = line.Trim();
            ss = line.Split(' ');
            n = Int32.Parse(ss[0]);
            a = Int32.Parse(ss[1]);
            b = Int32.Parse(ss[2]);
            c = Int32.Parse(ss[3]);
            d = Int32.Parse(ss[4]);
            x[0] = Int32.Parse(ss[5]);
            y[0] = Int32.Parse(ss[6]);
            m = Int32.Parse(ss[7]);
            for (i = 1; i < n; i++)
            {
                x[i] = (a * x[i - 1] + b) % m;
                y[i] = (c * y[i - 1] + d) % m;
            }
            sum = 0;
            for (i = 0; i < n; i++)
                for (j = i + 1; j < n; j++)
                    for (k = j + 1; k < n; k++)
                    {
                        if ((x[i] + x[j] + x[k]) % 3 == 0 && (y[i] + y[j] + y[k]) % 3 == 0)
                        {
                            sum++;
                        }
                    }
            sw.WriteLine("Case #{0}: {1}", mode + 1, sum);
        }
        sw.Close();
    }
}