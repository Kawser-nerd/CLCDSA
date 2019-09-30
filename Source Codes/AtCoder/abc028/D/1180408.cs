using System;

namespace abc028_d
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] x = Console.ReadLine().Split();
            double n = int.Parse(x[0]);
            double k = int.Parse(x[1]);
            Console.WriteLine(((n - k) * (k - 1) * 6 + (n - 1) * 3 + 1) / (n * n * n));
        }
    }
}