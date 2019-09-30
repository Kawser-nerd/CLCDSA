using System;
using System.Collections.Generic;

namespace a
{
    class Program
    {
        private static readonly ISet<char> Vowels = new HashSet<char> { 'a', 'e', 'i', 'o', 'u'  };


        private static long Solve(string s, int n)
        {
            long[] r = new long[s.Length + 1];
            r[0] = 0;

            int firstCon = -1;

            for (int k = 1; k <= s.Length; k++)
            {
                if (firstCon == -1)
                {
                    if (!Vowels.Contains(s[k - 1])) firstCon = k - 1;
                }
                else if (Vowels.Contains(s[k - 1]))
                {
                    firstCon = -1;
                }

                if (firstCon >= 0 && k - firstCon >= n)
                {
                    r[k] = k - n + 1;
                }
                else
                {
                    r[k] = r[k - 1];
                }
            }

            long rr = 0;
            for (int i = 1; i <= s.Length; i++) rr += r[i];

            return rr;
        }


        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int caseNum = 1; caseNum <= T; caseNum++)
            {
                string[] line = Console.ReadLine().Trim().Split();
                string s = line[0];
                int n = int.Parse(line[1]);

                long res = Solve(s, n);
                Console.WriteLine("Case #{0}: {1}", caseNum, res);
            }
        }
    }
}
