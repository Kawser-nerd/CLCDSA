using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

namespace B
{
    class B
    {
        static long T, P;
        static long[] M = new long[2000];
        static long teams;
        static long[,] prices = new long[12, 1000];
        static long INFINITY = 4000000;

        static long[, ,] table;

        static void Main(string[] args)
        {
            //Console.SetIn(new StreamReader("B-small-attempt0.in"));
            T = long.Parse(Console.ReadLine());
            for (long i = 1; i <= T; i++)
            {
                P = long.Parse(Console.ReadLine());
                teams=(long)Math.Pow(2,P);
                string[] tmp = Console.ReadLine().Split();

                for (long j = 0; j < teams; j++) M[j] = long.Parse(tmp[j]);

                for (long j = 0; j < P; j++)
                {
                    tmp = Console.ReadLine().Split();
                    long ile = (long)Math.Pow(2, P-j-1);
                    for (long k = 0; k < ile; k++) prices[j, k] = long.Parse(tmp[k]);
                }

                table = new long[12, 2000, 12];
                for (long j = 0; j <= P; j++)
                    for (long k = 0; k < teams; k++)
                        for (long l = 0; l < P; l++)
                            table[j, k, l] = -1;
                for (long j = 0; j < teams / 2; j++)
                {
                    long min_move = P - M[j * 2];
                    if (P - M[j * 2 + 1] > min_move) min_move = P - M[j * 2 + 1];

                    for (int k = 0; k <= P; k++)
                    {
                        table[0, j, k] = (k < min_move - 1) ? INFINITY : ((k == min_move-1) ? prices[0, j] : 0);
                    }

                }

                Console.WriteLine("Case #" + i + ": " + getPrice(P-1,0,0));
            }
        }

        static long getPrice(long poziom, long numer, long przes)
        {
            if (table[poziom, numer, przes] != -1) return table[poziom, numer, przes];
            long min_price = getPrice(poziom - 1, numer * 2, przes) + getPrice(poziom - 1, numer * 2 + 1, przes);
            long match = prices[poziom, numer] + getPrice(poziom - 1, numer * 2, przes + 1) + getPrice(poziom - 1, numer * 2 + 1, przes + 1);
            table[poziom, numer, przes] = min_price < match ? min_price : match;
            return table[poziom, numer, przes];
        }

        
    }
}
