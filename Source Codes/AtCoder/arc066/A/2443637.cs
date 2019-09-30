using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC66_C
{
    class Program
    {
        static void Main(string[] args)
        {

            var n = int.Parse(Console.ReadLine());

            var a = Console.ReadLine().Split().Select(int.Parse).ToList();


            var count = a
                .GroupBy(i => i)
                .Select(g => new { n = g.Key, c = g.Count() });
            foreach (var item in count)
            {
                if ((item.n == 0 && item.c > 1) || item.c > 2)
                {
                    Console.WriteLine(0);
                    return;
                }
            }
            long ans = 1;

            for (int i = 0; i < n/2; i++)
            {
                ans = (ans * 2) % 1000000007;
            }

            Console.WriteLine(ans);
        }
    }
}