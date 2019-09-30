using System;
using System.Globalization;

public class flyswatter
{
    public static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());

        for (int cs = 1; cs <= N; cs++)
        {
            // Read input
            string[] line = Console.ReadLine().Split();
            double f = double.Parse(line[0], CultureInfo.InvariantCulture);
            double R = double.Parse(line[1], CultureInfo.InvariantCulture);
            double t = double.Parse(line[2], CultureInfo.InvariantCulture);
            double r = double.Parse(line[3], CultureInfo.InvariantCulture);
            double g = double.Parse(line[4], CultureInfo.InvariantCulture);

            double TotalSize = Math.PI * R * R;
            double TotalEscape = 0;
            if (g > f + f)
            {
                double R2 = R - t;
                double SquareSize = (g - f - f) * (g - f - f);

                for (double x = r; x <= R; x += g + r + r)
                {
                    for (double y = r; y <= R; y += g + r + r)
                    {
                        double x1 = x + f;
                        double y1 = y + f;
                        if (Math.Sqrt(x1 * x1 + y1 * y1) > R2 - f)
                            continue;

                        double x2 = x + g - f;
                        double y2 = y + g - f;

                        if (Math.Sqrt(x2 * x2 + y2 * y2) > R2 - f)
                        {
                            TotalEscape += CircleSquareArea(R2 - f, x + f, y + f, x2, y2);
                        }
                        else
                        {
                            TotalEscape += SquareSize;
                        }
                    }
                }
                TotalEscape *= 4;
            }

            double P = (TotalSize - TotalEscape) / TotalSize;
            Console.WriteLine("Case #" + cs + ": " + P.ToString("0.000000", CultureInfo.InvariantCulture));
        }
    }

    // Overlap of circle and square
    public static double CircleSquareArea(double R, double x1, double y1, double x2, double y2)
    {
        double area = 0;
        double firstpointx = Math.Sqrt((R * R) - (y2 * y2));
        double firstpointy = y2;
        if (firstpointx < x1 || y2 > R)
        {

            firstpointx = x1;
            firstpointy = Math.Sqrt((R * R) - (x1 * x1));
        }
        else
        {
            area += TriangleArea(y2 - y1, firstpointx - x1);
        }
        double secondpointx = x2;
        double secondpointy = Math.Sqrt((R * R) - (x2 * x2));
        if (secondpointy < y1 || x2 > R)
        {
            secondpointx = Math.Sqrt((R * R) - (y1 * y1));
            secondpointy = y1;
        }
        else
        {
            area += TriangleArea(x2 - x1, secondpointy - y1);
        }
        double dx = firstpointx - secondpointx;
        double dy = firstpointy - secondpointy;
        double L = Math.Sqrt(dx * dx + dy * dy);
        area += CircleLineArea(R, L);
        double dx1 = firstpointx - x1;
        double dy1 = firstpointy - y1;
        double dx2 = secondpointx - x1;
        double dy2 = secondpointy - y1;
        area += TriangleArea(L, Math.Sqrt(dx1 * dx1 + dy1 * dy1), Math.Sqrt(dx2 * dx2 + dy2 * dy2));
        return area;
    }

    // Circle with radius R, line part length L on the side touching circle
    // Return value is area between the line and the circle side
    public static double CircleLineArea(double R, double L)
    {
        double H = Math.Sqrt((R * R) - (L * L / 4d));
        double deg = Math.Acos(H / R) * 2;
        double circ = Math.PI * R * R;
        double circpart = deg / (Math.PI * 2);
        return circ * circpart - TriangleArea(R, R, L);
    }

    // Area of triangle with sides A and B with a right angle between them
    public static double TriangleArea(double A, double B)
    {
        return A * B / 2d;
    }

    // Area of triangle with sides A, B and C
    public static double TriangleArea(double A, double B, double C)
    {
        double D = (A + B + C) / 2d;
        return Math.Sqrt(D * (D - A) * (D - B) * (D - C));
    }
}