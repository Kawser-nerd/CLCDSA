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
        const int mod = 1000000007;

        static void Main(string[] args)
        {
            Console.WriteLine(Console.ReadLine().Split().Select(s => s.ToUpper()).Distinct().Count() == 1 ? "Yes" : "No");
        }
    }
}