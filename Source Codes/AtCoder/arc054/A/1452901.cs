using System;
using System.Linq;

namespace arc054_a
{
    class Program
    {
        static void Main(string[] args)
        {
            double[] x = Console.ReadLine().Split().Select(double.Parse).ToArray();
            if (x[3] < x[4])
            {
                Console.WriteLine(x[2] > x[1] ? Math.Min((x[4] - x[3]) / (x[1] + x[2]), ((x[3] + x[0] - x[4]) / (x[2] - x[1]))) : (x[4] - x[3]) / (x[1] + x[2]));
            }
            else
            {
                Console.WriteLine(x[2] > x[1] ? Math.Min((x[3] - x[4]) / (x[2] - x[1]), ((x[4] + x[0] - x[3]) / (x[1] + x[2]))) : (x[4] + x[0] - x[3]) / (x[1] + x[2]));
            }
        }
    }
}