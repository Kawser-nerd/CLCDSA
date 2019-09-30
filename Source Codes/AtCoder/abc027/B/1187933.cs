using System;
using System.Linq;

namespace abc027_b
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
            if (x.Sum() % n != 0)
            {
                Console.WriteLine(-1);
            }
            else
            {
                int now = x[0];
                int ret = 0;
                for (int i = 1; i < n; i++)
                {
                    if (x.Sum() / n * i != now)
                    {
                        ret++;
                    }
                    now += x[i];
                }
                Console.WriteLine(ret);
            }
        }
    }
}