using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TidyNumber
{
    class TidyNumber
    {
        static void Main(string[] args)
        {
            int numberOfSamples = int.Parse(Console.ReadLine());

            for (int sp = 0; sp < numberOfSamples; sp++)
            {
                // Read each sample         
                string s = Console.ReadLine();
                SolveTheProblem(sp + 1, s);
            }
        }

        static void FillWith9(char[] lastTidy, int pos)
        {
            for (int i = pos; i < lastTidy.Length; i++)
            {
                lastTidy[i] = '9';
            }
        }

        static void DecreaseAt(char[] lastTidy, int pos, ref int startIndex, ref int dirtyIndex)
        {
            if (lastTidy[pos] > '0')
            {
                lastTidy[pos]--;
            }
            else
            {
                while (pos >= startIndex && lastTidy[pos] == '0')
                {
                    lastTidy[pos] = '9';
                    pos--;
                }

                lastTidy[pos]--;
                dirtyIndex = pos + 1;
            }

            if (lastTidy[startIndex] == '0')
            {
                startIndex++;
            }
        }

        static string LastTidyNumber(string sLastNumber)
        {
            char[] lastTidy = sLastNumber.ToCharArray();
            int startIndex = 0;
            int dirttyIndex = sLastNumber.Length;
            for (int i = lastTidy.Length - 1; i > startIndex; i--) // not count 0
            {
                if (lastTidy[i] >= lastTidy[i - 1]) continue;
                if (i >= dirttyIndex) continue;

                dirttyIndex = i;
                DecreaseAt(lastTidy, i - 1, ref startIndex, ref dirttyIndex);
            }

            FillWith9(lastTidy, dirttyIndex);

            return new string(lastTidy, startIndex, sLastNumber.Length - startIndex);
        }

        static void SolveTheProblem(int sp, string sLastNumber)
        {
            string outValue;

            // Calculation
            outValue = LastTidyNumber(sLastNumber.ToString());

            // Print results
            Console.Write("Case #{0}: {1}", sp, outValue);
            Console.WriteLine();
        }
    }
}
