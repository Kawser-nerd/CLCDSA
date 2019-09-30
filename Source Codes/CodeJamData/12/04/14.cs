using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;


namespace ConsoleApplication4
{
    public struct Point
    {
        public double X;
        public double Y;

        public HashSet<Point> Children;

        public Point(double x, double y)
        {
            X = x;
            Y = y;
            Children = new HashSet<Point>();
        }

        public override string ToString()
        {
            return string.Format("{0},{1}", X, Y);
        }

        public override bool Equals(object obj)
        {
            return ((Point)obj).X == this.X && ((Point)obj).Y == this.Y;
        }
    }

    public class HallOfMirrors
    {
        public static void Main()
        {
            using (StreamWriter writer = new StreamWriter(@"d:\output.txt"))
            {
                using (StreamReader reader = new StreamReader(@"d:\input.txt"))
                {
                    int count = int.Parse(reader.ReadLine());
                    for (int i = 0; i < count; i++)
                    {
                        Process(i + 1, reader, writer);
                    }
                }
            }
        }

        private static void Process(int p, StreamReader reader, StreamWriter writer)
        {
            var row = reader.ReadLine();
            var numbers = row.Split(' ').Select(x => int.Parse(x)).ToArray();
            var H = numbers[0];
            var W = numbers[1];
            var D = numbers[2];

            var data = new char[H][];
            var myPosition = new Point(0, 0);
            for (int i = 0; i < H; i++)
            {
                row = reader.ReadLine();
                data[i] = row.ToCharArray();

                for (int j = 0; j < data[i].Length; j++)
                {
                    if (data[i][j] == 'X')
                    {
                        myPosition = new Point(j - 0.5, i - 0.5);
                    }
                }
            }

            var width = W - 2;
            var height = H - 2;
            var left = -myPosition.X;
            var right = width + left;
            var top = -myPosition.Y;
            var bottom = height + top;

            var hMirrors = new List<double>();
            var vMirrors = new List<double>();

            // Generate all posible mirrors by mirrors
            var topDup = top;
            while (Math.Abs(topDup) * 2 <= D)
            {
                hMirrors.Add(topDup);
                topDup -= height;
            }

            var bottomDup = bottom;
            while (bottomDup * 2 <= D)
            {
                hMirrors.Add(bottomDup);
                bottomDup += height;
            }

            var leftDup = left;
            while (Math.Abs(leftDup) * 2 <= D)
            {
                vMirrors.Add(leftDup);
                leftDup -= width;
            }

            var rightDup = right;
            while (rightDup * 2 <= D)
            {
                vMirrors.Add(rightDup);
                rightDup += width;
            }

            // now we have hMirrors * vMirrors
            var me = new Point(0, 0);
            var all = new HashSet<Point>();
            DupFromMirrorLines(vMirrors, hMirrors, me, D, all);

            var mirrorPoints = new List<Point>();
            foreach (var h in hMirrors)
            {
                foreach (var v in vMirrors)
                {
                    if (Math.Sqrt(v * v + h * h) * 2 <= D)
                    {
                        mirrorPoints.Add(new Point(v, h));
                    }
                }
            }

            HashSet<string> angles = new HashSet<string>();
            var see = new List<Point>();
            foreach (var point in all)
            {
                if (point.X == 0 && point.Y == 0)
                    continue;

                var angle = GetAngle(point);
                if (angles.Add(angle))
                {
                    see.Add(point);
                }
            }

            writer.WriteLine("Case #{0}: {1}", p, see.Count);
        }

        private static string GetAngle(Point point)
        {
            return Math.Atan2(point.Y, point.X).ToString();
        }

        private static void DupFromMirrorLines(List<double> vMirrors, List<double> hMirrors, Point me, double D, HashSet<Point> all)
        {
            Stack<Point> tasks = new Stack<Point>();
            tasks.Push(me);
            all.Add(me);

            while (tasks.Count > 0)
            {
                var point = tasks.Pop();
                // |
                foreach (var v in vMirrors)
                {
                    var dup = new Point(v + v - point.X, point.Y);
                    if (Distance(dup, me) <= D)
                    {
                        if (!all.Contains(dup))
                        {
                            all.Add(dup);
                            point.Children.Add(dup);
                            tasks.Push(dup);
                        }
                    }
                }

                // -
                foreach (var h in hMirrors)
                {
                    var dup = new Point(point.X, h + h - point.Y);
                    if (Distance(dup, me) <= D)
                    {
                        if (!all.Contains(dup))
                        {
                            all.Add(dup);
                            point.Children.Add(dup);
                            tasks.Push(dup);
                        }
                    }
                }

                // corners
                foreach (var h in hMirrors)
                {
                    foreach (var v in vMirrors)
                    {
                        var dup = new Point(v + v - point.X, h + h - point.Y);
                        if (Distance(dup, me) <= D)
                        {
                            if (!all.Contains(dup))
                            {
                                all.Add(dup);
                                point.Children.Add(dup);
                                tasks.Push(dup);
                            }
                        }
                    }
                }
            }
        }

        private static double Distance(Point dup, Point point)
        {
            return Math.Sqrt(Math.Pow(point.X - dup.X, 2) + Math.Pow(point.Y - dup.Y, 2));
        }
    }
}