using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine().Split();
            var h = Int32.Parse(str[0]);
            var w = Int32.Parse(str[1]);

            Console.WriteLine(2 * h * w - w - h);
        }
    }

}