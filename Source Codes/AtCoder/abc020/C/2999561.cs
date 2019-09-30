using System;
using System.Collections.Generic;

namespace AtTest.C_Challenge
{
    class ABC_020
    {
        static Node[,] nodes;
        static int h, w;

        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            h = int.Parse(input[0]);
            w = int.Parse(input[1]);
            long t = long.Parse(input[2]);
            var isWhite = new bool[h, w];
            int sx = 0, sy = 0, gx = 0, gy = 0;

            for (int i = 0; i < h; i++)
            {
                string str = Console.ReadLine();
                for (int j = 0; j < w; j++)
                {
                    isWhite[i, j] = str[j] != '#';
                    if (str[j] == 'S')
                    {
                        sx = j;
                        sy = i;
                    }
                    else if (str[j] == 'G')
                    {
                        gx = j;
                        gy = i;
                    }
                }
            }

            nodes = new Node[h, w];
            /*for (long x = t - 1; x >= 0; x--)
            {
                for (int i = 0; i < h; i++)
                {
                    for (int j = 0; j < w; j++)
                    {
                        nodes[i, j] = new Node(h, w, isWhite[i, j]);
                        nodes[i, j].distances[i, j] = 0;
                        nodes[i, j].isMin[i, j] = true;
                    }
                }
                Dijkstra(sx, sy, x);
                if (nodes[sy, sx].distances[gy, gx] <= t)
                {
                    Console.WriteLine(x);
                    return;
                }
            }*/

            long bottom = 1;
            long top = t;
            long x = (top + bottom) / 2;
            while (top - bottom > 1)
            {
                for (int i = 0; i < h; i++)
                {
                    for (int j = 0; j < w; j++)
                    {
                        nodes[i, j] = new Node(h, w, isWhite[i, j]);
                        nodes[i, j].distances[i, j] = 0;
                        nodes[i, j].isMin[i, j] = true;
                    }
                }
                Dijkstra(sx, sy, x);
                //Console.WriteLine(bottom.ToString() + " " + x.ToString() + " " + top.ToString());
                //Console.WriteLine(nodes[sy, sx].distances[gy, gx]);
                if (nodes[sy, sx].distances[gy, gx] <= t)
                {
                    bottom = x;
                }
                else
                {
                    top = x;
                }
                x = (top + bottom) / 2;
            }

            Console.WriteLine(x);
        }

        //???????
        static long Dijkstra(int x, int y, long blackCost)
        {
            Node startNode = nodes[y, x];
            int nowX = x;
            int nowY = y;
            int cnt = 1;

            while (cnt < h * w)
            {
                for (int i = 0; i < 4; i++)
                {
                    int[] dire = FourDirection(i);
                    int tempX = nowX + dire[0];
                    int tempY = nowY + dire[1];
                    if (tempX < 0 || w <= tempX
                        || tempY < 0 || h <= tempY) continue;

                    if (startNode.isMin[tempY, tempX]) continue;//????????

                    long distance = startNode.distances[nowY, nowX];
                    distance += nodes[tempY, tempX].cost == 1 ? 1 : blackCost;
                    if (startNode.distances[tempY, tempX] == -1
                        || distance < startNode.distances[tempY, tempX])
                    {
                        startNode.distances[tempY, tempX] = distance;
                    }
                }

                int settleX = -1, settleY = -1;
                for (int i = 0; i < h; i++)//????????
                {
                    for (int j = 0; j < w; j++)
                    {
                        if (startNode.isMin[i, j] 
                            || startNode.distances[i, j] == -1) continue;

                        if (settleX == -1
                            || startNode.distances[i, j]
                            < startNode.distances[settleY, settleX])
                        {
                            settleY = i;
                            settleX = j;
                        }
                    }
                }
                startNode.isMin[settleY, settleX] = true;

                nowX = settleX;
                nowY = settleY;
                cnt++;
            }

            long maxDistance = 0;
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    if (maxDistance < startNode.distances[i, j])
                    {
                        maxDistance = startNode.distances[i, j];
                    }
                }
            }

            return maxDistance;
        }

        //(x,y)???
        static int[] FourDirection(int index)
        {
            int[] direction = new int[2];
            switch (index)
            {
                case 0:
                    direction[0] = 1;
                    direction[1] = 0;
                    break;
                case 1:
                    direction[0] = 0;
                    direction[1] = 1;
                    break;
                case 2:
                    direction[0] = -1;
                    direction[1] = 0;
                    break;
                case 3:
                    direction[0] = 0;
                    direction[1] = -1;
                    break;
            }
            return direction;
        }
    }

    class Node
    {
        public long[,] distances;
        public bool[,] isMin;
        public int cost;
        public Node(int h,int w,bool isWhite)
        {
            distances = new long[h, w];
            isMin = new bool[h, w];
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    distances[i, j] = -1;
                    isMin[i, j] = false;
                }
            }
            cost = isWhite ? 1 : -1;
        }
    }
}