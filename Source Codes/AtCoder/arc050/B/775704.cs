using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    class Program
    {
        static bool canMake(long R, long B, long a, long b, long k)
        {
            var x = (R - k) / (a - 1);
            var y = (B - k) / (b - 1);
            return (R - k >= 0) && (B - k >= 0) && (x + y) >= k;
        }
        static void Main(string[] args)
        {
            var buff = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
            var R = buff[0];
            var B = buff[1];
            buff = Console.ReadLine().Split(' ').Select(long.Parse).ToArray();
            var a = buff[0];
            var b = buff[1];

            var bottom = 0L;
            var top = R + B;
            for (int i = 0; i < 100; i++)
            {
                var mid = (bottom + top) / 2;
                if (canMake(R, B, a, b, mid))
                {
                    bottom = mid;
                }
                else
                {
                    top = mid;
                }
            }

            
            Console.WriteLine(bottom);
        }
    }
}