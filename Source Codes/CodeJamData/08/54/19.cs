using System;
using System.IO;

public class Round3D
{
    static void Main(string[] args)
    {
        int i, j, mode, n, t, x, y;
        int h, w, r;
        StreamReader sr;
        StreamWriter sw;
        string line;
        string[] ss;
        int[,] sum = new int[1000, 1000];

        sr = new StreamReader("D-small-attempt0.in");
        sw = File.CreateText("D-small-attempt0.out");
        line = sr.ReadLine().Trim();
        t = Int32.Parse(line);
        for (mode = 0; mode < t; mode++)
        {
            line = sr.ReadLine();
            line = line.Trim();
            ss = line.Split(' ');
            h = Int32.Parse(ss[0]);
            w = Int32.Parse(ss[1]);
            r = Int32.Parse(ss[2]);

            for (i = 1; i < 1000; i++)
                for (j = 1; j < 1000; j++)
                    sum[i, j] = 0;

            for (i = 0; i < r; i++)
            {
                line = sr.ReadLine();
                line = line.Trim();
                ss = line.Split(' ');
                y = Int32.Parse(ss[0]);
                x = Int32.Parse(ss[1]);
                sum[y, x] = -1;
            }

            sum[1, 1] = 1;
            for (i = 1; i <= h; i++)
                for (j = 1; j <= w; j++)
                    if (sum[i, j] > 0)
                    {
                        x = j + 2;
                        y = i + 1;
                        if (x >= 1 && x <= w && y >= 1 && y <= h)
                            if (sum[y, x] > -1)
                            {
                                sum[y, x] = (sum[y, x] + sum[i, j]) % 10007;
                            }

                        x = j + 1;
                        y = i + 2;
                        if (x >= 1 && x <= w && y >= 1 && y <= h)
                            if (sum[y, x] > -1)
                            {
                                sum[y, x] = (sum[y, x] + sum[i, j]) % 10007;
                            }
                    }
            sw.WriteLine("Case #{0}: {1}", mode + 1, sum[h, w]);
        }
        sw.Close();
    }
}