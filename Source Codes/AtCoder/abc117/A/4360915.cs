using System;

namespace Atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split();
            double T, X;
            T = double.Parse(s[0]);
            X = double.Parse(s[1]);
            double res = T / X;
            Console.WriteLine("{0:f4}", res);
        }
    }
}