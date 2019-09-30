using System;
using System.IO;

public class Round2B
{
    static void Main(string[] args)
    {
        int a, i, j, mode, m, n, s, t, x1, x2, x3, x4, y1, y2, y3, y4;
        bool succ;
        StreamReader sr;
        StreamWriter sw;
        string line;
        string[] ss;

        sr = new StreamReader("B-small-attempt0.in");
        sw = File.CreateText("B-small-attempt0.out");
        line = sr.ReadLine().Trim();
        t = Int32.Parse(line);
        for (mode = 0; mode < t; mode++)
        {
            line = sr.ReadLine();
            line = line.Trim();
            ss = line.Split(' ');
            n = Int32.Parse(ss[0]);
            m = Int32.Parse(ss[1]);
            a = Int32.Parse(ss[2]);
            if (n * m < a)
            {
                sw.WriteLine("Case #{0}: IMPOSSIBLE", mode + 1);
                continue;
            }

            if (n * m == a)
            {
                sw.WriteLine("Case #{0}: {1} {2} {3} {4} {5} {6}", mode + 1, 0, 0, n, 0, 0, m);
                continue;
            }

            succ = false;
            x3 = 0;
            y3 = 0;
            x4 = 0;
            y4 = 0;

            for (y1 = 0; y1 <= m; y1++)
            {
                for (x1 = 0; x1 <= n; x1++)
                {
                    if (x1 == n && y1 == m)
                    {
                        break;
                    }
                    x2 = x1;
                    y2 = y1;
                    do
                    {
                        x2++;
                        if (y2 == m && x2 == n) break;
                        if (x2 > n)
                        {
                            x2 = 0;
                            y2++;
                        }
                        s = Math.Abs(x1 * y2 - x2 * y1);
                        if (s == a)
                        {
                            succ = true;
                            x3 = x1;
                            y3 = y1;
                            x4 = x2;
                            y4 = y2;
                            break;
                        }
                    } while (true);
                    if (succ) break;
                }
                if (succ) break;
            }
            if (succ)
            {
                sw.WriteLine("Case #{0}: {1} {2} {3} {4} {5} {6}", mode + 1, 0, 0, x3, y3, x4, y4);
            }
            else
            {
                sw.WriteLine("Case #{0}: IMPOSSIBLE", mode + 1);
            }
        }
        sw.Close();
    }
}