using System;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine();
            var strs = str.Split(' ');
            var n = int.Parse(strs[0]);
            var limitT = int.Parse(strs[1]);

            int minCost = int.MaxValue;
            for (int i = 0; i < n; i++)
            {
                str = Console.ReadLine();
                strs = str.Split(' ');

                var c = int.Parse(strs[0]);
                var t = int.Parse(strs[1]);

                if (t > limitT)
                {
                    continue;
                }

                if (c < minCost)
                {
                    minCost = c;
                }
            }

            Console.WriteLine(minCost == int.MaxValue ? "TLE" : minCost.ToString());
        }
    }
}