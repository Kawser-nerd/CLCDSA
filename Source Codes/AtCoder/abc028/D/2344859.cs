using System;
using System.Collections.Generic;
using System.Linq;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            var p = new Program();
            p.Solve();
        }

        void Solve()
        {
            var tmp = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
            long n = tmp[0];
            long k = tmp[1];

            long all = n * n * n;

            long num = 0;
            //(k, k, k)
            num += 1;
            //(x, k , k ) x!=k
            num += (n - 1) * 3;
            //(x, k, y) x<k , y>k
            num += (k - 1) * (n - k) * 6;
            //Console.WriteLine(num);
            //Console.WriteLine(all);

            var ans = (double)num / all;
            Console.WriteLine(ans);
        }
    }
}