using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] hw = Console.ReadLine().Split(' ');
            int h = int.Parse(hw[0]);
            int w = int.Parse(hw[1]);
            string[] s = new string[h]; //input
            for (int i = 0; i < h; i++)
            {
                s[i] = Console.ReadLine();
            }
            char[,] t = new char[h, w]; //candidate solution
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    bool f = false;
                    for (int k = -1; k <= 1; k++)
                    {
                        for (int l = -1; l <= 1; l++)
                        {
                            if ((i + k < 0) || (j + l < 0) || (i + k >= h) || (j + l >= w))
                            {
                                continue;
                            }
                            if (s[i + k][j + l] == '.')
                            {
                                f = true;
                            }
                        }
                    }
                    if (f) { t[i, j] = '.'; } else { t[i, j] = '#'; }
                }
            }
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    if (s[i][j] == '.') continue;
                    bool f = false;
                    for (int k = -1; k <= 1; k++)
                    {
                        for (int l = -1; l <= 1; l++)
                        {
                            if ((i + k < 0) || (j + l < 0) || (i + k >= h) || (j + l >= w))
                            {
                                continue;
                            }
                            if (t[i + k, j + l] == '#')
                            {
                                f = true;
                            }
                        }
                    }
                    if (!f)
                    {
                        Console.WriteLine("impossible");
                        return;
                    }

                }
            }

            Console.WriteLine("possible");
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    Console.Write(t[i, j]);
                }
                Console.WriteLine();
            }
        }
    }
}