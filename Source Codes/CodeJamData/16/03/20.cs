#define LARGE_INPUT
using System;
using System.Collections.Generic;
using System.Text;

namespace CoinJam
{
    class Program
    {
        static void Main(string[] args)
        {
            int numberOfSamples = int.Parse(Console.ReadLine());
            for (int sp = 0; sp < numberOfSamples; sp++)
            {
                // Read each sample
                string[] values = Console.ReadLine().Split(' ');
                int coinLength = int.Parse(values[0]);
                int quantity = int.Parse(values[1]);

                SolveTheProblem(sp + 1, coinLength, quantity);
            }
        }

        static long ParseBigInt(string coin, int numBase)
        {
            long number = 0;
            for (int i = 0; i < coin.Length; i++)
            {
                number = number * numBase + (coin[i] - '0');
            }
            return number;
        }

        static bool CheckValid(string coin, out string outValues)
        {
            StringBuilder sb = new StringBuilder();
            long[] proofs = new long[9];
            
            for (int numBase =  2; numBase <= 10; numBase++)
            {
                long number = ParseBigInt(coin, numBase);

                // Check elementary
                proofs[numBase - 2] = 0;
                long lim = (long)Math.Sqrt(number);
                for (long i = 2; i <= lim; i++)
                {
                    if (number % i == 0)
                    {
                        proofs[numBase - 2] = i;
                        sb.Append(" ");
                        sb.Append(i);
                        break;
                    }
                }

                if (proofs[numBase - 2] == 0) // is prime!!!
                {
                    outValues = "";
                    return false;
                }
            }

            outValues = sb.ToString();
            return true;
        }

        static void SolveTheProblem(int sp, int coinLength, int quantity)
        {
            // Print results
            Console.WriteLine("Case #{0}:", sp);

            // TODO: solve it
#if LARGE_INPUT
            int halfLength = coinLength / 2;
            long seed = (1 << (halfLength - 1)) + 1;
#else
            long seed = (1 << (coinLength - 1)) + 1;
#endif

            for (int i = 0; i < quantity; i++)
            {
                string newCoin = Convert.ToString(seed, 2);
                string outValue;

                while (!CheckValid(newCoin, out outValue))
                { 
                    seed += 2;
                    newCoin = Convert.ToString(seed, 2);
                }               
#if LARGE_INPUT
                Console.WriteLine("{0}{0}{1}", newCoin, outValue);
#else
                Console.WriteLine("{0}{1}", newCoin, outValue);
#endif
                seed += 2;
            }
        }
    }
}
