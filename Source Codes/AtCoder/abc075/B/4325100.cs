using System;
using System.Collections.Generic;

namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            int H = 0, W = 0;

            string[] inputStr = Console.ReadLine().Split(' ');
            H = int.Parse(inputStr[0]);
            W = int.Parse(inputStr[1]);

            char[,] HW = new char[H, W];

            for(int i = 0;i < H; ++i)
            {
                string str = Console.ReadLine();
                for(int j = 0;j < W; ++j)
                {
                    HW[i, j] = str[j];
                }
            }
            for(int i = 0; i < H; ++i)
            {
                for(int j = 0; j < W; ++j)
                {
                    int counter = 0;

                    if(HW[i,j] != '#')
                    {
                        if (i - 1 >= 0 & j - 1 >= 0 && HW[i - 1, j - 1] == '#')
                        {
                            counter++;
                        }
                        if (i - 1 >= 0 && HW[i - 1, j] == '#')
                        {
                            counter++;
                        }
                        if (i - 1 >= 0 & j + 1 < W && HW[i - 1, j + 1] == '#')
                        {
                            counter++;
                        }
                        if (j - 1 >= 0 && HW[i, j - 1] == '#')
                        {
                            counter++;
                        }
                        if (j + 1 < W && HW[i, j + 1] == '#')
                        {
                            counter++;
                        }
                        if (i + 1 < H & j - 1 >= 0 && HW[i + 1, j - 1] == '#')
                        {
                            counter++;
                        }
                        if (i + 1 < H && HW[i + 1, j] == '#')
                        {
                            counter++;
                        }
                        if (i + 1 < H & j + 1 < W && HW[i + 1, j + 1] == '#')
                        {
                            counter++;
                        }
                        HW[i, j] = char.Parse(counter.ToString());
                    }
                }
            }

            for(int i = 0;i < H; ++i)
            {
                for(int j = 0;j < W; ++j)
                {
                    Console.Write($"{HW[i,j]}");
                }
                Console.Write("\n");
            }
        }
    }
}