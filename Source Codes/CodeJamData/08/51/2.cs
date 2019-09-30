using System;
using System.Collections.Generic;

public class pockets
{
    static int[] dx = new int[] { 0, -1, 0, 1 };
    static int[] dy = new int[] { -1, 0, 1, 0 };

    const int MAXN = 3000;

    public static void Main(string[] args)
    {
        int CASES = int.Parse(Console.ReadLine());

        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            long start = DateTime.Now.Ticks;
            int T = int.Parse(Console.ReadLine());
            List<string> parts = new List<string>();
            while (parts.Count < T * 2)
            {
                parts.AddRange(Console.ReadLine().Split());
            }
            int x = MAXN + 1;
            int y = MAXN + 1;
            int dir = 2;
            int[, ,] nextNum = new int[4, MAXN * 2 + 5, MAXN * 2 + 5];
            for (int j = 0; j < T; j++)
            {
                int n = int.Parse(parts[j * 2 + 1]);
                for (int m = 0; m < n; m++)
                {
                    for (int k = 0; k < parts[j * 2].Length; k++)
                    {
                        if (parts[j * 2][k] == 'F')
                        {
                            if (dir == 0)
                            { // vert, down
                                for (int i = 0; i < x; i++)
                                {
                                    nextNum[3, i, y - 1]++;
                                }
                                for (int i = x; i <= MAXN * 2 + 2; i++)
                                {
                                    nextNum[1, i, y - 1]++;
                                }
                            }
                            else if (dir == 1)
                            { // hor, left
                                for (int i = 0; i < y; i++)
                                {
                                    nextNum[2, x - 1, i]++;
                                }
                                for (int i = y; i <= MAXN * 2 + 2; i++)
                                {
                                    nextNum[0, x - 1, i]++;
                                }
                            }
                            else if (dir == 2)
                            { // vert, top
                                for (int i = 0; i < x; i++)
                                {
                                    nextNum[3, i, y]++;
                                }
                                for (int i = x; i <= MAXN * 2 + 2; i++)
                                {
                                    nextNum[1, i, y]++;
                                }
                            }
                            else if (dir == 3)
                            { // hor, right
                                for (int i = 0; i < y; i++)
                                {
                                    nextNum[2, x, i]++;
                                }
                                for (int i = y; i <= MAXN * 2 + 2; i++)
                                {
                                    nextNum[0, x, i]++;
                                }
                            }
                            x += dx[dir];
                            y += dy[dir];
                        }
                        if (parts[j * 2][k] == 'L')
                        {
                            dir = (dir + 3) % 4;
                        }
                        if (parts[j * 2][k] == 'R')
                        {
                            dir = (dir + 1) % 4;
                        }
                    }
                }
            }

            int total = 0;
            for (x = 0; x <= MAXN * 2 + 2; x++)
            {
                for (y = 0; y <= MAXN * 2 + 2; y++)
                {
                    if (nextNum[1, x, y] > 0 && nextNum[1, x, y] % 2 == 0 && nextNum[3, x, y] > 0 && nextNum[3, x, y] % 2 == 0)
                    {
                        total++;
                    }
                    else if (nextNum[0, x, y] > 0 && nextNum[0, x, y] % 2 == 0 && nextNum[2, x, y] > 0 && nextNum[2, x, y] % 2 == 0)
                    {
                        total++;
                    }
                }
            }
            Console.WriteLine("Case #" + CASE + ": " + total);
            Console.Error.WriteLine("Time: " + ((DateTime.Now.Ticks - start) / TimeSpan.TicksPerMillisecond) + " ms");
        }
    }
}