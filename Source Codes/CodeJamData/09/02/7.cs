using System;
using System.IO;


public class QualB
{
    static int[] xn = new int[] { 0, -1, 1, 0 };
    static int[] yn = new int[] { -1, 0, 0, 1 };
    static int[,] map = new int[200, 200];
    static int[,] dir = new int[200, 100];
    static int[,] color = new int[200, 200];

    static int h, w;

    static void search(int x, int y, int c)
    {

        int i, x1, y1;

        color[y, x] = c;
        for (i = 0; i < 4; i++)
        {
            x1 = x + xn[i];
            y1 = y + yn[i];
            if (x1 >= 0 && x1 < w && y1 >= 0 && y1 < h)
            {
                if (dir[y1, x1] == i && color[y1, x1] == -1)
                {
                    search(x1, y1, c);
                }
            }
        }
    }


    static void Main(string[] args)
    {
        StreamReader si;
        StreamWriter sw;
        string line;

        si = new StreamReader("B-large.in");
        sw = new StreamWriter("B-large.out");

        int c, i, j, k, l, min, t, x, y;
        char cur;
        string[] ss;
        char[] pattern = new char[26];

        line = si.ReadLine().Trim();
        t = Int32.Parse(line);

        for (i = 0; i < t; i++)
        {
            line = si.ReadLine().Trim();
            ss = line.Split(' ');
            h = Int32.Parse(ss[0]);
            w = Int32.Parse(ss[1]);
            for (j = 0; j < h; j++)
            {
                line = si.ReadLine().Trim();
                ss = line.Split(' ');
                for (k = 0; k < w; k++)
                {
                    map[j, k] = Int32.Parse(ss[k]);
                }
            }

            for (j = 0; j < h; j++)
            {
                for (k = 0; k < w; k++)
                {
                    min = Int32.MaxValue;
                    dir[j, k] = -1;
                    for (l = 0; l < 4; l++)
                    {
                        x = k + xn[l];
                        y = j + yn[l];
                        if (x >= 0 && x < w && y >= 0 && y < h)
                        {
                            if (map[y, x] < map[j, k])
                            {
                                if (map[y, x] < min)
                                {
                                    min = map[y, x];
                                    dir[j, k] = 3 - l;
                                }
                            }
                        }
                    }
                }
            }
            c = 0;
            for (j = 0; j < h; j++)
            {
                for (k = 0; k < w; k++)
                {
                    color[j, k] = -1;
                }
            }

            for (j = 0; j < h; j++)
            {
                for (k = 0; k < w; k++)
                {
                    if (dir[j, k] == -1)
                    {
                        search(k, j, c);
                        c++;
                    }
                }
            }


            for (j = 0; j < 26; j++)
            {
                pattern[j] = ' ';
            }

            cur = 'a';
            sw.WriteLine("Case #{0}:", i + 1);
            for (j = 0; j < h; j++)
            {
                for (k = 0; k < w; k++)
                {
                    if (pattern[color[j, k]] == ' ')
                    {
                        pattern[color[j, k]] = cur;
                        cur++;
                    }
                    sw.Write("{0} ", pattern[color[j, k]]);
                }
                sw.WriteLine();
            }
        }
        sw.Close();
    }
}