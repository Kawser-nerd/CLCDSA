using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CodeJam;
using System.Numerics;

namespace Proj
{
    class Program
    {

        static BigInteger Sqrt1(BigInteger n)
        {
            if (n == 0) return 0;
            if (n > 0)
            {
                int bitLength = Convert.ToInt32(Math.Ceiling(BigInteger.Log(n, 2)));
                BigInteger root = BigInteger.One << (bitLength / 2);

                while (!isSqrt(n, root))
                {
                    root += n / root;
                    root /= 2;
                }

                return root;
            }

            throw new ArithmeticException("NaN");
        }

        private static Boolean isSqrt(BigInteger n, BigInteger root)
        {
            BigInteger lowerBound = root * root;
            BigInteger upperBound = (root + 1) * (root + 1);

            return (n >= lowerBound && n < upperBound);
        }
        

        static void Main(string[] args)
        {
            using (var prob = new CodeJamProblem("D:\\CodeJam\\test.in"))
            {
                var TestCount = prob.ReadLineInt32();

                int Count = 0;
                for (var i = 0; i < TestCount; i++)
                {

                    
                    var Parts = prob.ReadParts();

                    BigInteger r;
                    BigInteger t;
                    BigInteger n = 0;

                    if (BigInteger.TryParse(Parts[0], out r) && BigInteger.TryParse(Parts[1], out t))
                    {
                        BigInteger S1 = 2 * r + 1;
                        BigInteger D = (S1 - 2);
                        D = D * D + 8 * t;

                        var vSqrt = Sqrt1(D);

                        n = (-(S1 - 2) + Sqrt1(D)) / 4;
                    }
                    else
                        Count = -10000000;

                    prob.OutputCase(n);
                }
            }

        }
    }
}
