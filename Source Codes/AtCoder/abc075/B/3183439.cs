using System;

namespace ABC075B
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] bufs = Console.ReadLine().Split(' ');
            int H = int.Parse(bufs[0]);
            int W = int.Parse(bufs[1]);

            int[,] map = new int[H + 2, W + 2];

            for (int i = 1; i <= H; i++)
            {
                string row = Console.ReadLine();
                for (int j = 1; j <= W; j++)
                {
                    if(row[j - 1] == '#')
                    {
                        map[i - 1, j - 1]++;
                        map[i - 1, j]++;
                        map[i - 1, j + 1]++;
                        map[i, j - 1]++;
                        map[i, j] = 100;
                        map[i, j + 1]++;
                        map[i + 1, j - 1]++;
                        map[i + 1, j]++;
                        map[i + 1, j + 1]++;
                    }
                }
            }

            for (int i = 1; i <= H; i++)
            {
                string res = String.Empty;
                for (int j = 1; j <= W; j++)
                {
                    if (map[i, j] >= 100)
                    {
                        res += '#';
                    }
                    else
                    {
                        res += map[i, j];
                    }
                }
                Console.WriteLine(res);
            }

        }
    }
}