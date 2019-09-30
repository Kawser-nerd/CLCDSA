using System;
using System.Linq;

namespace arc021_1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] tile = new int[4, 4];
            for (int i = 0; i < 4; i++)
            {
                int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
                for (int j = 0; j < 4; j++)
                {
                    tile[i, j] = x[j];
                }
            }
            bool flag = true;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (tile[i, j] == tile[i + 1, j])
                    {
                        flag = false;
                    }
                }
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (tile[i, j] == tile[i, j + 1])
                    {
                        flag = false;
                    }
                }
            }
            for (int i = 1; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (tile[i, j] == tile[i - 1, j])
                    {
                        flag = false;
                    }
                }
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 1; j < 4; j++)
                {
                    if (tile[i, j] == tile[i, j - 1])
                    {
                        flag = false;
                    }
                }
            }
            Console.WriteLine(!flag ? "CONTINUE" : "GAMEOVER");
        }
    }
}