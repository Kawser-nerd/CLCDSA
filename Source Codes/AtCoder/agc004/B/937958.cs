using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC004_B3
{
    class Program
    {
        static long N, x;
        static void Main(string[] args)
        {
            var t = scan;
            N = t[0]; x = t[1];
            var a = scan;
            var b = new long[N];

            
            for (long i = 0; i < N; i++)
            {
                b[i] = a[i];
            }

            long ans = a.Sum();

            for (long k = 1; k < N; k++)
            {
                long time = k * x;

                for (long i = 0; i < N; i++)
                {
                    long p = (i - k < 0) ? i - k + N : i - k;
                    b[i] = Math.Min(b[i], a[p]);
                    time += b[i];
                }
                ans = Math.Min(ans, time);
            }
            Console.WriteLine(ans);
        }

        static long[] scan { get { return Array.ConvertAll(Console.ReadLine().Split(), long.Parse); } }
    }
}