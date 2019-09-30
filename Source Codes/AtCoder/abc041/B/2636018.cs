using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestApp2
{
    class Program
    {
        static void Main(string[] args)
        {

            var str = Console.ReadLine()
                .Split(' ')
                .Select(x => decimal.Parse(x))
                .ToArray();
            var a = str[0];
            var b = str[1];
            var c = str[2];
            var xx = a * b * c;
            var yy = xx / 1000000007;
            var ii = Math.Floor(yy);
            var value = xx - ii * 1000000007;
            Console.WriteLine(value);
            Console.ReadLine();
        }
    }
}