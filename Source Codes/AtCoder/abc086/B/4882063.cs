using System;
using System.Linq;

namespace B___1_21
{
    class Program
    {
        static void Main(string[] args)
        {
            var a_b = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var a = a_b[0];
            var b = a_b[1];

            var ab = Math.Sqrt(int.Parse("" + a + b));

            Console.WriteLine(ab == Math.Floor(ab) ? "Yes" : "No");
        }
    }
}