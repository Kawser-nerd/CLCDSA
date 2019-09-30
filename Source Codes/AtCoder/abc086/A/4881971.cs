using System;
using System.Linq;

namespace A___Product
{
    class Program
    {
        static void Main(string[] args)
        {
            var a_b = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var a = a_b[0];
            var b = a_b[1];

            Console.WriteLine((a * b) % 2 == 1 ? "Odd" : "Even");
        }
    }
}