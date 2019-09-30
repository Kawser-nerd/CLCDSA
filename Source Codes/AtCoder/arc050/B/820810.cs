using System;
using System.Text.RegularExpressions;
using System.Linq;
using System.Collections.Generic;
using System.IO;
using System.Numerics;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine().Split();
            var r = Int64.Parse(str[0]);
            var b = Int64.Parse(str[1]);
            str = Console.ReadLine().Split();
            var x = Int64.Parse(str[0]);
            var y = Int64.Parse(str[1]);

            Int64 left = 0;
            Int64 right = Math.Max(r, b);
            while (right - left > 1)
            {
                var m = (left + right) / 2;
                if(m <= r && m <= b && (r - m) / (x - 1) + (b - m) / (y - 1) >= m)
                    left = m;
                else
                    right = m;
            }
            Console.WriteLine(left);
        }
    }
}