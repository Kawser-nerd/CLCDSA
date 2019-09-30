using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC119_B();
        }

        static void ABC119_B()
        {
            var N = int.Parse(Console.ReadLine());
            var sum = 0D;
            for (var n = 0; n < N; n++)
            {
                var xu = Console.ReadLine().Split(' ').ToArray();
                var x = xu[0];
                var u = xu[1];
                sum += u == "BTC" ? 380000.0 * double.Parse(x) : double.Parse(x);
            }
            Console.WriteLine(sum);
        }
    }
}