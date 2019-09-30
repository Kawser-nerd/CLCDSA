using System;

namespace Submit
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] num = Console.ReadLine().Split();
            double n = double.Parse(num[0]);
            double x = double.Parse(num[1]);
            Console.WriteLine(3 * (Math.Abs(n - MCD(n, x))));
        }
        static double MCD(double n, double x)
        {
            if (x == 0) return n;
            else return MCD(x, n % x);
        }
    }
}