using System;

namespace A.ABD
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());

            Console.WriteLine(N < 1000 ? "ABC" : "ABD");
        }
    }
}