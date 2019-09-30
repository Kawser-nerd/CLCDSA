using System;
using System.Collections.Generic;

namespace Atcoder
{
    class Program
    {

        static int R, C, sy, sx, gy, gx, ans;
        static char[,] map;
        public static void Main(string[] arg)
        {
            Solve();
         //   Console.ReadKey();
        }
        static void Solve()
        {
            string[] input = Console.ReadLine().Split();
            R = int.Parse(input[0]);
            C = int.Parse(input[1]);

            input = Console.ReadLine().Split();
            sy = int.Parse(input[0]) - 1;
            sx = int.Parse(input[1]) - 1;

            input = Console.ReadLine().Split();
            gy = int.Parse(input[0]) - 1;
            gx = int.Parse(input[1]) - 1;

            char[] c;
            map = new char[R, C];

            for (int i = 0; i < R; i++)
            {
                c = Console.ReadLine().ToCharArray();
                for (int j = 0; j < C; j++)
                {
                    map[i, j] = c[j];
                }
            }

            Bfs(sy, sx);
            Console.WriteLine(ans);
            Console.ReadKey();

        }
        static void Bfs(int y, int x)
        {
            var yPos = new Queue<int>();
            var xPos = new Queue<int>();
            var cnt = new Queue<int>();
            int nowY, nowX, nowCnt;
            int[] vy = new int[] { 1, 0, -1, 0 };
            int[] vx = new int[] { 0, 1, 0, -1 };
            yPos.Enqueue(y);
            xPos.Enqueue(x);
            cnt.Enqueue(0);

            while (yPos.Count > 0 && xPos.Count > 0)
            {
                nowY = yPos.Dequeue();
                nowX = xPos.Dequeue();
                nowCnt = cnt.Dequeue();

                if (nowY == gy && nowX == gx)
                {
                    ans = nowCnt;
                    return;
                }
                for (int i = 0; i < 4; i++)
                {
                    int ny = nowY + vy[i];
                    int nx = nowX + vx[i];
                    if (map[ny, nx] == '.')
                    {
                        yPos.Enqueue(ny);
                        xPos.Enqueue(nx);
                        cnt.Enqueue(nowCnt + 1);
                        map[ny, nx] = '-';
                    }
                }

            }

        }
    }
}