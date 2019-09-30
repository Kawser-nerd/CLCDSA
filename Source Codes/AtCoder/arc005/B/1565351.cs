using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using static System.Console;

namespace AtCoder
{
    class Program
    {
        const int HEIGHT = 9, WIDTH = 9;
        const int LEN = 4;
        static readonly Dictionary<string, Direction> Directions = new Dictionary<string, Direction>()
        {
            { "R", new Direction(1, 0) },
            { "L", new Direction(-1, 0) },
            { "U", new Direction(0, -1) },
            { "D", new Direction(0, 1) },
            { "RU", new Direction(1, -1) },
            { "RD", new Direction(1, 1) },
            { "LU", new Direction(-1, -1) },
            { "LD", new Direction(-1, 1) },
        };
        static readonly Dictionary<string, string> Contrasts = new Dictionary<string, string>()
        {
            { "R", "L" },
            { "L", "R" },
            { "U", "D" },
            { "D", "U" },
            { "RD-LR", "LD" },
            { "RD-TB", "RU" },
            { "RU-LR", "LU" },
            { "RU-TB", "RD" },
            { "LU-LR", "RU" },
            { "LU-TB", "LD" },
            { "LD-LR", "RU" },
            { "LD-TB", "LU" },
        };
        static void Main(string[] args)
        {
            Coordinate dir = new Coordinate(ReadLine());
            //Coordinate dir = new Coordinate("8 9 LU");
            //            string[] ll = new string[]
            //            {
            //"206932999",
            //"471100777",
            //"973172688",
            //"108989704",
            //"246954192",
            //"399039569",
            //"944715218",
            //"003664867",
            //"219006823",
            //            };
            char[] table = new char[HEIGHT * WIDTH];
            for (int y = 0; y < HEIGHT; y++)
            {
                //char[] chrs = ll[y].ToCharArray();
                char[] chrs = ReadLine().ToCharArray();
                for (int x = 0; x < WIDTH; x++)
                {
                    int index = ToIndex(x, y);
                    table[index] = chrs[x];
                }
            }
            Move(table, dir, 0);
            Write(Environment.NewLine);
            ReadLine();
        }
        static void Move(char[] table, Coordinate dir, int cnt)
        {
            int index = ToIndex(dir.X, dir.Y);
            Write(table[index]);
            if (++cnt < LEN)
            {
                int x = dir.X + Directions[dir.W].X;
                int y = dir.Y + Directions[dir.W].Y;
                if (IsOutOfTable(x, y))
                {
                    string lr = "";
                    string tb = "";
                    if (dir.W.Contains("L"))
                        lr = (dir.X == 0) ? "R" : "L";
                    if (dir.W.Contains("R"))
                        lr = (dir.X == (WIDTH - 1)) ? "L" : "R";
                    if (dir.W.Contains("U"))
                        tb = (dir.Y == 0) ? "D" : "U";
                    if (dir.W.Contains("D"))
                        tb = (dir.Y == (HEIGHT - 1)) ? "U" : "D";

                    dir.W = lr + tb;

                    x = dir.X + Directions[dir.W].X;
                    y = dir.Y + Directions[dir.W].Y;
                }
                dir.X = x;
                dir.Y = y;
                Move(table, dir, cnt);
            }
        }

        static int ToIndex(int x, int y) => x + (y * WIDTH);
        static int ToCoordinateX(int index) => index % WIDTH;
        static int ToCoordinateY(int index) => index / WIDTH;
        static bool IsOutOfTable(int x, int y) =>
            x < 0 ||
            y < 0 ||
            x >= WIDTH ||
            y >= HEIGHT;
    }
    class Coordinate
    {
        public int X { get; set; }
        public int Y { get; set; }
        public string W { get; set; }
        public Coordinate(string line)
        {
            string[] ar = line.Split(' ');
            X = int.Parse(ar[0]) - 1;
            Y = int.Parse(ar[1]) - 1;
            W = ar[2];
        }
        public Coordinate() { }
    }
    class Direction
    {
        public int X { get; set; }
        public int Y { get; set; }
        public Direction(int x, int y)
        {
            X = x;
            Y = y;
        }
    }
}