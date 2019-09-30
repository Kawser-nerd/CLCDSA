using System;
using System.Linq;

namespace AtCoder.ABC122.A
{
    class Program
    {
        public static void Main()
        {
            var b = Console.ReadLine();
            Console.WriteLine(b == "A" ? "T" : b == "T" ? "A" : b == "C" ? "G" : "C");
        }
    }
}