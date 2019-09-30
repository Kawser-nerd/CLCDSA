using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace ARC062_C
{
    class Program
    {
        static long N;
        static long T, A, t, a;
        static void Main(string[] args)
        {
            N = scan[0];
            var q = scan;
            T = q[0]; A = q[1];

            for (long i = 1; i < N; i++)
            {
                q = scan;
                t = q[0]; a = q[1];

                if(t - T >= 0 && a -A >= 0)
                {
                    T = t; A = a; continue;
                }

                long tx = (T % t == 0 || T / t == 0) ? T / t : T / t + 1;
                long ax = (A % a == 0 || A / a == 0) ? A / a : A / a + 1;

                long max = Math.Max(tx, ax);

                T = t * max;
                A = a * max;

                //Console.WriteLine(T+" "+A);
            }

            WriteLine(T + A);
        }

        static long[] scan { get { return Array.ConvertAll(ReadLine().Split(), long.Parse); } }
    }
}