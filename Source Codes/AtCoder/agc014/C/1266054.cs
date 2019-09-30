//#pragma warning disable

using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

public class Test
{
    public class P {
        public int Y;
        public int X;

        public P(int y, int x)
        {
            Y = y;
            X = x;
        }
    }

    public static void Main()
    {
        var line1 = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
        var H = line1[0];
        var W = line1[1];
        var K = line1[2];

        var field = new char[H][];

        int posY = -1;
        int posX = -1;

        for (var i = 0; i < H; i++)
        {
            string s = Console.ReadLine();
            field[i] = s.ToCharArray();

            if (s.IndexOf('S') != -1)
            {
                posY = i;
                posX = s.IndexOf('S');
            }
        }

        int totalCost = 0;

        var costWalk = new int[H, W];
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                costWalk[i, j] = -1;
            }
        }

        var costObstacle = new int[H, W];
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                costObstacle[i, j] = -1;
            }
        }


        var q1 = new Queue<P>();
        int costW = 0;
        q1.Enqueue(new P(posY, posX));
        costWalk[posY, posX] = 0;

        var q3 = new Queue<P>();
        int costO = 0;
        q3.Enqueue(new P(posY, posX));
        costObstacle[posY, posX] = 0;

        var MIIIIIN = Math.Min(Math.Min(Math.Min(posY, H - posY - 1), posX), W - posX - 1);

        while (true)
        {
            // costWalk ???
            {
                while (q1.Count != 0 && costW < (totalCost + 1) * K)
                {
                    var q2 = new Queue<P>();

                    foreach (var next in q1)
                    {
                        var d = new int[] { 0, -1, 0, 1, 0 };

                        for (int n = 0; n < 4; n++)
                        {
                            int y = next.Y + d[n];
                            int x = next.X + d[n + 1];

                            if (y >= 0 && y < H && x >= 0 && x < W)
                            {
                                if (costWalk[y, x] == -1 && field[y][x] != '#')
                                {
                                    var p = new P(y, x);
                                    q2.Enqueue(p);
                                    q3.Enqueue(p);
                                    costWalk[y, x] = costW + 1;
                                    var miiiiin = Math.Min(Math.Min(Math.Min(y, H - y - 1), x), W - x - 1);
                                    MIIIIIN = Math.Min(MIIIIIN, miiiiin);

                                    if (y == 0 || y == H - 1 || x == 0 || x == W - 1)
                                    {
                                        Console.WriteLine(totalCost + 1);
                                        return;
                                    }
                                }
                            }
                        }
                    }

                    q1 = q2;
                    costW++;
                }
            }

            Console.WriteLine((MIIIIIN + K - 1) / K + 1);
            return;

            /*Console.WriteLine("debug:");
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    Console.Write(costWalk[i, j] + " ");
                }
                Console.WriteLine();
            }*/

            // ????
            {
                while (q3.Count != 0 && costO < (totalCost + 1) * K)
                {
                    var q4 = new Queue<P>();
                    q4 = q3;

                    while(q4.Count != 0)
                    {
                        var next = q4.Dequeue();

                        var d = new int[] { 0, -1, 0, 1, 0 };

                        for (int n = 0; n < 4; n++)
                        {
                            int y = next.Y + d[n];
                            int x = next.X + d[n + 1];

                            if (y >= 0 && y < H && x >= 0 && x < W)
                            {
                                if (costObstacle[y, x] == -1)
                                {
                                    if (field[y][x] != '#')
                                    {
                                        q4.Enqueue(new P(y, x));  // q3!
                                        costObstacle[y, x] = costO + 0;  // zero!

                                        if (y == 0 || y == H - 1 || x == 0 || x == W - 1)
                                        {
                                            //Console.WriteLine(totalCost + 1);
                                            //return;
                                        }
                                    }
                                    else
                                    {
                                        q3.Enqueue(new P(y, x));
                                        costObstacle[y, x] = costO + 1;
                                        field[y][x] = '.';  // ?????????????

                                        if (y == 0 || y == H - 1 || x == 0 || x == W - 1)
                                        {
                                            //Console.WriteLine(totalCost + 1);
                                            //return;
                                        }

                                        if (costWalk[next.Y, next.X] != -1)
                                        {
                                            q1.Enqueue(new P(next.Y, next.X));
                                        }
                                    }
                                }
                            }
                        }
                    }

                    costO++;
                }
            }
            /*Console.WriteLine("debug2:");
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    Console.Write(costWalk[i, j] + " ");
                }
                Console.WriteLine();
            }*/

            totalCost += 1;
        }
    }
}