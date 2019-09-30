using System;
using System.Linq;

namespace arc091_b
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            long ret = 0;
            for (int i = x[1] + 1; i <= x[0]; i++)
            {
                int a = (x[0] - (i - 1)) / i + 1;
                ret += a * (i - x[1]);
                if ((x[0] - (i - 1)) / i != (x[0] - x[1]) / i)
                {
                    ret += (x[0] - x[1]) % i + 1;
                }
            }
            if (x[1] == 0) ret -= x[0];
            Console.WriteLine(ret);
        }
    }
}