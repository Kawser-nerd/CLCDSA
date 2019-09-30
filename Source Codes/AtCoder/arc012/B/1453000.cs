using System;
using System.Linq;

namespace arc012_2
{
    class Program
    {
        static void Main(string[] args)
        {
            double[] x = Console.ReadLine().Split().Select(double.Parse).ToArray();
            for (int i = 0; i < x[0]; i++)
            {
                x[3] /= x[1];
                x[3] *= x[2];
            }
            Console.WriteLine(x[3] > 0.00000001 ? x[3] : 0);
        }
    }
}