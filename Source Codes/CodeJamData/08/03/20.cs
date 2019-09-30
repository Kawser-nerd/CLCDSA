using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;



namespace Googlee {

    class Program {

        static double f, R, t, r, g;

        static double accuracy = 0.00000000000000000001;
        static int steps = 5000;

        class Point {

            public double x;
            public double y;

            public Point(double x, double y) {
                this.x = x;
                this.y = y;
            }
            public Point(Point x) {
                this.x = x.x;
                this.y = x.y;
            }

            public override string ToString() {               
                return "(" +x.ToString() + ", " + y.ToString() + ")";
            }
        }


        static double distanceFromCircle(Point a) {
            return R - t - Math.Sqrt(a.x * a.x + a.y * a.y);
        }

        static double distance(Point a, Point b) {
            double w = a.x - b.x;
            double h = a.y - b.y;
            return Math.Sqrt(w * w + h * h);
        }

        static Point binarySearch(Point a, Point b) {
            a = new Point(a);
            b = new Point(b);

            int br = 0;
            Point middle = a;
            while (distance(a, b) > accuracy) {
                middle = new Point((a.x + b.x) / 2, (a.y + b.y) / 2);
                double dist = distanceFromCircle(middle);
                if (dist <= f) b = middle;
                else a = middle;
                if (br++ == steps) break;
            }

            return middle;

        }



        static double count(double x) {
            double rad = R - t - f;
            return 0.5 * (x * Math.Sqrt(rad * rad - x * x) + rad * rad * Math.Atan(x / (Math.Sqrt(rad * rad - x * x))));
        }

        static double area(Point bottom_left) {
           
            if (g - 2 * f <= 0) return 0;
           
            Point center = new Point(bottom_left.x + f, bottom_left.y + f);
            if (distanceFromCircle(center) <= f) return 0;
           
           
            Point opposite_corner = new Point(bottom_left.x + g, bottom_left.y + g);          
            if (distanceFromCircle(opposite_corner) >= 0) return  (g - 2 * f) * (g - 2 * f);
             
           
        
            double up = bottom_left.y + g;
            double right = bottom_left.x + g;

            Point original = bottom_left;

            bottom_left = new Point(bottom_left.x + f, bottom_left.y + f);


            Point top_left = binarySearch(bottom_left, new Point(bottom_left.x, original.y + g-f));
            Point bottom_right = binarySearch(bottom_left, new Point(original.x + g-f, bottom_left.y));
            Point top_rightA = binarySearch(top_left, new Point(original.x + g-f, top_left.y));
            Point top_rightB = binarySearch(bottom_right, new Point(bottom_right.x, original.y + g-f));
            
            return top_left.y * distance(top_left, top_rightA) + count(top_rightB.x) - count(top_rightA.x) - distance(bottom_left, bottom_right) * bottom_left.y;
        }


        static void Main(string[] args) {

            int N = Int32.Parse(Console.ReadLine());

            for (int i = 1; i <= N; i++) {

                String line = Console.ReadLine();
                String[] data = line.Split(' ');

                f = Double.Parse(data[0].Replace('.', ','));
                R = Double.Parse(data[1].Replace('.', ','));
                t = Double.Parse(data[2].Replace('.', ','));
                r = Double.Parse(data[3].Replace('.', ','));
                g = Double.Parse(data[4].Replace('.', ','));


                double result = 0;
                for (double y = r; y < R - t; y += g + 2 * r) {
                    for (double x = r; x < R - t; x += g + 2 * r) {
                        result += area(new Point(x, y));
                    }
                }


                result = 1 - (result / ((Math.PI * R * R) / 4));

                Console.WriteLine("Case #"+i.ToString()+": " + String.Format("{0:0.000000}", result).Replace(',', '.'));

            }
        }
    }
}

