using System;

namespace ConsoleAppCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] HW = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int h = HW[0], w = HW[1];
            int n = int.Parse(Console.ReadLine());
            int[] a = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            int[][] ret = new int[h][];
            for (int i = 0; i < h; i++) ret[i] = new int[w];
            int x = 0, y = 0;
            for (int i = 0; i < n; i++)
            {
                int cnt = 0;
                while (cnt++ < a[i])
                {
                    ret[y][x] = i + 1;
                    if (y % 2 == 0)
                    {
                        if (x == w - 1)
                        {
                            y++;
                        }
                        else
                        {
                            x++;
                        }
                    }
                    else
                    {
                        if (x == 0)
                        {
                            y++;
                        }
                        else
                        {
                            x--;
                        }
                    }
                }
            }
            for(int i = 0; i < h; i++)
            {
                Console.WriteLine(string.Join(" ", ret[i]));
            }
        }
    }
}