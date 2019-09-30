using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class A : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            int iCases = int.Parse(sLines);

            System.Threading.Tasks.Task<string>[] tasks = new System.Threading.Tasks.Task<string>[iCases];

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string s = Console.ReadLine();
                tasks[iCase - 1] = System.Threading.Tasks.Task.Run<string>
                    (
                        () => DoWork(s)
                    );
                //tasks[iCase - 1].Wait();
            }

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string ret = tasks[iCase - 1].Result;
                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);
            }
        }

        private string DoWork(string s)
        {
            int[] counts = new int[26];
            for (int i = 0; i < s.Length; i++)
            {
                counts[s[i] - 'A']++;
            }

            int[] digCounts = new int[10];
            digCounts[0] = RemoveWord("ZERO", 'Z', counts);
            digCounts[2] = RemoveWord("TWO", 'W', counts);
            digCounts[8] = RemoveWord("EIGHT", 'G', counts);
            digCounts[6] = RemoveWord("SIX", 'X', counts);
            digCounts[3] = RemoveWord("THREE", 'H', counts);
            digCounts[7] = RemoveWord("SEVEN", 'S', counts);
            digCounts[5] = RemoveWord("FIVE", 'V', counts);
            digCounts[4] = RemoveWord("FOUR", 'F', counts);
            digCounts[9] = RemoveWord("NINE", 'I', counts);
            digCounts[1] = RemoveWord("ONE", 'O', counts);

            StringBuilder ret = new StringBuilder();
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < digCounts[i]; j++)
                {
                    ret.Append(i.ToString());
                }
            }

            return ret.ToString();
        }

        private int RemoveWord(string word, char uniqueLetter, int[] counts)
        {
            int count = counts[uniqueLetter - 'A'];
            for (int i = 0; i < word.Length; i++)
            {
                counts[word[i] - 'A'] -= count;
            }
            return count;
        }
    }
}
