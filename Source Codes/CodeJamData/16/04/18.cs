#define LARGE_INPUT
using System;
using System.Numerics;

namespace Fractiles
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
                int patternLength = int.Parse(values[0]);
                int complexity = int.Parse(values[1]);
                int studentCount = int.Parse(values[2]);

                SolveTheProblem(sp + 1, patternLength, complexity, studentCount);
            }
        }

        static void SolveTheProblem(int sp, int patternLength, int complexity, int numberOfStudent)
        {
            string[] outValues;

#if !LARGE_INPUT
            BigInteger powerStep = 1;
            for (int i = 1; i < complexity; i++)
            {
                powerStep *= patternLength;
            }

            if (studentCount < patternLength)
            {
                outValues = null; // Impossible!!!
            }
            else
            {
                outValues = new string[patternLength];
                for (int i = 0; i < patternLength; i++)
                {
                    outValues[i] = (powerStep * i + 1).ToString();
                }
            }
#else
            int numberOfGroup = patternLength / complexity;
            if (patternLength % complexity > 0)
            {
                numberOfGroup++;
            }

            if (numberOfStudent < numberOfGroup)
            {
                outValues = null; // Impossible!!!
            }
            else
            {
                outValues = new string[numberOfGroup];
                int count = 0;
                // Loop through
                for (int i = 0; i < numberOfGroup; i++)
                {
                    BigInteger position = 0;
                    // Loop through each member in group
                    for (int j = 0; j < complexity; j++)
                    {
                        position = position * patternLength + count;
                        
                        if (count < patternLength - 1)
                        {
                            count++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    outValues[i] = (position + 1).ToString();
                }
            }
#endif

            // Print results
            Console.Write("Case #{0}:", sp);
            if (outValues != null)
            {
                for (int i = 0; i < outValues.Length; i++)
                {
                    Console.Write(" {0}", outValues[i]);
                }
                Console.WriteLine();
            }
            else
            {
                Console.WriteLine(" IMPOSSIBLE");
            }
        }
    }
}
