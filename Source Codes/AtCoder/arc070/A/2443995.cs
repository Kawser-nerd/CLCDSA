using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC70_C
{
    class Program
    {
        static void Main(string[] args)
        {

            var x = long.Parse(Console.ReadLine());
            long n = 2;
            for (; x > n * (n - 1) / 2; n++);

            Console.WriteLine(n-1);
        }
    }
}