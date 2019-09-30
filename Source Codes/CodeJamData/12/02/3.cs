using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamQR2012
{
    class Program
    {
        static private void QR_B()
        {
            int numTestCases = Int32.Parse(Console.ReadLine());
            for (int zz = 0; zz < numTestCases; zz++)
            {
                string testCaseText = Console.ReadLine();

                string[] splits = testCaseText.Split(' ');

                int numGooglers = Int32.Parse(splits[0]);
                int numSurprises = Int32.Parse(splits[1]);
                int p = Int32.Parse(splits[2]); // TODO - find max num of googlers whose best result is >= p

                /*
                 * numbers sorted high to low in each triplet
                 * not surprising			total
                 * n	n	n		3n
                 * n	n	n-1		3n-1
                 * n	n-1	n-1		3n-2
                 * 
                 * surprising
                 * n	n	n-2		3n-2
                 * n	n-1	n-2		3n-3
                 * n	n-2	n-2		3n-4
                 */
                int maxNumGreatherOrEqualToP = 0;
                int numImprovableWithASurprise = 0;

                for (int splitIndex = 3; splitIndex < 3 + numGooglers; ++splitIndex)
                {
                    int googlerScoreTotal = Int32.Parse(splits[splitIndex]);

                    int nonSurprisingBestScore = (googlerScoreTotal + 2) / 3;
                    if (nonSurprisingBestScore >= p)
                    {
                        maxNumGreatherOrEqualToP++;
                    }
                    else
                    {
                        int bestPossibleInASurprise = (googlerScoreTotal + 4) / 3;
                        if (googlerScoreTotal > 1 && bestPossibleInASurprise >= p)
                        {
                            numImprovableWithASurprise++;
                        }
                        else
                        {
                            // this score is hopeless!
                        }
                    }
                }

                maxNumGreatherOrEqualToP += Math.Min(numSurprises, numImprovableWithASurprise);

                Console.WriteLine(String.Format("Case #{0}: {1}", zz + 1, maxNumGreatherOrEqualToP));
            }
        }

        static void Main(string[] args)
        {
            QR_B();
        }
    }
}
