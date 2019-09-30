using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;
using System.Globalization;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();

            if (Math.Abs(a[1] - a[2]) <= a[0])
            {
                Console.WriteLine("0");
            }
            else
            {
                Console.WriteLine(Math.Abs(a[1] - a[2]) - a[0]);
            }
        }
    }
}