using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ARC85_D
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine().Split(' ');
            int n = int.Parse(s[0]);
            long h = long.Parse(s[1]);
            long amax = 0;
            long bsum = 0;
            var b = new long[n];
            long count = n;
            for (int i = 0; i < n; i++)
            {
                var p = Console.ReadLine().Split(' ');
                amax = Math.Max(amax, long.Parse(p[0]));
                b[i] = long.Parse(p[1]);
                bsum += b[i];
            }
            Array.Sort(b);
            bsum = 0;
            count = 0;
            for (int i = 0; i < n; i++)
            {
                if (b[n - i - 1] > amax)
                {
                    bsum += b[n - i - 1];
                    count++;
                }
                else
                {
                    break;
                }
                if (bsum >= h)
                {
                    Console.WriteLine(i + 1);
                    return;
                }
            }

            Console.WriteLine((h - bsum) % amax == 0 ? (h - bsum) / amax + count : (h - bsum) / amax + count + 1);
        }
    }
}