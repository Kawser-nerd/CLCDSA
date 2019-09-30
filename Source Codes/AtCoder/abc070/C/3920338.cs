using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_C
{
    class C070
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            long gcm=1;
            for (int i = 0; i < N; i++)
            {
                long T = long.Parse(Console.ReadLine());
                if (i == 0) gcm = T;
                else gcm = GetLeastCommonMultiple(gcm, T);
            }
            Console.WriteLine(gcm);
        }

        //?????(Euclid???:O(log n)
        public static long GetGreatestCommonFactor(long x, long y)
        {
            while (x > 0 && y > 0)
            {
                if (x > y)
                {
                    x %= y;
                }
                else
                {
                    y %= x;
                }
            }
            return Math.Max(x, y);
        }

        //?????
        public static long GetLeastCommonMultiple(long x, long y)
        {
            long gcf = GetGreatestCommonFactor(x, y);
            long zz = y / gcf;
            return x * zz;
        }


    }
}