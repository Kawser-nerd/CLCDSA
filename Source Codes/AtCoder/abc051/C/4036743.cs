using System;
using static System.Console;
using System.Linq;
using System.Collections.Generic;

static class Program
{
    static void Main()
    {

        int[] input = ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();

        Point startPoint = new Point(input[0], input[1]);
        Point goalPoint = new Point(input[2], input[3]);

        //????????????
        Write("U");
        Point.Move(startPoint.GetArroundPoint(Point.Direction.U), goalPoint.GetArroundPoint(Point.Direction.L));
        Write("R");

        //????????????
        Write("D");
        Point.Move(goalPoint.GetArroundPoint(Point.Direction.D), startPoint.GetArroundPoint(Point.Direction.R));
        Write("L");

        //????????????
        Write("L");
        Point.Move(startPoint.GetArroundPoint(Point.Direction.L), goalPoint.GetArroundPoint(Point.Direction.U));
        Write("D");

        //????????????
        Write("R");
        Point.Move(goalPoint.GetArroundPoint(Point.Direction.R), startPoint.GetArroundPoint(Point.Direction.D));
        Write("U");

        ReadKey();
    }

    struct Point
    {
        public Point(int x, int y) : this()
        {
            X = x;
            Y = y;
        }

        public int X { get; set; }
        public int Y { get; set; }

        public Point GetArroundPoint(Direction direction)
        {
            switch (direction)
            {
                case Direction.U:
                    return new Point(X, Y + 1);
                case Direction.D:
                    return new Point(X, Y - 1);
                case Direction.L:
                    return new Point(X - 1, Y);
                case Direction.R:
                    return new Point(X + 1, Y);
                default:
                    throw new Exception();
            }
        }

        public enum Direction
        {
            U,
            D,
            L,
            R
        }

        public static void Move(Point a, Point b)
        {
            if (a.Y > b.Y)
            {
                while (a.Y > b.Y)
                {
                    Write("D");
                    --a.Y;
                }
            }
            else if (a.Y < b.Y)
            {
                while (a.Y < b.Y)
                {
                    Write("U");
                    ++a.Y;
                }
            }

            if (a.X > b.X)
            {
                while (a.X > b.X)
                {
                    Write("L");
                    --a.X;
                }
            }
            else if (a.X < b.X)
            {
                while (a.X < b.X)
                {
                    Write("R");
                    ++a.X;
                }
            }
        }
    }
}