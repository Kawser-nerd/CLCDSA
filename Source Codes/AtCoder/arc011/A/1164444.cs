using System;
using System.Linq;

namespace arc011_1
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int ret = x[2];
            while (x[2] / x[0] > 0)
            {
                ret += x[2] / x[0] * x[1];
                x[2] = x[2] / x[0] * x[1] + x[2] % x[0];
            }
            Console.WriteLine(ret);
        }
    }
}