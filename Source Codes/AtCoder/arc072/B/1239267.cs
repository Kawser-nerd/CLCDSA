using System;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = Console.ReadLine().Split(' ');
            long x = long.Parse(lines[0]);
            long y = long.Parse(lines[1]);
            string[] ans = { "Alice", "Brown" };

            Console.WriteLine(ans[Math.Abs(x - y) <= 1 ? 1 : 0]);
        }
    }
}