using System;
using System.Numerics;

namespace SheepCount
{
    class Program
    {
        static void Main(string[] args)
        {
            digits = new bool[10];
            int numberOfSamples = int.Parse(Console.ReadLine());
            for (int sp = 0; sp < numberOfSamples; sp++)
            {
                // Read each sample
                int startNumber = int.Parse(Console.ReadLine());

                SolveTheProblem(sp + 1, startNumber);
            }
        }

        static bool[] digits;
        static int digitCount;

        public static bool SeeAllDigits(BigInteger number)
        {
            string s = number.ToString();
            for (int i = 0; i < s.Length; i++)
            {
                int d = s[i] - '0';
                if (digits[d] == false)
                {
                    digits[d] = true;
                    digitCount++;
                }
            }

            return digitCount >= 10;
        }

        static void SolveTheProblem(int sp, int startNumber)
        {
            string outValue;

            if (startNumber == 0)
            {
                outValue = null;
            }
            else
            {
                // Clear old data
                for (int i = 0; i < digits.Length; i++)
                {
                    digits[i] = false;
                }
                digitCount = 0;

                // Start counting
                BigInteger number = startNumber;
                while (!SeeAllDigits(number))
                {
                    number += startNumber;
                }
                outValue = number.ToString();
            }

            // Print results
            Console.Write("Case #{0}:", sp);
            if (outValue != null)
            {
                Console.WriteLine(" {0}", outValue);
            }
            else
            {
                Console.WriteLine(" INSOMNIA");
            }
        }

    }
}
