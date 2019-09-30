using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016_2_B
{
    class Program
    {
        static int bitCount(long x)
        {
            var res = 0;
            while (x > 0)
            {
                if ((x % 2) != 0) res++;
                x >>= 1;
            }
            return res;
        }

        static BigInteger tieP(long mask, int index, int remK, int target, BigInteger[] pp)
        {
            if (remK == 0) return 1;
            if ((mask % 2) == 0) return tieP(mask >> 1, index + 1, remK, target, pp);
            if (target == remK) return tieP(mask >> 1, index + 1, remK - 1, target - 1, pp) * pp[index];
            if (target == 0) return tieP(mask >> 1, index + 1, remK - 1, target, pp) * (100 - pp[index]);
            var res1 = tieP(mask >> 1, index + 1, remK - 1, target - 1, pp) * pp[index];
            var res2 = tieP(mask >> 1, index + 1, remK - 1, target, pp) * (100 - pp[index]);
            return res1 + res2;
        }

        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var line = Console.ReadLine().Split().Select(int.Parse).ToArray();
                var N = line[0];
                var K = line[1];
                var pN = 1L;
                for (int i = 0; i < N; i++)
                {
                    pN <<= 1;
                }
                var max = BigInteger.Zero;
                var lineP = Console.ReadLine().Split().Select(x => x == "1.00" ? BigInteger.One * 100 : new BigInteger(int.Parse(x.Substring(2)))).ToArray();
                for (long i = 0; i < pN; i++)
                    if (bitCount(i) == K)
                    {
                        var p = tieP(i, 0, K, K / 2, lineP);
                        if (p > max)
                            max = p;
                    }
                for (int i = 0; i < K - 4; i++)
                {
                    max /= 100;
                }
                var res = (double)max;
                for (int i = 0; i < 4 && i < K; i++)
                {
                    res /= 100.0;
                }
                Console.WriteLine("Case #{0}: {1}", testN, res);
            }
        }
    }
}
