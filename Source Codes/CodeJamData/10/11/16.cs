using System;
using System.Collections.Generic;
using System.IO;

public class Round1AA
{
    static void Main(string[] args)
    {
        StreamReader si;
        StreamWriter sw;
        string line;
        string[] ss;

        int c, i, j, k, n, p, q, t, x, y;
        string ret;
        char[,] map = new char[100, 100];
        char[] row = new char[100];
        int[] xn = new int[4] { 1, 1, 0, -1 };
        int[] yn = new int[4] { 0, 1, 1, 1 };
        bool flagb, flagr;

        si = new StreamReader("A-large.in");
        sw = new StreamWriter("A-large.out");

        line = si.ReadLine().Trim();

        t = Int32.Parse(line);
        for (c = 0; c < t; c++)
        {
            line = si.ReadLine().Trim();
            ss = line.Split(' ');
            n = Int32.Parse(ss[0]);
            k = Int32.Parse(ss[1]);
            for (i = 0; i < n; i++)
            {
                line = si.ReadLine().Trim();
                for (j = 0; j < n; j++)
                {
                    map[i, j] = line[j];
                }
            }
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    row[j] = '.';
                }
                p = n - 1;
                for (j = n - 1; j >= 0; j--)
                {
                    if (map[i, j] != '.')
                    {
                        row[p] = map[i, j];
                        p--;
                    }
                }
                for (j = 0; j < n; j++)
                {
                    map[i, j] = row[j];
                }
            }

            flagb = false;
            flagr = false;
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    if (map[i, j] != '.' && (map[i, j] != 'B' || !flagb) && (map[i, j] != 'R' || !flagr))
                    {
                        for (p = 0; p < 4; p++)
                        {
                            x = j + xn[p];
                            y = i + yn[p];
                            q = 1;
                            while (x >= 0 && x < n && y >= 0 && y < n && q < k)
                            {
                                if (map[y, x] != map[i, j])
                                {
                                    break;
                                }
                                q++;
                                x += xn[p];
                                y += yn[p];
                            }
                            if (q >= k)
                            {
                                if (map[i, j] == 'B')
                                {
                                    flagb = true;
                                } else {
                                    flagr = true;
                                }
                                break;
                            }
                        }

                        if (flagb && flagr)
                        {
                            break;
                        }
                    }
                }
                if (flagb && flagr)
                {
                    break;
                }
            }
            ret = "";
            if (flagb && flagr)
            {
                ret = "Both";
            }
            if (flagb && !flagr)
            {
                ret = "Blue";
            }
            if (!flagb && flagr)
            {
                ret = "Red";
            }
            if (!flagb && !flagr)
            {
                ret = "Neither";
            }
            sw.WriteLine("Case #{0}: {1}", c + 1, ret);
        }
        sw.Close();

    }
}
