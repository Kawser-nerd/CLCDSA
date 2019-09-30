using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using GCJDevKit.Tools;
using System.Diagnostics;
using System.Threading;

namespace GCJDevKit.Solvers
{
    class A : AbstractSolver
    {
        class Point
        {
            public double X, Y;
            public Point(int x, int y)
            {

                this.X = x;
                this.Y = y;
            }
        }

        double[] LPole;
        double[] UPole;

        double[] LSumaPole;
        double[] USumaPole;

        int width;
        int L, U, G;

        Point[] LPS;
        Point[] UPS;

        double epsilon = 0.00000000001;

        double sumaUp(double x, Point[] ps, double [] sumaPole, int N)
        {
            int left = 0;
            int right = N - 1;

            while (left + 1 < right)
            {
                int middle = (left + right) / 2;
                if (ps[middle].X < x)
                {
                    left = middle;
                }
                else
                {
                    right = middle;
                }
            }
            var r = sumaPole[left] + ps[left].Y * (x - ps[left].X) + (x - ps[left].X) * (x - ps[left].X) * (ps[right].Y - ps[left].Y) / (ps[right].X - ps[left].X) / 2;
            return r;
        }



        double sumaPole(double x)
        {
            return sumaUp(x, UPS, USumaPole, U) - sumaUp(x, LPS, LSumaPole, L);
        }

        double findPointWith(double pole)
        {
            double left = epsilon;
            double right = width - epsilon;

            while (right - left > epsilon)
            {
                double mid = (right + left) / 2;
                double midv = sumaPole(mid) ;
                if (midv < pole)
                {
                    left = mid;
                }
                else
                {
                    right = mid;
                }
            }
            return left;
        }

        protected override object Solve(System.IO.StreamReader input)
        {
            width = NextInt();
            L = NextInt();
            U = NextInt();
            G = NextInt();

            LPS = new Point[L];


            for (int i = 0; i < L; i++)
            {
                LPS[i] = new Point(NextInt(), NextInt());
            }

            UPS = new Point[U];
            for (int i = 0; i < U; i++)
            {
                UPS[i] = new Point(NextInt(), NextInt());
            }

            LPole = new double[L + 1];
            UPole = new double[U + 1];

            LSumaPole = new double[L];
            USumaPole = new double[U];


            LPole[0] = 0;
            UPole[0] = 0;

            for (int i = 1; i < L; i++)
            {
                var right = LPS[i];
                var left = LPS[i - 1];
                LPole[i] = (left.Y + right.Y) * (right.X - left.X) / 2;
                LSumaPole[i] = LSumaPole[i - 1] + LPole[i];
            }

            for (int i = 1; i < U; i++)
            {
                var right = UPS[i];
                var left = UPS[i - 1];
                UPole[i] = (left.Y + right.Y) * (right.X - left.X) / 2;
                USumaPole[i] = USumaPole[i - 1] + UPole[i];
            }

            double totalPole = sumaPole(width);

            StringBuilder sb = new StringBuilder();


                for (int i = 1; i < G; i++)
                {
                    sb.AppendLine();
                    sb.Append(findPointWith(totalPole * i / G));
                }

            return sb;
        }
    }
}
