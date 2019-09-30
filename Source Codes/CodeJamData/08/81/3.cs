using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            using(var reader = new StreamReader("Input.txt"))
            using(var output = new StreamWriter("output.txt"))
            {
                int N = int.Parse(reader.ReadLine());
                for (int i = 0; i < N; i++)
                {
                    var ss = reader.ReadLine().Split();
                    int x1 = int.Parse(ss[0]), y1 = int.Parse(ss[1]), x2 = int.Parse(ss[2]),
                        y2 = int.Parse(ss[3]), x3 = int.Parse(ss[4]),
                        y3 = int.Parse(ss[5]);
                    ss = reader.ReadLine().Split();
                    int X1 = int.Parse(ss[0]), Y1 = int.Parse(ss[1]), X2 = int.Parse(ss[2]),
                        Y2 = int.Parse(ss[3]), X3 = int.Parse(ss[4]),
                        Y3 = int.Parse(ss[5]);
                    var res = f(x1, y1, x2, y2, x3, y3, X1, Y1, X2, Y2, X3, Y3);
                    output.WriteLine("Case #{0}: {1}", i + 1, res);
                }
            }
        }

        static string f(int x1, int y1, int x2, int y2, int x3, int y3, int X1, int Y1, int X2, int Y2, int X3, int Y3)
        {
            double a11, a12, a21, a22;
            double x0, y0;
            double r1 = x1 - x2, r2 = x1 - x3, q1 = y1 - y2, q2 = y1 - y3, R1 = X1 - X2,
                   R2 = X1 - X3, Q1 = Y1 - Y2, Q2 = Y1 - Y3;
            double d = r1 * q2 - r2 * q1;
            double s11 = q2 / d, s12 = -q1 / d, s21 = -r2 / d, s22 = r1 / d;
            a11 = s11 * R1 + s12 * R2;
            a12 = s21 * R1 + s22 * R2;
            a21 = s11 * Q1 + s12 * Q2;
            a22 = s21 * Q1 + s22 * Q2;
            x0 = -(a11 * x1 + a12 * y1 - X1);
            y0 = -(a21 * x1 + a22 * y1 - Y1);
            double u1 = x1, v1 = y1;
            double u2 = x2, v2 = y2;
            double u3 = x3, v3 = y3;
            f(a11, a12, a21, a22, x0, y0, ref u1, ref v1);
            Debug.Assert(Math.Abs(u1 - X1) < 1E-5);
            Debug.Assert(Math.Abs(v1 - Y1) < 1E-5);
            f(a11, a12, a21, a22, x0, y0, ref u2, ref v2);
            Debug.Assert(Math.Abs(u2 - X2) < 1E-5);
            Debug.Assert(Math.Abs(v2 - Y2) < 1E-5);
            f(a11, a12, a21, a22, x0, y0, ref u3, ref v3);
            Debug.Assert(Math.Abs(u3 - X3) < 1E-5);
            Debug.Assert(Math.Abs(v3 - Y3) < 1E-5);
            double x = x1, y = y1, xp = x + 1E6, yp = y + 1E6;
            double b11 = a11 - 1, b12 = a12, b21 = a21, b22 = a22 - 1;
            d = b11 * b22 - b12 * b21;
            s11 = b22 / d;
            s12 = -b12 / d;
            s21 = - b21 / d;
            s22 = b11 / d;
            x = -s11 * x0 - s12 * y0;
            y = -s21 * x0 - s22 * y0;
            //double t, t1 = double.PositiveInfinity;
            //int c = 0;
            //while ((t = (x - xp) * (x - xp) + (y -yp) * (y - yp)) > 1E-15)
            //{
            //    ////if (++c > 20 && t > t1 - 1E-12) return "No Solution";
            //    //t1 = t;
            //    xp = x;
            //    yp = y;
            //    f(a11, a12, a21, a22, x0, y0, ref x, ref y);
            //}
            xp = x;
            yp = y;
            f(a11, a12, a21, a22, x0, y0, ref x, ref y);
            Debug.Assert(Math.Abs(x - xp) < 1E-5);
            Debug.Assert(Math.Abs(y - yp) < 1E-5);
            //d = R1 * Q2 - R2 * Q1;
            //s11 = -Q2 / d;
            //s21 = Q1 / d;
            //s12 = R2 / d;
            //s22 = -R1 / d;
            //double dx = x - X1, dy = y - Y1;
            //double c1 = s11 * dx + s12 * dy;
            //double c2 = s21 * dx + s22 * dy;
            //Debug.Assert(Math.Abs(c1 * R1 + c2 * R2 + dx) < 1E-5);
            //Debug.Assert(Math.Abs(c1 * Q1 + c2 * Q2 + dy) < 1E-5);
            //if (c1 < 0 || c2 < 0 || c1 > 1 || c2 > 1 || c1 + c2 > 1) return "No Solution";
            //Console.WriteLine(c1 + " " + c2);
            return x + " " + y;
        }

        static void f(
            double a11,
            double a12,
            double a21,
            double a22,
            double x0,
            double y0,
            ref double x,
            ref double y)
        {
            double t1 = x0 + a11 * x + a12 * y;
            double t2 = y0 + a21 * x + a22 * y;
            x = t1;
            y = t2;
        }
    }
}
