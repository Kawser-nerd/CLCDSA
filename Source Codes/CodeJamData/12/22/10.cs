using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;
using System.Numerics;

struct State : IEquatable<State>
{
    public int X; public int Y; public int Water;
    public State(int x, int y, int water) { X = x; Y = y; Water = water; }
    public bool Equals(State p) { return p.X == X && p.Y == Y && p.Water == Water; }
    public override int GetHashCode() { unchecked { return (int)(X * 3137 * 3137 + Y * 3137 + Water); } }
}

class Problem
{
    const string inFile = "..\\..\\bsmall.in";
    const string outFile = "..\\..\\bsmall.out";

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

                    int H = ss[0];
                    int m = ss[1];
                    int n = ss[2];

                    int[,] floors = new int[m,n];
                    int[,] ceils = new int[m,n];

                    for (int i = 0; i < m; i++)
                    {
                        ss = Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), int.Parse);
                        for (int j = 0; j < n; j++)
                        {
                            ceils[i, j] = ss[j];
                        }
                    }

                    for (int i = 0; i < m; i++)
                    {
                        ss = Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), int.Parse);
                        for (int j = 0; j < n; j++)
                        {
                            floors[i, j] = ss[j];
                        }
                    }

                    string res = Solve(m, n, H, floors, ceils);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }

    private string Solve(int m, int n, int H, int[,] floors, int[,] ceils)
    {
        bool[,] good = flood(m, n, H, floors, ceils);

        if (good[m - 1, n - 1])
        {
            return "0.0";
        }

        double time = calc(good, m, n, H, floors, ceils);
        return time.ToString();
    }

    private double calc(bool[,] good, int m, int n, int H, int[,] floors, int[,] ceils)
    {
        double res = double.MaxValue;
        
        Dictionary<State, double> f = new Dictionary<State, double>();
        Queue<State> q = new Queue<State>();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (good[i, j])
                {
                    State s = new State(i, j, H);
                    f[s] = 0;
                    q.Enqueue(s);
                }
            }
        }

        while (q.Count > 0)
        {
            State p = q.Dequeue();
            double cost = f[p];
            if (p.X == m - 1 && p.Y == n - 1)
            {
                res = Math.Min(res, cost);
                continue;
            }

            for (int i = 0; i < 4; i++)
            {
                int tx = p.X + dx[i];
                int ty = p.Y + dy[i];
                if (tx >= 0 && tx < m && ty >= 0 && ty < n)
                {
                    int water = p.Water;
                    double waitTime = 0;
                    if (p.Water + 50 > ceils[tx, ty])
                    {
                        water = Math.Max(0, ceils[tx, ty] - 50);
                        waitTime = (p.Water - water)/10.0;
                    }

                    if (canGo(p.X, p.Y, tx, ty, floors, ceils, water))
                    {
                        if (water >= floors[p.X, p.Y] + 20)
                        {
                            int newWater = Math.Max(0, water - 10);
                            State next = new State(tx, ty, newWater);
                            if (!f.ContainsKey(next) || f[next] > cost + waitTime + 1)
                            {
                                f[next] = cost + waitTime + 1;
                                q.Enqueue(next);
                            }
                        }
                        else
                        {
                            int newWater = Math.Max(0, water - 100);
                            State next = new State(tx, ty, newWater);
                            if (!f.ContainsKey(next) || f[next] > cost + waitTime + 10)
                            {
                                f[next] = cost + waitTime + 10;
                                q.Enqueue(next);
                            }
                        }
                    }
                }
            }
        }

        return res;
    }

    int[] dx = new int[] { -1, 0, 1, 0 };
    int[] dy = new int[] { 0, 1, 0, -1 };

    private bool[,] flood(int m, int n, int H, int[,] floors, int[,] ceils)
    {
        bool[,] good = new bool[m,n];

        State start = new State(0, 0, m);
        Queue<State> q = new Queue<State>();
        q.Enqueue(start);
        while (q.Count > 0)
        {
            State p = q.Dequeue();
            good[p.X, p.Y] = true;

            for (int i = 0; i < 4; i++)
            {
                int tx = p.X + dx[i];
                int ty = p.Y + dy[i];
                if (tx >= 0 && tx < m && ty >= 0 && ty < n && !good[tx, ty])
                {
                    if (canGo(p.X, p.Y, tx, ty, floors, ceils, H))
                    {
                        q.Enqueue(new State(tx, ty, 0));
                    }
                }
            }
        }
        return good;
    }

    private bool canGo(int x, int y, int tx, int ty, int[,] floors, int[,] ceils, int H)
    {
        return H + 50 <= ceils[tx, ty] &&
               floors[tx, ty] + 50 <= ceils[tx, ty] &&
               floors[x, y] + 50 <= ceils[tx, ty] &&
               floors[tx, ty] + 50 <= ceils[x, y];
    }

    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}