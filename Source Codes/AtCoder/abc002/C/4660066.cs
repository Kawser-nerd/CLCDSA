using System;
using System.Linq;

namespace BeginnerContest_002_C
{
    class Program
    {
        static void Main(string[] args)
        {
            double[] input = Console.ReadLine().Split(' ').Select(double.Parse).ToArray();
            var p = new
            {
                x_a = 0,
                y_a = 0,
                x_b = input[2] - input[0],
                y_b = input[3] - input[1],
                x_c = input[4] - input[0],
                y_c = input[5] - input[1]
            };

            double s = Math.Abs(p.x_b * p.y_c - p.x_c * p.y_b)*0.5;
            Console.WriteLine(Math.Round(s, 1, MidpointRounding.AwayFromZero));
        }
    }
}