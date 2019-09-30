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
            double[] a = Console.ReadLine().Split(' ').Select(double.Parse).ToArray();
            long f = (long)Math.Floor(a[2] / a[3]);
            double ans = f * a[1] + (a[2] - f * a[3]) * a[0];
            if (ans > (f + 1) * a[1])
            {
                ans = (f + 1) * a[1];
            }
            Console.WriteLine(ans);
        }
    }
}