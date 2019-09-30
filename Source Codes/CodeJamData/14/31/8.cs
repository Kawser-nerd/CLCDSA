using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using JamHelpers;

namespace R1C_A
{
    class Program : ProgramBase
    {
        static void Main()
        {
            new Program().Run();
        }

        public override void RunCase()
        {
            var frac = ReadLine();
            var ints = frac.Split('/').ToBigInt();
            var gcd = BigInteger.GreatestCommonDivisor(ints[0], ints[1]);
            var nom = ints[0] / gcd;
            var denom = ints[1] / gcd;
            var log2 = (int)Math.Round(BigInteger.Log(denom, 2));
            if (BigInteger.Pow(2, log2) != denom)
                WriteAnswer("impossible");
            else
            {
                int i = 0;
                while (BigInteger.Pow(2, i) <= nom)
                    i++;
                var result = log2 - i + 1;
                WriteAnswer(result);
            }
        }
    }
}
