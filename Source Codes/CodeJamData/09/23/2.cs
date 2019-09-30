using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;

public class C
{
    static int W;
    static string[] map;

    static bool[, , ,] done, mem;

    static bool rec(int x, int y, int target, int deep)
    {
        if (target == 0) return true;
        if (deep == 0) return false;
        if (done[x, y, target + 600, deep])
            return mem[x, y, target + 600, deep];
        done[x, y, target + 600, deep] = true;
        mem[x, y, target + 600, deep] = false;

        foreach (neighbour n in neighbours(x, y))
        {
            int nt = (n.sign == '+' ? target - n.dig : target + n.dig);
            if (rec(n.x, n.y, nt, deep - 1))
            {
                mem[x, y, target + 600, deep] = true;
                break;
            }
        }
        return mem[x, y, target + 600, deep];
    }

    struct neighbour
    {
        public int x, y, dig;
        public char sign;

        public neighbour(int x, int y, char sign, int dig)
        {
            this.x = x;
            this.y = y;
            this.sign = sign;
            this.dig = dig;
        }
    }
    struct point
    {
        public int x, y;
        public point(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }

    static int[] dx = { -1, 0, 1, 0 };
    static int[] dy = { 0, 1, 0, -1 };

    static IEnumerable<neighbour> neighbours(int x, int y)
    {
        for (int i = 0; i < 4; i++)
        {
            int nx1 = x + dx[i];
            int ny1 = y + dy[i];
            if (nx1 < 0 || nx1 >= W || ny1 < 0 || ny1 >= W)
                continue;
            for (int j = 0; j < 4; j++)
            {
                int nx2 = nx1 + dx[j];
                int ny2 = ny1 + dy[j];
                if (nx2 < 0 || nx2 >= W || ny2 < 0 || ny2 >= W)
                    continue;

                yield return new neighbour(nx2, ny2, map[nx1][ny1], map[nx2][ny2] - '0');
            }
        }
    }

    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.WriteLine("Case #" + CASE + ":");
            string[] parts = Console.ReadLine().Split();
            W = int.Parse(parts[0]);
            int Q = int.Parse(parts[1]);

            map = new string[W];
            for (int i = 0; i < W; i++)
                map[i] = Console.ReadLine();

            done = new bool[W, W, 2000, 251];
            mem = new bool[W, W, 2000, 251];
            parts = Console.ReadLine().Split();
            for (int i = 0; i < Q; i++)
            {
                int query = int.Parse(parts[i]);

                bool found = false;
                int dept = -1;
                while (!found)
                {
                    dept++;
                    for (int x = 0; !found && x < W; x++)
                    {
                        for (int y = 0; !found && y < W; y++)
                        {
                            if (!char.IsDigit(map[x][y]))
                                continue;

                            int tg = query - map[x][y] + '0';
                            if (rec(x, y, tg, dept))
                                found = true;
                        }
                    }
                }
                // we know dept, now find output

                List<point> act = new List<point>();
                
                int sd = 100;

                int target;

                for (int x = 0; x < W; x++)
                {
                    for (int y = 0; y < W; y++)
                    {
                        if (!char.IsDigit(map[x][y]))
                            continue;

                        target = query - map[x][y] + '0';
                        if (rec(x, y, target, dept))
                        {
                            if (map[x][y] - '0' < sd)
                            {
                                sd = map[x][y] - '0';
                                act.Clear();
                                act.Add(new point(x, y));
                            }
                            else if (map[x][y] - '0' == sd)
                            {
                                act.Add(new point(x, y));
                            }
                        }
                    }
                }

                target = query - sd;

                string ret = sd.ToString();
                for (int dp = dept - 1; dp >= 0; dp--)
                {
                    char so = (char)100;
                    sd = 100;

                    bool[,] newdone = new bool[W, W];
                    List<point> newact = new List<point>();

                    foreach (point p in act)
                    {
                        foreach (neighbour n in neighbours(p.x, p.y))
                        {
                            int nt = (n.sign == '+' ? target - n.dig : target + n.dig);
                            if (rec(n.x, n.y, nt, dp))
                            {
                                if (n.sign < so || (n.sign == so && n.dig < sd))
                                {
                                    newact.Clear();
                                    newact.Add(new point(n.x, n.y));
                                    for (int k = 0; k < W; k++) for (int j = 0; j < W; j++)
                                            newdone[k, j] = false;
                                    newdone[n.x, n.y] = true;
                                    so = n.sign;
                                    sd = n.dig;
                                }
                                else if (n.sign == so && n.dig == sd)
                                {
                                    if (!newdone[n.x, n.y])
                                    {
                                        newact.Add(new point(n.x, n.y));
                                        newdone[n.x, n.y] = true;
                                    }
                                }
                            }
                        }
                    }

                    ret += so.ToString() + sd.ToString();
                    target = (so == '+' ? target - sd : target + sd);

                    act = newact;
                }

                Console.WriteLine(ret);
            }
        }
    }
}
