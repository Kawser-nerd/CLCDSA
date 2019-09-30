using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Center_of_Mass
{
    using System.Globalization;
    using System.IO;
    using System.Threading;

    public class Program
    {
        private static Point[] points;
        private static Point[] velocities;

        public static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            var reader = new StreamReader("b.txt");
            var writer = new StreamWriter("b_out.txt");
            int t = int.Parse(reader.ReadLine());
            for (int cas = 1; cas <= t; ++cas)
            {
                int n = int.Parse(reader.ReadLine());
                points = new Point[n];
                velocities = new Point[n];
                var center = new Point();
                var velocity = new Point();
                for (int i = 0; i < n; ++i)
                {
                    string[] spoints = reader.ReadLine().Split(' ');
                    points[i] = new Point(double.Parse(spoints[0]), double.Parse(spoints[1]), double.Parse(spoints[2]));
                    velocities[i] = new Point(double.Parse(spoints[3]), double.Parse(spoints[4]), double.Parse(spoints[5]));
                    center += points[i];
                    velocity += velocities[i];
                }

                center /= n;
                velocity /= n;
                Point w = -center;
                double time, d;
                if (!velocity.Zero())
                {
                    time = Point.ScalarProduct(w, velocity) / Point.ScalarProduct(velocity, velocity);
                    d = (w - velocity * time).Length();
                    if (time < 0)
                    {
                        time = 0.0;
                        d = w.Length();
                    }
                }
                else
                {
                    time = 0.0;
                    d = w.Length();
                }
                

                writer.WriteLine("Case #{0}: {1:F8} {2:F8}", cas, d, time);
            }

            reader.Close();
            writer.Close();
        }
    }

    public class Point
    {
        public Point()
        {
            this.X = this.Y = this.Z = 0.0;
        }

        public Point(double x, double y, double z)
        {
            this.X = x;
            this.Y = y;
            this.Z = z;
        }

        public double X
        {
            get;
            set;
        }

        public double Y
        {
            get;
            set;
        }

        public double Z
        {
            get;
            set;
        }

        public static Point operator +(Point a, Point b)
        {
            return new Point(a.X + b.X, a.Y + b.Y, a.Z + b.Z);
        }

        public static Point operator -(Point a, Point b)
        {
            return a + -b;
        }

        public static Point operator -(Point a)
        {
            return new Point(-a.X, -a.Y, -a.Z);
        }

        public static Point operator /(Point a, double x)
        {
            return a * (1 / x);
        }

        public static Point operator *(Point a, double x)
        {
            return new Point(a.X * x, a.Y * x, a.Z * x);
        }

        public static double ScalarProduct(Point a, Point b)
        {
            return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
        }

        public double Length()
        {
            return Math.Sqrt(this.X * this.X + this.Y * this.Y + this.Z * this.Z);
        }

        public bool Zero()
        {
            const double eps = 1e-7;
            return Math.Abs(X) < eps && Math.Abs(Y) < eps && Math.Abs(Z) < eps;
        }
    }
}
