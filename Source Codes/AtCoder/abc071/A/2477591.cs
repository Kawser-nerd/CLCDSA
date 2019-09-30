using System;

namespace AtCoder
{
    class Program
    {
        static void Main()
        {
            var inp = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            double a = Math.Abs(inp[0] - inp[1]);
            double b = Math.Abs(inp[0] - inp[2]);
            Console.WriteLine(a < b ? "A" : "B");
        }
    }
}