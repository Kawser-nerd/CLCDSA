using System;
using System.Collections.Generic;
using System.Linq;

public struct Point
{
    public int X;
    public int Y;

    public Point(Point p)
    {
        X = p.X;
        Y = p.Y;
    }

    public Point(int x, int y)
    {
        X = x;
        Y = y;
    }

    public static bool operator ==(Point a, Point b)
    {
        return (a.X == b.X && a.Y == b.Y);
    }

    public static bool operator !=(Point a, Point b)
    {
        return !(a == b);
    }

    //obj????????????true???
    public override bool Equals(object obj)
    {
        if (!(obj is Point))
        {
            return false;
        }

        Point p = (Point)obj;
        return (X == p.X && Y == p.Y);
    }

    //Equals?true????????????
    public override int GetHashCode()
    {
        return (X << 16) ^ Y;
    }

    public Point Clone()
    {
        return new Point(X, Y);
    }

    public void Reverse()
    {
        X = -X;
        Y = -Y;
    }

    public static Point operator +(Point a, Point b)
    {
        return new Point(a.X + b.X, a.Y + b.Y);
    }

    public static Point operator -(Point a, Point b)
    {
        return new Point(a.X - b.X, a.Y - b.Y);
    }

    public static Point operator *(Point a, int i)
    {
        return new Point(a.X * i, a.Y * i);
    }

    public static Point operator /(Point a, int i)
    {
        return new Point(a.X / i, a.Y / i);
    }
    public static Point operator +(Point a)
    {
        return new Point(+a.X, +a.Y);
    }

    public static Point operator -(Point a)
    {
        return new Point(-a.X, -a.Y);
    }

    public override string ToString()
    {
        return string.Format("({0},{1})", X, Y);
    }
}

public class HopcroftKarp
{
    readonly int U;  // 1??U?????
    readonly int V;  // 1??V?????
    readonly List<int>[] link; // link[u] = [v0, v1 ,...]
    const int nil = 0; // ?????
    int[] distance;
    int[] pairU;  // pairU[u] = v
    int[] pairV;  // pairV[v] = u

    HopcroftKarp(int u, int v, List<int>[] link)
    {
        U = u;
        V = v;
        this.link = link;
        distance = new int[u + 1];
        pairU = new int[v + 1];
        pairV = new int[u + 1];
    }

    bool Bfs()
    {
        var queue = new Queue<int>();
        for (int u = 1; u <= U; u++)
        {
            if (pairU[u] == nil)
            {
                distance[u] = 0;
                queue.Enqueue(u);
            }
            else
            {
                distance[u] = int.MaxValue;
            }
        }
        distance[nil] = int.MaxValue;

        while (queue.Count > 0)
        {
            var u = queue.Dequeue();
            if (distance[u] < distance[nil])
            {
                foreach (var v in link[u])
                {
                    var nextU = pairV[v];
                    if (distance[nextU] == int.MaxValue)
                    {
                        distance[nextU] = distance[u] + 1;
                        queue.Enqueue(nextU);
                    }
                }
            }
        }
        return distance[nil] != int.MaxValue;
    }

    bool Dfs(int u)
    {
        if (u == nil)
        {
            return true;
        }

        foreach (var v in link[u])
        {
            var nextU = pairV[v];
            if (distance[nextU] == distance[u] + 1)
            {
                if (Dfs(nextU))
                {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }

        distance[u] = int.MaxValue; // ????????
        return false;
    }

    int Solve()
    {
        // PairU,V????nil(0)??????
        int matching = 0;
        while (Bfs())
        {
            for (int u = 1; u <= U; u++)
            {
                if (pairU[u] == nil)
                {
                    if (Dfs(u))
                    {
                        matching++;
                    }
                }
            }
        }
        return matching;
    }

    public static int GetMaxMatch(int u, int v, List<int>[] link)
    {
        return new HopcroftKarp(u, v, link).Solve();
    }
}

class Solution
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        var reds = new Point[n + 1]; // 0????
        var blues = new Point[n + 1]; // 0????
        for (int i = 1; i <= n; i++)
        {
            var vals = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            reds[i] = new Point(vals[0], vals[1]);
        }
        for (int i = 1; i <= n; i++)
        {
            var vals = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            blues[i] = new Point(vals[0], vals[1]);
        }

        var link = new List<int>[n + 1];
        for (int i = 1; i <= n; i++)
        {
            link[i] = new List<int>();
            var red = reds[i];
            for (int j = 1; j <= n; j++)
            {
                var blue = blues[j];
                if (red.X < blue.X && red.Y < blue.Y)
                {
                    link[i].Add(j);
                }
            }
        }

        Console.WriteLine(HopcroftKarp.GetMaxMatch(n, n, link));
    }
}