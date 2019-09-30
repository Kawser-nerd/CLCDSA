using System;
using System.Collections.Generic;
class Program
    {
    	static void Main(string[] args)
    	{
            string[] s0 = Console.ReadLine().Split(' ');
            int h = int.Parse(s0[0]);
            int w = int.Parse(s0[1]);
            int k = int.Parse(s0[2]);
            int[,] map = new int[h, w];
            Queue<int[]> queue = new Queue<int[]>();
            
            for (int i=0; i<h; i++)
            {
                string s = Console.ReadLine();
                for (int j=0; j<w; j++)
                {
                    switch (s[j])
                    {
                        case '.':
                        map[i, j] = -1;
                        break;

                        case '#':
                        map[i, j] = -2;
                        break;

                        case 'S':
                        map[i, j] = 0;
                        queue.Enqueue(new int[] {i, j});
                        break;
                    }
                }
            }

            int dist = 999;

            while (queue.Count > 0)
            {
                int[] pos = queue.Dequeue();
                int posX = pos[0];
                int posY = pos[1];
                if (map[posX, posY] > k) break;
                int newDist = Math.Min(Math.Min(Math.Min(posX, posY), h-1-posX), w-1-posY);
                if (newDist < dist) dist = newDist;
                if (dist == 0) break;

                if (map[posX + 1, posY] == -1)
                {
                    map[posX + 1, posY] = map[posX, posY] + 1;
                    queue.Enqueue(new int[] {posX + 1, posY});
                }
                if (map[posX - 1, posY] == -1)
                {
                    map[posX - 1, posY] = map[posX, posY] + 1;
                    queue.Enqueue(new int[] {posX - 1, posY});
                }
                if (map[posX, posY + 1] == -1)
                {
                    map[posX, posY + 1] = map[posX, posY] + 1;
                    queue.Enqueue(new int[] {posX, posY + 1});
                }
                if (map[posX, posY - 1] == -1)
                {
                    map[posX + 1, posY] = map[posX, posY] + 1;
                    queue.Enqueue(new int[] {posX, posY - 1});
                }
            }
            if (dist == 0) Console.WriteLine(1);
            else Console.WriteLine((dist - 1) / k + 2);

            
            
        }
    }
    //mcs Main.cs
    //mono Main.exe