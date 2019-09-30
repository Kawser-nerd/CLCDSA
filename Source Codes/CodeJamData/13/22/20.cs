using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace CodeJamTest
{
    class ProblemB : CodeJamTemplate
    {
        protected override void _run()
        {
            int T = readInt();

            for (int i = 0; i < T; i++)
            {
                write("Case #{0}: ", i + 1);

                int[] intArray = readIntTokens();
                int N = intArray[0];
                int X = intArray[1];
                int Y = intArray[2];

                X = Math.Abs(X);
                double prob = 0.0f;
                int R = (X + Y) / 2 + 1;
                if (N <= (2 * (R - 1) - 1) * (R - 1))
                    writeLine("0.0");
                else if (N >= (2 * R - 1) * R)
                    writeLine("1.0");
                else
                {
                    int P = X + Y;
                    int J = N - (2 * (R - 1) -1) * (R - 1);
                    if (Y + 1 > J || Y == P)
                        writeLine("0.0");
                    else if (J - P >= Y + 1)
                        writeLine("1.0");
                    else
                    {
                        int n = 0;
                        for (int j = 0; j <= J - (Y + 1); j++)
                            n += getCoefficient(J, j);

                        writeLine("{0:0.##############}", n * Math.Pow(0.5f, J));
                    }
                }
            }
        }

        int getCoefficient(int n, int k)
        {
            int i = Math.Min(n-k, k);
            int j = Math.Max(n-k, k);
            return (int) (factUntil(n, j) / factUntil(i, 0));
        }

        BigInteger factUntil(int a, int b)
        {
            BigInteger n = 1;
            for (int i = a; i > b; i--)
                n *= i;

            return n;
        }
    }
}