using System;
using System.Collections.Generic;
using System.Linq;

namespace Test
{
    class Program
    {
        static void Main(string[] args)
        {
            long[] x = Console.ReadLine().Split().Select(long.Parse).ToArray();
            long ret = x[1];
            long[] a = new long[] { x[0],x[3],x[4] }; long aret = 0;
            aret += a[0] / 2 * 2; aret += a[1] / 2 * 2; aret += a[2] / 2 * 2;
            long[] b = new long[] { x[0] - 1,x[3] - 1,x[4] - 1 };
            if (b.Min() >= 0)
            {
                long bret = 0;
                bret += b[0] / 2 * 2; bret += b[1] / 2 * 2; bret += b[2] / 2 * 2;
                Console.WriteLine(ret + Math.Max(aret,(bret + 3)));
            }
            else
            {
                Console.WriteLine(ret + aret);
            }
        }
    }
}