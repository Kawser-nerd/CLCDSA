using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
           Console.WriteLine(ABC057_C());
        }
        
        static int ABC057_C()
        {
            var N = double.Parse(Console.ReadLine());
            var min = int.MaxValue;
            for (var a = 1; a <= int.Parse(((int)Math.Sqrt(N)).ToString()); a++)
            {
                var b = N / a;
                var keta = Math.Max(a.ToString().Length, b.ToString().Length);
                min = Math.Min(min, keta);
            }
            return min;
        }
    }
}