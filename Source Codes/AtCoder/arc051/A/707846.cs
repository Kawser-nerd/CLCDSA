using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//using System.Drawing;

namespace AtCoder
{
    class Point {
        public int X;
        public int Y;
        public Point(int x, int y) {
            X = x;
            Y = y;
        }
    }
    class ARC051
    {
        static void Main(string[] args) {
            string[] spl = Console.ReadLine().Split(' ');
            int x1 = int.Parse(spl[0]);
            int y1 = int.Parse(spl[1]);
            int r = int.Parse(spl[2]);
            spl = Console.ReadLine().Split(' ');
            int x2 = int.Parse(spl[0]);
            int y2 = int.Parse(spl[1]);
            int x3 = int.Parse(spl[2]);
            int y3 = int.Parse(spl[3]);

            Point[] corner = new Point[] {
                new Point(x2, y2),
                new Point(x3, y2),
                new Point(x2, y3),
                new Point(x3, y3),
            };
            string existsBlue = "NO";
            foreach(Point p in corner) {
                if((p.X - x1) * (p.X - x1) + (p.Y - y1) * (p.Y - y1) > r * r) {
                    existsBlue = "YES";
                }
            }

            string existsRed = "NO";
            foreach (Point p in corner) {
                if (x1 - r < x2 ||
                    x1 + r > x3 ||
                    y1 - r < y2 ||
                    y1 + r > y3) {
                    existsRed = "YES";
                }
            }
            
            Console.WriteLine(existsRed);
            Console.WriteLine(existsBlue);
        }
    }
}