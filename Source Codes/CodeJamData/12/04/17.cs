using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class Hall
    {
        private class Point
        {
            public int x;
            public int y;
        }
        private readonly Point me;
        private readonly int h;
        private readonly int w;
        private readonly int dsq;
        private List<Point> list;
        public Hall(int H, int W, int D, StreamReader sr)
        {
            h = (H - 2) * 2;
            w = (W - 2) * 2;
            dsq = D * D * 4;
            for (int i = 0; i < H; i++)
            {
                int n = sr.ReadLine().IndexOf('X');
                if (n >= 0)
                {
                    me = new Point
                    {
                        x = n * 2 - 1,
                        y = i * 2 - 1,
                    };
                }
            }
        }
        private Point Where(int room_x, int room_y)
        {
            return new Point
            {
                x = (room_x % 2 == 0) ? w * room_x + me.x
                                      : w * room_x + w - me.x,
                y = (room_y % 2 == 0) ? h * room_y + me.y
                                      : h * room_y + h - me.y,
            };
        }
        private static int Dsq(Point a, Point b)
        {
            int x = a.x - b.x;
            int y = a.y - b.y;
            return x * x + y * y;
        }
        private bool IsOnLine1(Point p, Point p1, Point p2)
        {
            int x1 = Math.Min(p1.x, p2.x);
            int x2 = Math.Max(p1.x, p2.x);
            int y1 = Math.Min(p1.y, p2.y);
            int y2 = Math.Max(p1.y, p2.y);
            return (x1 <= p.x && p.x <= x2 && y1 <= p.y && p.y <= y2);
        }
        private bool IsOnLine2(Point p1, Point p2)
        {
            return (p1.x - me.x) * (p2.y - me.y) == (p1.y - me.y) * (p2.x - me.x);
        }
        private bool Visible(Point p)
        {
            foreach (Point x in list)
            {
                if (IsOnLine1(x, p, me) && IsOnLine2(x, p))
                {
                    return false;
                }
            }
            return Dsq(p, me) <= dsq;
        }
        private int Add(int n)
        {
            List<Point> list1 = new List<Point> {
                Where(-n, -n),
                Where(-n,  n),
                Where( n, -n),
                Where( n,  n),
            };
            for (int i = -n + 1; i <= n - 1; i++)
            {
                list1.Add(Where( i, -n));
                list1.Add(Where( i,  n));
                list1.Add(Where(-n,  i));
                list1.Add(Where( n,  i));
            }
            List<Point> list2 = list1.FindAll(Visible);
            list.AddRange(list2);
            return list2.Count;
        }
        public int Solve()
        {
            list = new List<Point>();
            int count = 0;
            int a = 0;
            for (int i = 1; (a = Add(i)) > 0; i++)
            {
                count += a;
            }
            return count;
        }
    }
    static class Program
    {
        static T[] ReadArray<T>(this StreamReader sr, Converter<string, T> parse)
        {
            return Array.ConvertAll(sr.ReadLine().Split(' '), parse);
        }
        static void Main(string[] args)
        {
            string name = "../D-small-attempt1";
            StreamReader sr = new StreamReader(name + ".in");
            StreamWriter sw = new StreamWriter(name + ".out");
            int T = int.Parse(sr.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                int[] n = sr.ReadArray(int.Parse);
                Hall hall = new Hall(n[0], n[1], n[2], sr);
                sw.WriteLine("Case #{0}: {1}", i, hall.Solve());
                Console.WriteLine("Case #{0}: Done", i);
            }
            sw.Close();
            sr.Close();
        }
    }
}
