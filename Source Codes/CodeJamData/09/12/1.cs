using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;

struct Point : IEquatable<Point>
{
    public int X; public int Y;
    public Point(int x, int y) { X = x; Y = y; }
    public bool Equals(Point p) { return p.X == X && p.Y == Y; }
    public override int GetHashCode() { return (int)(X * 3137 + Y); }
}

struct Traffic : IEquatable<Traffic>
{
    public int X; public int Y; public int Z;
    public Traffic(int x, int y, int z) { X = x; Y = y; Z = z; }
    public bool Equals(Traffic p) { return p.X == X && p.Y == Y && p.Z == Z; }
    public override int GetHashCode() { return (int)(X * 3137 * 3137 + Y * 3137 + Z); }
}

class Problem
{
    const string inFile = "..\\..\\blarge.in";
    const string outFile = "..\\..\\blarge.out";

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

                    Traffic[,] a = new Traffic[m, n];
                    for (int i = 0; i < m; i++)
                    {
                        ss = Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), int.Parse);
                        for (int j = 0; j < n; j++)
                        {
                            a[i, j] = new Traffic(ss[j*3], ss[j*3 + 1], ss[j*3 + 2]);
                        }
                    }

                    string res = Solve(m, n, a);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }

    int waitTime(int time, Traffic b, bool goNorth)
    {
        if (goNorth)
        {
            if (time >= b.Z)
            {
                time = (time - b.Z) % (b.X + b.Y);

                if (time < b.X)
                    return 0;
                else
                    return b.Y - (time - b.X);
            }
            else
            {
                time = (b.Z - time);
                if (time > b.Y)
                    return 0;
                else
                    return time;
            }
        }
        else
        {
            if (time >= b.Z)
            {
                time = (time - b.Z) % (b.X + b.Y);

                if (time < b.X)
                    return b.X - time;
                else
                    return 0;
            }
            else
            {
                time = (b.Z - time);
                if (time > b.Y)
                    return time - b.Y;
                else
                    return 0;
            }

        }
    }

    string Solve(int m, int n, Traffic[,] a)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i, j].Z = a[i, j].Z % (a[i, j].X + a[i, j].Y);
            }
        }

        int m2 = m * 2;
        int n2 = n * 2;

        Point start = new Point(m2-1, 0);
        Point end = new Point(0, n2 - 1);
        Dictionary<Point, int> f = new Dictionary<Point, int>();
        f[start] = 0;

        Queue<Point> q = new Queue<Point>();
        q.Enqueue(start);
        int res = int.MaxValue;
        while (q.Count > 0)
        {
            Point p = q.Dequeue();
            
            int time = f[p];

            if (p.Equals(end))
            {
                res = Math.Min(res, time);
                continue;
            }

            Traffic gt = a[p.X / 2, p.Y / 2];

            int cost = 0;

            // up
            if (p.X > 0)
            {
                if (p.X % 2 == 1)
                {
                    int wait = waitTime(time, gt, true);
                    cost = wait + 1;
                }
                else
                {
                    cost = 2;
                }

                Point next = new Point(p.X - 1, p.Y);

                if (!f.ContainsKey(next) || f[next] > time + cost)
                {
                    f[next] = time + cost;
                    q.Enqueue(next);
                }
            }

            // down
            if (p.X < m2 - 1)
            {
                if (p.X % 2 == 0)
                {
                    int wait = waitTime(time, gt, true);
                    cost = wait + 1;
                }
                else
                {
                    cost = 2;
                }

                Point next = new Point(p.X + 1, p.Y);
                if (!f.ContainsKey(next) || f[next] > time + cost)
                {
                    f[next] = time + cost;
                    q.Enqueue(next);
                }
            }
             
            // right
            if (p.Y < n2 - 1)
            {
                if (p.Y % 2 == 0)
                {
                    int wait = waitTime(time, gt, false);
                    cost = wait + 1;
                }
                else
                {
                    cost = 2;
                }

                Point next = new Point(p.X, p.Y + 1);
                if (!f.ContainsKey(next) || f[next] > time + cost)
                {
                    f[next] = time + cost;
                    q.Enqueue(next);
                }
            }

            // left
            if (p.Y > 0)
            {
                if (p.Y % 2 == 1)
                {
                    int wait = waitTime(time, gt, false);
                    cost = wait + 1;
                }
                else
                {
                    cost = 2;
                }

                Point next = new Point(p.X, p.Y - 1);
                if (!f.ContainsKey(next) || f[next] > time + cost)
                {
                    f[next] = time + cost;
                    q.Enqueue(next);
                }
            }
        }
        return res.ToString();
    }

    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}