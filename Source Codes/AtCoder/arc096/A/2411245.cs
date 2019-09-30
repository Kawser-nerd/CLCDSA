using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp6
{
    class Program
    {
        static void Main(string[] args)
        {
            var elements = Console.ReadLine().Split(' ');
            var a = int.Parse(elements[0]);
            var b = int.Parse(elements[1]);
            var c = int.Parse(elements[2]);
            var X = int.Parse(elements[3]);
            var Y = int.Parse(elements[4]);

            var min = -1;
            foreach(var aN in Enumerable.Range(0, X + 1))
            {
                var cN = (X - aN) * 2;
                var bN = Y - cN / 2;

                var sum = aN * a + cN * c;
                if (bN > 0) sum += bN * b;
                if (min < 0 || sum < min) min = sum;
            }

            foreach (var bN in Enumerable.Range(0, Y + 1))
            {
                var cN = (Y - bN) * 2;
                var aN = X - cN / 2;

                var sum = bN * b + cN * c;
                if (aN > 0) sum += aN * a;
                if (min < 0 || sum < min) min = sum;
            }
            Console.WriteLine(min);
        }
    }
}