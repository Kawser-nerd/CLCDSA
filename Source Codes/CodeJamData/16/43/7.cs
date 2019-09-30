using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class C
{
    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Error.WriteLine("Case " + CASE);
            string[] ps = Console.ReadLine().Split();
            int R = int.Parse(ps[0]);
            int C = int.Parse(ps[1]);
            int N = 2 * (R + C);
            int[] perm = new int[N];
            ps = Console.ReadLine().Split();
            for (int i = 0; i < N; i++)
                perm[i] = int.Parse(ps[i]);

            int[] loves = new int[N];
            for (int i = 0; i < perm.Length; i += 2)
            {
                loves[perm[i] - 1] = perm[i + 1] - 1;
                loves[perm[i + 1] - 1] = perm[i] - 1;
            }

            bool possible = true;
            char[][] grid = new char[R][];
            for (int i = 0; i < R; i++) grid[i] = new char[C];
            
            bool[] conn = new bool[N];
            while(true)
            {
                int p1 = -1;
                int p2 = -1;

                bool have = false;
                for(int i = 0; i < N; i++)
                {
                    if (conn[i]) continue;
                    have = true;
                    for(int j = i + 1; j < N; j++)
                    {
                        if (loves[i] == j)
                        {
                            p1 = i;
                            p2 = j;
                        }
                        else if (!conn[j]) break;
                    }
                }

                if (p1 == -1)
                {
                    if (have) possible = false;
                    break;
                }

                // connect p1 and p2

                loc loc = getLoc(R, C, p1);
                int px = loc.x;
                int py = loc.y;
                int d = loc.d; // top, right, down, left
                

                while (!(px < 0 || py < 0 || px >= C || py >= R))
                {
                    if (grid[py][px] == 0)
                    {
                        if (d == 0 || d == 2) grid[py][px] = '\\';
                        if (d == 1 || d == 3) grid[py][px] = '/';
                    }

                    // oh, the horror, there must be a bug here somewhere...
                    if (d == 0 && grid[py][px] == '/')
                    {
                        px--;
                        d = 1;
                    }
                    else if (d == 0 && grid[py][px] == '\\')
                    {
                        px++;
                        d = 3;
                    }
                    else if (d == 1 && grid[py][px] == '/')
                    {
                        py++;
                        d = 0;
                    }
                    else if (d == 1 && grid[py][px] == '\\')
                    {
                        py--;
                        d = 2;
                    }
                    else if (d == 2 && grid[py][px] == '/')
                    {
                        px++;
                        d = 3;
                    }
                    else if (d == 2 && grid[py][px] == '\\')
                    {
                        px--;
                        d = 1;
                    }
                    else if (d == 3 && grid[py][px] == '/')
                    {
                        py--;
                        d = 2;
                    }
                    else if (d == 3 && grid[py][px] == '\\')
                    {
                        py++;
                        d = 0;
                    }
                    else
                    {
                        throw new Exception("Oh man...");
                    }
                }

                // todo: check if pos is ok
                loc loc2 = getLoc(R, C, p2);
                int[] dy = { -1, 0, 1, 0 };
                int[] dx = { 0, 1, 0, -1 };
                if(loc2.x + dx[loc2.d] != px || loc2.y + dy[loc2.d] != py)
                {
                    possible = false;
                    break;
                }

                conn[p1] = conn[p2] = true;
            }


            // fill in random chars
            for(int i = 0; i < R; i++)
            {
                for(int j = 0; j < C; j++)
                {
                    if(grid[i][j] == 0)
                    {
                        grid[i][j] = '/'; // randomly chosen by me
                    }
                }
            }

            // print
            Console.WriteLine("Case #" + CASE + ":");
            if (possible)
            {
                for (int i = 0; i < R; i++)
                    Console.WriteLine(new string(grid[i]));
            }
            else
            {
                Console.WriteLine("IMPOSSIBLE");
            }
        }
    }

    public struct loc
    {
        public int x, y, d;
    }

    public static loc getLoc(int R, int C, int p1)
    {
        loc ret;
        if (p1 < C)
        {
            ret.x = p1;
            ret.y = 0;
            ret.d = 0;
        }
        else if (p1 < C + R)
        {
            ret.x = C - 1;
            ret.y = p1 - C;
            ret.d = 1;
        }
        else if (p1 < C + R + C)
        {
            ret.x = C + R + C - p1 - 1;
            ret.y = R - 1;
            ret.d = 2;
        }
        else
        {
            ret.x = 0;
            ret.y = R + C + R + C - p1 - 1;
            ret.d = 3;
        }
        return ret;
    }
}
