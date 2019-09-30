using System;
using System.Collections.Generic;
using System.Linq;

namespace Test
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            long ret = 0;
            ret += x[1];
            int[] a = new int[] { x[0],x[3],x[4] }; long aret = 0;
            aret += a[0] / 2 * 2; aret += a[1] / 2 * 2; aret += a[2] / 2 * 2;
            int[] b = new int[] { x[0] - 1,x[3] - 1,x[4] - 1 }; long bret = 0;
            bret += b[0] / 2 * 2; bret += b[1] / 2 * 2; bret += b[2] / 2 * 2;
            Console.WriteLine(ret + Math.Max(aret,b.Min() >= 0 ? bret + 3 : 0));
        }
    }
}