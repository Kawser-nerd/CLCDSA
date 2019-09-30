using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(ARC095_C());
        }

        static int ARC095_C()
        {
            var inputs = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var A = inputs[0];
            var B = inputs[1];
            var C = inputs[2];
            var X = inputs[3];
            var Y = inputs[4];

            var length = X > Y ? X : Y;
            var ans = int.MaxValue;
            for (var i = 100000; i >= 0; i -= 1)
            {
                var ab = i * 2;
                var a = Math.Max(0, X - i);
                var b = Math.Max(0, Y - i);
                var sum = (a * A) + (b * B) + (ab * C);
                ans = Math.Min(ans, sum);
            }
            return Math.Min(ans, (X * A) + (Y * B));
        }
    }
}