using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Data;
using System.Numerics;

class ProblemB : GCJ
{
    int n, x, y;

    int Base(int it)
    {
        if (it == -1)
            return 0;
        return (it * 2 + 2) * (it * 2 + 1) / 2;
    }

    public override void Input(int testcase)
    {
        string[] str = sr.ReadLine().Split(splitors, StringSplitOptions.RemoveEmptyEntries);
        n = int.Parse(str[0]);
        x = int.Parse(str[1]);
        y = int.Parse(str[2]);

        double ret = 0;

        int it = (Math.Abs(x) + Math.Abs(y)) / 2;
        int b1 = Base(it - 1);
        int b2 = Base(it);

        if (n >= b2)
            ret = 1;
        else if (n > b1)
        {
            int cnt = Math.Abs(y) + 1;
            int mm = (b2 - b1 - 1) / 2;
            int m = n - b1;

            if (m == 2 * mm)
            {
                if (x == 0)
                    ret = 0;
                else
                    ret = 1;
            }
            else
            {
                double[][] p = new double[mm + 1][];
                for (int i = 0; i <= mm; i++)
                {
                    p[i] = new double[mm + 1];
                    for (int j = 0; j <= mm; j++)
                        p[i][j] = 0;
                }
                p[0][1] = 0.5;
                p[1][0] = 0.5;
                for (int k = 2; k <= m; k++)
                    for (int i = 0; i <= mm; i++)
                    {
                        int j = k - i;
                        if (j < 0 || j > mm)
                            continue;
                        double ratio1 = 0, ratio2 = 0;
                        if (i == mm)
                            ratio1 = 1;
                        else
                            ratio1 = 0.5;
                        if (j == mm)
                            ratio2 = 1;
                        else
                            ratio2 = 0.5;
                        if (j > 0)
                            p[i][j] += p[i][j - 1] * ratio1;
                        if (i > 0)
                            p[i][j] += p[i - 1][j] * ratio2;
                    }
                for (int i = cnt; i <= mm; i++)
                    if (m - i >= 0 && m - i <= mm)
                        ret += p[i][m - i];
            }
        }
        else
            ret = 0;

        sw.WriteLine(" " + ret);
        Console.WriteLine(" " + ret);
        base.Input(testcase);
    }
}
