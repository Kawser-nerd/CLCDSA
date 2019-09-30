using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC
{
    class Program
    {
        static void Main(string[] args)
        {
            ABC113_B();
        }

        static void ABC113_B()
        {
            var N = int.Parse(Console.ReadLine());
            var TA = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var T = TA[0];
            var A = TA[1];
            var H = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            var min = double.MaxValue;
            var point = 1;
            for (var i = 0; i < N; i++)
            {
                if (min > Math.Abs(A - (T - (H[i] * 0.006))))
                {
                    min = Math.Abs(A - (T - (H[i] * 0.006)));
                    point = i+1;
                }
            }
            Console.WriteLine(point);
        }
    }
}