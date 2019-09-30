using System;
using System.IO;

public class Round2A
{
    static void Main(string[] args)
    {
        const int MAX = 20000;
        int c1, c2, i, j, mode, n, r, t, v;
        StreamReader sr;
        StreamWriter sw;
        string line;
        string[] ss;
        int[,] best = new int[10000, 2];
        int[] changed = new int[10000];
        int[] gate = new int[10000];

        sr = new StreamReader("A-large.in");
        sw = File.CreateText("A-large.out");
        line = sr.ReadLine().Trim();
        t = Int32.Parse(line);
        for (mode = 0; mode < t; mode++)
        {
            line = sr.ReadLine();
            line = line.Trim();
            ss = line.Split(' ');
            n = Int32.Parse(ss[0]);
            v = Int32.Parse(ss[1]);
            for (i = 0; i < (n - 1) / 2; i++)
            {
                line = sr.ReadLine();
                line = line.Trim();
                ss = line.Split(' ');
                gate[i] = Int32.Parse(ss[0]);
                changed[i] = Int32.Parse(ss[1]);
            }
            j = (n - 1) / 2;
            for (i = 0; i < (n + 1) / 2; i++)
            {
                line = sr.ReadLine();
                line = line.Trim();
                r = Int32.Parse(line);
                best[j, r] = 0;
                best[j, 1 - r] = MAX;
                j++;
            }
            for (i = (n - 1) / 2 - 1; i >= 0; i--)
            {
                c1 = i * 2 + 1;
                c2 = i * 2 + 2;
                best[i, 0] = MAX;
                best[i, 1] = MAX;

                if (gate[i] == 1)
                {
                    best[i, 0] = Math.Min(best[i, 0], best[c1, 0] + best[c2, 0]);
                    best[i, 0] = Math.Min(best[i, 0], best[c1, 0] + best[c2, 1]);
                    best[i, 0] = Math.Min(best[i, 0], best[c1, 1] + best[c2, 0]);

                    best[i, 1] = Math.Min(best[i, 1], best[c1, 1] + best[c2, 1]);
                    if (changed[i] == 1)
                    {
                        best[i, 1] = Math.Min(best[i, 1], best[c1, 0] + best[c2, 1] + 1);
                        best[i, 1] = Math.Min(best[i, 1], best[c1, 1] + best[c2, 0] + 1);
                    }
                } else {
                    best[i, 0] = Math.Min(best[i, 0], best[c1, 0] + best[c2, 0]);
                    if (changed[i] == 1)
                    {
                        best[i, 0] = Math.Min(best[i, 0], best[c1, 0] + best[c2, 1] + 1);
                        best[i, 0] = Math.Min(best[i, 0], best[c1, 1] + best[c2, 0] + 1);
                    }

                    best[i, 1] = Math.Min(best[i, 1], best[c1, 0] + best[c2, 1]);
                    best[i, 1] = Math.Min(best[i, 1], best[c1, 1] + best[c2, 0]);
                    best[i, 1] = Math.Min(best[i, 1], best[c1, 1] + best[c2, 1]);
                }
            }
            if (best[0, v] >= MAX)
            {
                sw.WriteLine("Case #{0}: IMPOSSIBLE", mode + 1);
            } else {
                sw.WriteLine("Case #{0}: {1}", mode + 1, best[0, v]);
            }
        }
        sw.Close();
    }
}