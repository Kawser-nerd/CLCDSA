using System;
using System.Linq;

namespace A___September_9
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = Console.ReadLine();

            Console.WriteLine(N.Contains('9') ? "Yes" : "No");
        }
    }
}