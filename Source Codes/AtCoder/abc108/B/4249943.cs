using System;
using System.Linq;

namespace ABC108_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var i = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var x1 = i[0];
            var y1 = i[1];
            var x2 = i[2];
            var y2 = i[3];

            var xd = x2 - x1;
            var yd = y2 - y1;

            Console.WriteLine("{0} {1} {2} {3}", x2 - yd, y2 + xd, x1 - yd, y1 + xd);
        }
    }
}