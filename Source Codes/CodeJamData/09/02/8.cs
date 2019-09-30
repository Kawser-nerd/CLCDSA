using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace gcj2009
{
    class Q2
    {
        public static void f()
        {
            using (StreamReader sr = new StreamReader(@"C:\Users\int\Desktop\B.in"))
            {
                using (StreamWriter sw = new StreamWriter(@"C:\Users\int\Desktop\B.out"))
                {
                    int t = int.Parse(sr.ReadLine());
                    for (int ca = 0; ca < t; ca++)
                    {
                        int h, w;
                        string line = sr.ReadLine();
                        h = int.Parse(line.Split(' ')[0]);
                        w = int.Parse(line.Split(' ')[1]);
                        int[,] a = new int[h, w];
                        for (int i = 0; i < h; i++)
                        {
                            line = sr.ReadLine();
                            string[] strs = line.Split(' ');
                            for (int j = 0; j < w; j++)
                            {
                                a[i, j] = int.Parse(strs[j]);
                            }
                        }
                        //North, West, East, South
                        int[,] dir = new int[,] { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };
                        List<int>[,] lx = new List<int>[h, w];
                        List<int>[,] ly = new List<int>[h, w];
                        for (int i = 0; i < h; i++)
                        {
                            for (int j = 0; j < w; j++)
                            {
                                lx[i, j] = new List<int>();
                                ly[i, j] = new List<int>();
                            }
                        }
                        for (int i = 0; i < h; i++)
                        {
                            for (int j = 0; j < w; j++)
                            {
                                int bx = -1;
                                int by = -1;
                                int min = int.MaxValue;
                                for (int d = 0; d < 4; d++)
                                {
                                    int x = i + dir[d, 0];
                                    int y = j + dir[d, 1];
                                    if (0 <= x && x < h && 0 <= y && y < w)
                                    {
                                        if (a[x, y] < a[i, j])
                                        {
                                            if (a[x, y] < min)
                                            {
                                                min = a[x, y];
                                                bx = x;
                                                by = y;
                                            }
                                        }
                                    }
                                }
                                if (bx != -1)
                                {
                                    lx[bx, by].Add(i);
                                    ly[bx, by].Add(j);
                                    lx[i, j].Add(bx);
                                    ly[i, j].Add(by);
                                }
                            }
                        }
                        char cur = 'a';
                        char[,] res = new char[h, w];
                        for (int i = 0; i < h; i++)
                        {
                            for (int j = 0; j < w; j++)
                            {
                                if (res[i, j] == (char)0)
                                {
                                    res[i, j] = cur;
                                    fill(res, i, j, cur, lx, ly);
                                    cur++;
                                }
                            }
                        }

                        
                        sw.WriteLine("Case #" + (ca + 1) + ":");
                        for (int i = 0; i < h; i++)
                        {
                            for (int j = 0; j < w; j++)
                            {
                                sw.Write(res[i, j]);
                                if (j != w - 1)
                                {
                                    sw.Write(' ');
                                }
                                else
                                {
                                    sw.WriteLine();
                                }
                            }
                        }
                    }
                }
            }
        }

        private static void fill(char[,] res, int x, int y, char cur, List<int>[,] lx, List<int>[,] ly)
        {
            for (int i = 0; i < lx[x, y].Count; i++)
            {
                int nx = lx[x, y][i];
                int ny = ly[x, y][i];
                if (res[nx, ny] == (char)0)
                {
                    res[nx, ny] = cur;
                    fill(res, nx, ny, cur, lx, ly);
                }
            }
        }
    }
}
