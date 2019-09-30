using System;
using System.Linq;

namespace agc017_b
{
    class Program
    {
        static void Main(string[] args)
        {
            long[] x = Console.ReadLine().Split().Select(long.Parse).ToArray();
            x[0]--;
            long sa = x[2] - x[1];
            bool ret = false;
            for (int i = 0; i <= x[0]; i++)//??????????
            {
                long now = x[3] * (x[0] - i * 2);
                if (now - (x[4] - x[3]) * i <= sa &&
                    sa <= now + (x[4] - x[3]) * (x[0] - i)) ret = true;
            }
            Console.WriteLine(ret ? "YES" : "NO");
        }
    }
}