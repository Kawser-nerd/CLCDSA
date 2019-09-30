using System;
using System.IO;

public class Round3A
{
    struct pos
    {
        public int x, y;
    }

    static void Main(string[] args)
    {
        /*
        const int MAXX = 7000;
        const int MAXY = 7000;
        const int SX = 3500;
        const int SY = 3500;
         */

        const int MAXX = 300;
        const int MAXY = 300;
        const int SX = 150;
        const int SY = 150;


        int[] xn = new int[] { 0, 1, 0, -1 };
        int[] yn = new int[] { -1, 0, 1, 0 };
       

        int d, f, i, j, l, mode, n, r, sum, t, w, x, y;
        int maxx, maxy, minx, miny;
        string s, s1;
        StreamReader sr;
        StreamWriter sw;
        string line;
        string[] ss;
        bool[, ,] mark = new bool[MAXY, MAXX, 4];
        bool[,] map = new bool[MAXY, MAXX];
        bool[] dm = new bool[4];
        pos[] list = new pos[49000000];

        sr = new StreamReader("A-small-attempt0.in");
        sw = File.CreateText("A-small-attempt0.out");
        line = sr.ReadLine().Trim();
        t = Int32.Parse(line);
        for (mode = 0; mode < t; mode++)
        {
            line = sr.ReadLine();
            line = line.Trim();
            l = Int32.Parse(line);

            i = 0;
            s = "";
            while (i < l)
            {
                line = sr.ReadLine();
                line = line.Trim();
                ss = line.Split(' ');
                
                for (j = 0; j < ss.Length; j += 2)
                {
                    s1 = ss[j];
                    w = Int32.Parse(ss[j + 1]);
                    for (r = 0; r < w; r++)
                    {
                        s += s1;
                    }
                    i += 1;
                }
            }
            x = SX;
            y = SY;
            d = 2;

            for (i = 0; i < MAXY; i++)
                for (j = 0; j < MAXX; j++)
                {
                    map[i, j] = false;
                    for (r = 0; r < 4; r++)
                    {
                        mark[i, j, r] = true;
                    }
                }

            for (i = 0; i < s.Length; i++)
            {
                switch (s[i])
                {
                    case 'L':
                        d++;
                        if (d >= 4) d -= 4;
                        break;
                    case 'R':
                        d--;
                        if (d < 0) d += 4;
                        break;
                    case 'F':
                        switch (d)
                        {
                            case 0:
                                mark[y - 1, x, 3] = false;
                                mark[y - 1, x - 1, 1] = false;
                                break;
                            case 1:
                                mark[y, x, 0] = false;
                                mark[y - 1, x, 2] = false;
                                break;
                            case 2:
                                mark[y, x, 3] = false;
                                mark[y, x - 1, 1] = false;
                                break;
                            case 3:
                                mark[y, x - 1, 0] = false;
                                mark[y - 1, x - 1, 2] = false;
                                break;
                        }
                        x += xn[d];
                        y += yn[d];
                        break;
                }
            }

            r = 0;
            list[r].x = 0;
            list[r].y = 0;

            f = -1;
            while (f < r)
            {
                f++;
                map[list[f].y, list[f].x] = true;
                for (i = 0; i < 4; i++)
                {
                    if (mark[list[f].y, list[f].x, i])
                    {
                        x = list[f].x + xn[i];
                        y = list[f].y + yn[i];
                        if (x >= 0 && x < MAXX && y >= 0 && y < MAXY)
                            if (!map[y, x])
                            {
                                r++;
                                list[r].x = x;
                                list[r].y = y;
                                map[y, x] = true;
                            }
                    }
                }
            }

            maxx = Int32.MinValue;
            maxy = Int32.MinValue;
            minx = Int32.MaxValue;
            miny = Int32.MaxValue;

            for (i = 0; i < MAXY; i++)
                for (j = 0; j < MAXX; j++)
                    if (!map[i, j])
                    {
                        maxx = Math.Max(j, maxx);
                        maxy = Math.Max(i, maxy);

                        minx = Math.Min(j, minx);
                        miny = Math.Min(i, miny);
                    }
                     

            sum = 0;
            for (i = miny; i <= maxy; i++)
                for (j = minx; j <= maxx; j++)
                {
                    if (map[i, j])
                    {
                        for (r = 0; r < 4; r++)
                        {
                            dm[r] = false;
                            x = j;
                            y = i;
                            while (x >= minx && x <= maxx && y >= miny && y <= maxy)
                            {
                                if (!map[y, x])
                                {
                                    dm[r] = true;
                                    break;
                                }
                                x += xn[r];
                                y += yn[r];
                            }
                        }
                        if ((dm[0] && dm[2]) || (dm[1] && dm[3]))
                        {
                            sum++;
                        }
                    }
                }
            sw.WriteLine("Case #{0}: {1}", mode + 1, sum);
        }
        sw.Close();
    }
}