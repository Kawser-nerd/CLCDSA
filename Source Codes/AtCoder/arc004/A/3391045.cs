using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());

            double[] x = new double[N];
            double[] y = new double[N];

            List<double> distance = new List<double> { };

            for (int i = 0; i < N; i++)
            {
                var input = Console.ReadLine().Split(' ').Select(k => int.Parse(k)).ToArray();
                x[i] = input[0];
                y[i] = input[1];

            }

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    distance.Add(Math.Sqrt((x[i]-x[j])*(x[i]-x[j])+ (y[i] - y[j]) *(y[i] - y[j])));
                }
            }

            Console.WriteLine(distance.Max());
        }
    }
}