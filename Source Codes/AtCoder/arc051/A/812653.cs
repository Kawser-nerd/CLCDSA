using System;
using System.Text.RegularExpressions;
using System.Linq;
using System.Collections.Generic;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine().Split();
            var x1 = Int32.Parse(str[0]);
            var y1 = Int32.Parse(str[1]);
            var r = Int32.Parse(str[2]);
            str = Console.ReadLine().Split();
            var x2 = Int32.Parse(str[0]);
            var y2 = Int32.Parse(str[1]);
            var x3 = Int32.Parse(str[2]);
            var y3 = Int32.Parse(str[3]);

            Console.WriteLine(x1 - r < x2 || x1 + r > x3 || y1 + r > y3 || y1 - r < y2 ? "YES" : "NO");
            Console.WriteLine(GetSqDist(x1, y1, x2, y2) > r * r || GetSqDist(x1, y1, x2, y3) > r * r || GetSqDist(x1, y1, x3, y2) > r * r || GetSqDist(x1, y1, x3, y3) > r * r ? "YES" : "NO");
        }

        static double GetSqDist(double x1, double y1, double x2, double y2)
        {
            return Math.Pow(x1 - x2, 2) + Math.Pow(y1 - y2, 2);
        }
    }
}