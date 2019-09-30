using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;

struct State : IEquatable<State>
{
    public readonly int x, y, blue, blueDir, yellow, yellowDir;

    public State(int x, int y, int blue, int blueDir, int yellow, int yellowDir)
    {
        this.x = x;
        this.y = y;
        this.blue = blue;
        this.yellow = yellow;
        this.blueDir = blueDir;
        this.yellowDir = yellowDir;
    }

    #region IEquatable<State> Members

    public bool  Equals(State other)
    {
 	    return this.x == other.x && this.y == other.y && this.blue == other.blue && this.yellow == other.yellow
            && this.blueDir == other.blueDir && this.yellowDir == other.yellowDir;
    }

    public override int  GetHashCode()
    {
        unchecked
        {
            return x * 3137 * 3137 * 3137 * 3137 * 3137 + y * 3137 * 3137 * 3137 * 3137 +
                blue * 3137 * 3137 * 3137 + yellow * 3137 * 3137 + blueDir * 3137 + yellowDir;
        }
    }

    #endregion
}

struct Point : IEquatable<Point>
{
    public int X; public int Y;
    public Point(int x, int y) { X = x; Y = y; }
    public bool Equals(Point p) { return p.X == X && p.Y == Y; }
    public override int GetHashCode() { return (int)(X * 3137 + Y); }
}

class Problem
{
    const string inFile = "..\\..\\bsmall.in";
    const string outFile = "..\\..\\bsmall.out";
    const int INF = 987654321;

    public void Process()
    {
        using (StreamReader sr = new StreamReader(inFile))
        {
            using (StreamWriter sw = new StreamWriter(outFile))
            {
                int numCases = int.Parse(sr.ReadLine());
                Console.WriteLine("There are {0} test cases.", numCases);
                for (int @case = 1; @case <= numCases; @case++)
                {
                    int[] ss = Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), int.Parse);
                    int m = ss[0];
                    int n = ss[1];
                    char[,] a = new char[m, n];

                    for (int i = 0; i < m; i++)
                    {
                        string s = sr.ReadLine();
                        for (int j = 0; j < s.Length; j++)
                        {
                            a[i, j] = s[j];
                        }
                    }

                    string res = Solve(m, n, a);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }

    void fire(int x, int y, int dir, char[,] a, out int tx, out int ty)
    {
        int m = a.GetLength(0);
        int n = a.GetLength(1);
        int u = x, v = y;
        do
        {
            u = x + dx[dir];
            v = y + dy[dir];

            if (u >= 0 && v >= 0 && u < m && v < n && a[u, v] != '#')
            {
                x = u;
                y = v;
            }
            else break;
        }
        while (true);

        tx = x;
        ty = y;
    }

    int[] dx = new int[] { -1, 0, 1, 0 };
    int[] dy = new int[] { 0, 1, 0, -1 };
    Dictionary<State, int> f;
    Queue<State> q;

    string Solve(int m, int n, char[,] a)
    {
        int startx = 0, starty = 0, endx = 0, endy = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i, j] == 'O')
                {
                    startx = i;
                    starty = j;
                }
                else if (a[i, j] == 'X')
                {
                    endx = i;
                    endy = j;
                }
            }
        }

        Point[, ,] g = new Point[m, n, 4];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i, j] != '#')
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int u, v;
                        fire(i, j, k, a, out u, out v);
                        g[i, j, k] = new Point(u, v);
                    }
                }
            }
        }

        State start = new State(startx, starty, -1, 0, -1, 0);
        f = new Dictionary<State, int>();
        f[start] = 0;
        q = new Queue<State>();
        q.Enqueue(start);

        int res = INF;
        while (q.Count > 0)
        {
            State p = q.Dequeue();
            //Console.WriteLine("{0} {1}", p.x, p.y);
            int cost = f[p];

            int bx = p.blue / n;
            int by = p.blue % n;

            int cx = p.yellow / n;
            int cy = p.yellow % n;

            if (a[p.x, p.y] == 'X')
            {
                res = Math.Min(res, cost);
                continue;
            }

            for (int t = 0; t < 4; t++)
            {
                Point fire = g[p.x, p.y, t];

                if (!(fire.X == bx && fire.Y == by && t == p.blueDir ||
                    fire.X == cx && fire.Y == cy && t == p.yellowDir))
                {
                    State next = new State(p.x, p.y, fire.X * n + fire.Y, t, p.yellow, p.yellowDir);
                    if (!f.ContainsKey(next) || f[next] > cost)
                    {
                        f[next] = cost;
                        q.Enqueue(next);
                    }

                    next = new State(p.x, p.y, p.blue, p.blueDir, fire.X * n + fire.Y, t);
                    if (!f.ContainsKey(next) || f[next] > cost)
                    {
                        f[next] = cost;
                        q.Enqueue(next);
                    }
                }
            }

            for (int t = 0; t < 4; t++)
            {
                int u = p.x + dx[t];
                int v = p.y + dy[t];
                if (u >= 0 && v >= 0 && u < m && v < n && a[u,v] != '#')
                {
                    State next = new State(u, v, p.blue, p.blueDir, p.yellow, p.yellowDir);
                    if (!f.ContainsKey(next) || f[next] > cost + 1)
                    {
                        f[next] = cost + 1;
                        q.Enqueue(next);
                    }
                }
                else if (p.blue != -1 && p.yellow != -1)
                {
                    if (p.x == bx && p.y == by && p.blueDir == t)
                    {
                        State next = new State(cx, cy, p.blue, p.blueDir, p.yellow, p.yellowDir);
                        if (!f.ContainsKey(next) || f[next] > cost + 1)
                        {
                            f[next] = cost + 1;
                            q.Enqueue(next);
                        }
                    }

                    if (p.x == cx && p.y == cy && p.yellowDir == t)
                    {
                        State next = new State(bx, by, p.blue, p.blueDir, p.yellow, p.yellowDir);
                        if (!f.ContainsKey(next) || f[next] > cost + 1)
                        {
                            f[next] = cost + 1;
                            q.Enqueue(next);
                        }
                    }
                }
            }
        }
        return res >= INF ? "THE CAKE IS A LIE" : res.ToString();
    }

    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}