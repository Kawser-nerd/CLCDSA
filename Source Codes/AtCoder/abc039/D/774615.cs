using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace d
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] vy = { 0, 1, 0, -1, 0, 1, 1, -1, -1 };
            int[] vx = { 0, 0, 1, 0, -1, 1, -1, 1, -1 }; 
            int[] hw = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int h = hw[0];
            int w = hw[1];
            string[] s = new string[h];
            for (int i = 0; i < h; i++)
            {
                s[i] = Console.ReadLine();
            }
            bool[,] tmp = new bool[h, w];
            bool[,] ans = new bool[h, w];
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    bool sharp = true;
                    for (int k = 0; k < 9; k++)
                    {
                        int nextx = i + vx[k];
                        int nexty = j + vy[k];
                        if (nextx < 0 || h <= nextx || nexty < 0 || w <= nexty) continue;
                        if(s[nextx][nexty]== '.')
                        {
                            sharp = false;
                            break;
                        } 
                    }
                    tmp[i, j] = sharp;
                }
            }
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    if (tmp[i, j])
                    {
                        for (int k = 0; k < 9; k++)
                        {
                            int nextx = i + vx[k];
                            int nexty = j + vy[k];
                            if (nextx < 0 || h <= nextx || nexty < 0 || w <= nexty) continue;
                            else
                            {
                                ans[nextx, nexty] = true;
                            }
                        }
                    }
                }
            }
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    if (ans[i, j])
                    {
                        if(s[i][j]=='.')
                        {
                            Console.WriteLine("impossible");
                            return;
                        }
                    }
                    else
                    {
                        if(s[i][j] == '#')
                        {
                            Console.WriteLine("impossible");
                            return;
                        }
                    }
                }
            }
            Console.WriteLine("possible");
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    if (tmp[i, j]) Console.Write("#");
                    else Console.Write(".");
                }
                Console.WriteLine();
            }
        }
    }
}