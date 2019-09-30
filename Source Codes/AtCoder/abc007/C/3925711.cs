using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.Diagnostics;

class Point
{
    public static readonly Point[] Delta =
    {
        new Point( 1,  0),
        new Point(-1,  0),
        new Point( 0,  1),
        new Point( 0, -1),
    };
    public int X { get; set;}
    public int Y { get; set;}
    public Point(int x, int y)
    {
        X = x;
        Y = y;
    }
    public static Point operator+(Point p1, Point p2)
    {
        return new Point(p1.X + p2.X, p1.Y + p2.Y);
    }
}

class Program
{
    public Program()
    {
        string[] inputs = Console.ReadLine().Split();
        int r = int.Parse(inputs[0]);
        int c = int.Parse(inputs[1]);
        inputs = Console.ReadLine().Split();
        int sX = int.Parse(inputs[1]) - 1;
        int sY = int.Parse(inputs[0]) - 1;
        inputs = Console.ReadLine().Split();
        int gX = int.Parse(inputs[1]) - 1;
        int gY = int.Parse(inputs[0]) - 1;
        string[] map =
            Enumerable.Range(0, r)
            .Select(x => Console.ReadLine())
            .ToArray();
        int[][] distance = 
            Enumerable.Range(0, r)
            .Select(x => new int[c]
                .Select(y => int.MaxValue).ToArray())
            .ToArray();
        distance[sY][sX] = 0;
        for(var que = new Queue<Point>(new Point[]{new Point(sX, sY) }); que.Any(); )
        {
            Point p = que.Dequeue();
            foreach(Point next in Point.Delta.Select(x => p + x))
            {
                if(next.X < 0 || next.X >= c ||
                    next.Y < 0 || next.Y >= r ||
                    map[next.Y][next.X] != '.' ||
                    distance[next.Y][next.X] <= distance[p.Y][p.X] + 1)
                    continue;
                
                distance[next.Y][next.X] = distance[p.Y][p.X] + 1;
                if(next.Y == gY && next.X == gX)
                {
                    que.Clear();
                    break;
                }
                que.Enqueue(next);
            }
        }
        //Console.WriteLine(string.Join("\n", distance.Select(x => string.Join(",", x))));
        Console.WriteLine(distance[gY][gX]);
    }
    static void Main(string[] args)
    {
        var p = new Program();
    }
}