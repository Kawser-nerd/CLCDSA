using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamR1A2012
{
    class Program
    {
        static private void R1A_B()
        {
            int numTestCases = Int32.Parse(Console.ReadLine());
            for (int zz = 0; zz < numTestCases; zz++)
            {
                int n = Int32.Parse(Console.ReadLine());
                List<int> aList = new List<int>();
                List<int> bList = new List<int>();
                for (int i = 0; i < n; i++)
                {
                    string aAndBText = Console.ReadLine();
                    string[] splits = aAndBText.Split(' ');

                    aList.Add(Int32.Parse(splits[0]));
                    bList.Add(Int32.Parse(splits[1]));
                }

                int numLevelCompletions = 0;
                int numStars = 0;

                bool done = false;
                while (!done)
                {
                    bool foundB = false;

                    for (int bSearch = 0; bSearch < n; bSearch++)
                    {
                        if (numStars >= bList[bSearch])
                        {
                            numLevelCompletions++;
                            foundB = true;

                            if (numStars >= aList[bSearch])
                            {
                                numStars++;
                                aList[bSearch] = Int32.MaxValue;
                            }

                            numStars++;
                            bList[bSearch] = Int32.MaxValue;
                        }
                    }

                    if (foundB)
                    {
                        continue;
                    }

                    int bestA = -1;
                    int bestBVal = -1;
                    for (int aSearch = 0; aSearch < n; aSearch++)
                    {
                        // only do the best a (with the highest b)
                        // this logic might not be right
                        if (numStars >= aList[aSearch] && bestBVal < bList[aSearch])
                        {
                            bestA = aSearch;
                            bestBVal = bList[aSearch];
                        }
                    }

                    if (bestA != -1)
                    {
                        numLevelCompletions++;
                        aList[bestA] = Int32.MaxValue;
                        numStars++;
                    }
                    else
                    {
                        done = true;
                    }
                }

                string result = (numStars == 2 * n)
                    ? numLevelCompletions.ToString()
                    : "Too Bad";

                Console.WriteLine(String.Format("Case #{0}: {1}", zz + 1, result));
            }
        }

        static void Main(string[] args)
        {
            R1A_B();
        }
    }
}
