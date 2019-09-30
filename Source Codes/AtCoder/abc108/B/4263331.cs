using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B.Ruined_Square
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(null).Select(x => int.Parse(x)).ToArray();
            var length = 0;

            var point = new List<Point>
            {
                new Point { X = input[0], Y = input[1] },
                new Point { X = input[2], Y = input[3] },
            };

            point.Add(new Point
            {
                X = point[1].X - (point[1].Y - point[0].Y),
                Y = point[1].Y + (point[1].X - point[0].X)
            });

            point.Add(new Point
            {
                X = point[2].X - (point[1].X - point[0].X),
                Y = point[2].Y - (point[1].Y - point[0].Y)
            });

            Console.Write(point[2].X + " " + point[2].Y + " " + point[3].X + " " + point[3].Y);
        }

        public class Point
        {
            public int X { get; set; }
            public int Y { get; set; }
        }
    }
}