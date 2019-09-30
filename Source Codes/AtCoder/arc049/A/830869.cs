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
            var s = Console.ReadLine();
            var str = Console.ReadLine().Split();
            var a = Int32.Parse(str[0]);
            var b = Int32.Parse(str[1]);
            var c = Int32.Parse(str[2]);
            var d = Int32.Parse(str[3]);
            Console.WriteLine(s.Insert(a, "\"").Insert(b + 1, "\"").Insert(c + 2, "\"").Insert(d + 3, "\""));
        }
    }
}