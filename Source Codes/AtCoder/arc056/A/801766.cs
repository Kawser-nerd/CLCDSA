using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            ulong a, b, k, l;
            var inStr = Console.ReadLine().Split();
            a = ulong.Parse(inStr[0]);
            b = ulong.Parse(inStr[1]);
            k = ulong.Parse(inStr[2]);
            l = ulong.Parse(inStr[3]);
            Console.WriteLine(Solve(a, b, k, l));
        }

        static ulong Solve(ulong a, ulong b, ulong k, ulong l)
        {
            return Math.Min(k * a, Math.Min((k / l) * b + (k % l) * a, ((k / l) + 1) * b));
        }
    }
}