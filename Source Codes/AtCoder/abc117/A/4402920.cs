using System;

namespace AtCoder
{
    class Program
    {
        public static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split(' ');
            double T = double.Parse(s[0]);
            double X = double.Parse(s[1]);
            Console.WriteLine("{0:0.0000}", T / X);
        }
    }
}