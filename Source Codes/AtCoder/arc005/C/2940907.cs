using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int H, W, SY, SX, GY, GX;
        public char[,] M;
        public bool[,,] USED; // y, x, Destruction
        public int[] DX = new int[] { 1, 0, -1, 0 };
        public int[] DY = new int[] { 0, 1, 0, -1 };
        public bool success;

        public void Run()
        {
            {
                var line = Input.ReadIntArray();
                H = line[0];
                W = line[1];
            }
          
            M = new char[H, W];
            for (int y = 0; y < H; y++)
            {
                var line = Console.ReadLine();
                for (int x = 0; x < W; x++)
                    M[y, x] = line[x];
            }

            for (int y = 0; y < H; y++)
            for (int x = 0; x < W; x++)
            {
                if (M[y, x] == 's')
                {
                    SY = y;
                    SX = x;
                }

                if (M[y, x] == 'g')
                {
                    GY = y;
                    GX = x;
                }
            }

            BFS();
            Console.WriteLine(success ? "YES" : "NO");

        }

        public void BFS()
        {
            success = false;

            USED = new bool[H, W, 3];
            for (int y = 0; y < H; y++)
            for (int x = 0; x < W; x++)
            for (int d = 0; d <= 2; d++)
            {
                USED[y, x, d] = false;
            }

            var queue = new Queue<Data>();
            queue.Enqueue(new Data { i = 0, y = SY, x = SX, crash = 0 });
            while (queue.Count > 0)
            {
                var d = queue.Dequeue();
                if (USED[d.y, d.x, d.crash]) continue; // ??????????TLE???
                if (d.y == GY && d.x == GX) success = true;
                USED[d.y, d.x, d.crash] = true;

                for (int dr = 0; dr < DY.Length; dr++)
                {
                    int yy = d.y + DY[dr];
                    int xx = d.x + DX[dr];
                    if (0 <= yy && yy < H && 0 <= xx && xx < W)
                        if (M[yy, xx] == '#')
                        {
                            if(d.crash < 2)
                               queue.Enqueue(new Data { i = d.i + 1, y = yy, x = xx, crash = d.crash+1});
                        }
                        else
                        {
                            queue.Enqueue(new Data { i = d.i + 1, y = yy, x = xx, crash = d.crash });
                        }
                       
                }
            }
        }
    }

    // lib
    class Data
    {
        public int x;
        public int y;
        public int i;
        public int crash;
    }


    // common ----------

    internal static class Input
    {
        public static string ReadString()
        {
            string line = Console.ReadLine();
            return line;
        }

        public static int ReadInt()
        {
            string line = Console.ReadLine();
            return int.Parse(line);
        }

        public static int[] ReadIntArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(int.Parse).ToArray();            
        }

        public static long ReadLong()
        {
            string line = Console.ReadLine();
            return long.Parse(line);
        }

        public static long[] ReadLongArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(long.Parse).ToArray();
        }

        public static double[] ReadDoubleArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(double.Parse).ToArray();
        }
    }
    
    internal class Program
    {
        public static void Main(string[] args)
        {
            var s = new Solution();
            s.Run();
        }
    }
}