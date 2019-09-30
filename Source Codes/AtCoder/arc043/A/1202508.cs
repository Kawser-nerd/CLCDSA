using System;
using System.Linq;

namespace arc043_a
{
    class Program
    {
        static void Main(string[] args)
        {
            double[] x = Console.ReadLine().Split().Select(double.Parse).ToArray();
            int[] point = new int[(int)x[0]];
            for (int i = 0; i < x[0]; i++)
            {
                point[i] = int.Parse(Console.ReadLine());
            }
            if (point.Min() == point.Max())
            {
                Console.WriteLine(-1);
            }
            else
            {
                Array.Sort(point);
                double p = x[2] / (point.Max() - point.Min());
                double q = x[1] - point.Average() * p;
                Console.WriteLine(p + " " + q);
            }
        }
    }
}