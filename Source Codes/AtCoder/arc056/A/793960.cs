using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace a
{
    class Program
    {
        static void Main(string[] args)
        {
            long[] abkl=Console.ReadLine().Split().Select(long.Parse).ToArray();
            long a = abkl[0];
            long b = abkl[1];
            long k = abkl[2];
            long l = abkl[3];
            long x = a * k;
            long y = (k / l) * b + (k % l) * a;
            long z = (k / l + 1) * b;
            Console.WriteLine(Math.Min(x, Math.Min(y, z)));
        }
    }
}