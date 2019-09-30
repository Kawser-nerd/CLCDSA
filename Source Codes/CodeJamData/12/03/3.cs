using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamQR2012
{
    class Program
    {
        private class CharRange
        {
            public CharRange(char min, char max)
            {
                Min = min;
                Max = max;
            }
            public readonly char Min;
            public readonly char Max;
        }

        static private void QR_C()
        {
            int numTestCases = Int32.Parse(Console.ReadLine());
            for (int zz = 0; zz < numTestCases; zz++)
            {
                string testCaseText = Console.ReadLine();

                string[] splits = testCaseText.Split(' ');

                int a = Int32.Parse(splits[0]);
                int b = Int32.Parse(splits[1]);

                int foundPairs = 0;

                // find num of recycled pairs with a <= n < m <= b
                for (int n = a; n < b; n++)
                {
                    HashSet<int> foundMs = new HashSet<int>();

                    string rearrangeMe = n.ToString();
                    for (int loopPoint = 1; loopPoint < rearrangeMe.Length; ++loopPoint)
                    {
                        string rearranged = rearrangeMe.Substring(loopPoint) + rearrangeMe.Substring(0, loopPoint);
                        int mTest = Int32.Parse(rearranged);

                        if (n < mTest && mTest <= b)
                        {
                            if (foundMs.Add(mTest))
                            {
                                foundPairs++;
                            }
                        }
                    }
                }
                
                Console.WriteLine(String.Format("Case #{0}: {1}", zz + 1, foundPairs));
            }
        }

        static void Main(string[] args)
        {
            QR_C();
        }
    }
}
