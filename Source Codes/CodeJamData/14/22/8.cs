using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace GoogleCodeJam.Fourteen.Round1B
{
    /// <summary>
    /// CodeJamProblem contains a collection of TestCases which are created by parsing the input file.
    /// The Solve method is called for each Test Case, then The output file is generated.
    /// </summary>
    public class Round1BB : CodeJamProblem<Round1BBTestCase>
    {
        protected override void ParseCase(Round1BBTestCase currentCase, int currentCaseNum, ref int currentLine, string[] lines)
        {
            var field = lines[currentLine].Split(_delimiterChars);
            currentCase.A = int.Parse(field[0]);
            currentCase.B = int.Parse(field[1]);
            currentCase.K = int.Parse(field[2]);
            currentLine++;
        }
        protected override StringBuilder OutputForEachCase(Round1BBTestCase testCase, StringBuilder currentString)
        {
            currentString.Append(testCase.NumWins);
            return currentString;
        }
    }

    public class Round1BBTestCase : ITestCase
    {
        public long A { get; set; }
        public long B { get; set; }
        public long K { get; set; }
        public long NumWins { get; set; }

        public Round1BBTestCase()
        {
        }

        static Round1BBTestCase()
        {
        }

        public void Solve()
        {
            if (A < 2 || B < 2)
            {
                for (int a = 0; a < A; a++)
                    for (int b = 0; b < B; b++)
                        if ((a & b) < K)
                            NumWins++;
                return;
            }

            if (K < A && K < B)
            {
                NumWins += K * A;
                NumWins += K * (B - K);

                for (int a = (int)K; a < A; a++)
                    for (int b = (int)K; b < B; b++)
                        if ((a & b) < K)
                            NumWins++;
                //long mult = 1;
                //long k = K;
                //while (k > 1)
                //{
                //    k >>= 1;
                //    mult <<= 1;
                //}

                //long AdditionalWins = 0;

                //for (int a = (int)K; a < A; a += (int)mult)
                //{
                //    for (int b = (int)K; b < B; b += (int)mult)
                //    {
                //        if ((a & b) < K)
                //            AdditionalWins++;
                //        if (b + (int)mult < B)
                //            for (; b < B; b++)
                //                if ((a & b) < K)
                //                    NumWins += mult;
                //    }
                //    if (a + (int)mult < A)
                //        for (; a < A; a++)
                //            for (int b = (int)K; b < B; b++)
                //                NumWins++;
                //}

                //NumWins += AdditionalWins * mult * mult;

            }
            else
            {
                NumWins += A * B;
            }


        }
    }
}
