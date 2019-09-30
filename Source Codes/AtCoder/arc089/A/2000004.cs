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

    public int Mdistance(Point that)
    {
        return Math.Abs(X - that.X) + Math.Abs(Y - that.Y);
    }
}

class Solution
{
    static void Main()
    {
        var n = int.Parse(Console.ReadLine());

        var curPoint = new Point(0, 0);
        var curTime = 0;
        for (int i = 0; i < n; i++)
        {
            var vals = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var nextTime = vals[0];
            var nextPoint = new Point(vals[1], vals[2]);

            var distance = curPoint.Mdistance(nextPoint);
            var t = nextTime - curTime;
            if (distance > t || distance % 2 != t % 2)
            {
                Console.WriteLine("No");
                return;
            }

            curTime = nextTime;
            curPoint = nextPoint;
        }

        Console.WriteLine("Yes");
    }
}