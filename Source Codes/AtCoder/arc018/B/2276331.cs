using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace arc_018_B
{
    class Program
    {
        static void Main(string[] args)
        {
            long n = long.Parse(Console.ReadLine());
            long[,] a = new long[n, 2];
            for (long i = 0; i < n; i++)
            {
                long[] usdf = Console.ReadLine().Split().Select(long.Parse).ToArray();
                a[i, 0] = usdf[0];
                a[i, 1] = usdf[1];
            }
            long ans = 0;
            for (long i = 0; i < n-2; i++)
            {
                for (long j = i + 1; j < n - 1; j++)
                {
                    for (long k = j + 1; k < n; k++)
                    {
                        long x1 = a[j, 0] - a[i, 0];
                        long x2 = a[k, 0] - a[i, 0];
                        long y1 = a[j, 1] - a[i, 1];
                        long y2 = a[k, 1] - a[i, 1];
                        /*    long[] length = new long[3];
                            length[0] = Math.Sqrt(x1 * x1 + y1 * y1);
                            length[1] = Math.Sqrt(x2 * x2 + y2 * y2);
                            length[2] = Math.Sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
                            Array.Sort(length);
                            if (length[2] >= length[0] + length[1]) { break; }
                          */
                        long S = Math.Abs(x1 * y2 - x2 * y1);
                          
                        if (S != 0 && S % 2 == 0)
                        { ans++; }
                    }
                }
            }
            Console.WriteLine(ans);
            Console.ReadLine();
        }
    }
}