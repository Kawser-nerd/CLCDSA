using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace aojpro
{
    class Program
    {

        static long[] a;
        static long[] p;
      
        static long Paty(long N, long X)
        {
            if(N == 0)
            {
                if(X <= 0)
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
            }
            else if(X > a[N - 1] + 1)
            {
                return Paty(N - 1, X - a[N - 1] - 2) + 1 + p[N - 1];
            }
            else
            {
                return Paty(N - 1, X - 1);
            }

        }


        static void Main(string[] args)
        {
            string[] str = Console.ReadLine().Split(' ');

            long n = long.Parse(str[0]);
            long x = long.Parse(str[1]);

            a = new long[n + 1];
            p = new long[n + 1];

            a[0] = 1;
            p[0] = 1;

            for(int i = 1; i <= n; i++)
            {
                a[i] = 2 * a[i - 1] + 3;
                p[i] = 2 * p[i - 1] + 1;
            }

            Console.WriteLine(Paty(n, x));

        }
    }
}