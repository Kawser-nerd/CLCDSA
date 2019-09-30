using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1C_Consonants
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader inps = new StreamReader("data_in.txt");
            StreamWriter outps = new StreamWriter("data_out.txt");
            int T = int.Parse(inps.ReadLine());
            for (int t = 0; t < T; ++t)
            {
                string line = inps.ReadLine();
                string[] lineEl = line.Split(' ');
                int n = int.Parse(lineEl[1]);
                string word = lineEl[0];
                string res = Resolve(word, n);
                outps.WriteLine("Case #" + (t + 1) + ": " + res);
            }
            inps.Close();
            outps.Close();
        }

        public static bool isVovel(char ch)
        {
            return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u');

        }
        
        public static string Resolve(string word, int n)
        {
            long res = 0;
            bool[] wordB = new bool[word.Length];
            // wrodB[i] - is non-vovel at i
            int wordLen = word.Length;
            for (int i = 0; i < word.Length; ++i)
                wordB[i] = !isVovel(word[i]);
            // find islands
            List<int> islandPos = new List<int>();
            List<int> islandLen = new List<int>();
            findIslands(islandPos, islandLen, wordB, n);

            for (int nIsland = 0; nIsland < islandPos.Count(); ++nIsland)
            {
                // where to count
                //long prevIslandPos = 0;
                //if (nIsland > 0)
                //    prevIslandPos = islandPos[nIsland - 1] + islandLen[nIsland - 1];
                long nextIslandPos = wordB.Length;
                if (nIsland < islandPos.Count() - 1)
                {
                    nextIslandPos = islandPos[nIsland + 1] + n - 1;
                }
                long thisIslandPos = islandPos[nIsland];
                long thisIslandLen = islandLen[nIsland];
                long x = (thisIslandLen - n + 1) * (thisIslandLen - n + 2) / 2;
                long leftCombinations = (thisIslandPos + 1);
                long rightCombinations = ((nextIslandPos - (thisIslandPos + thisIslandLen)) + 1);
                long leftright = (leftCombinations - 1) * (rightCombinations - 1); //at least one element each side
                long allLeft = (leftCombinations - 1) * (thisIslandLen - n + 1); // minus only island
                long allRight = (rightCombinations - 1) * (thisIslandLen - n + 1); // munis only island
                long allOfThem = x + leftright + allLeft + allRight;
                res += allOfThem;
            }

            return res.ToString();
        }

        private static void findIslands(List<int> islandPos, List<int> islandLen, bool[] wordB, int n)
        {
            int count1 = 0;
            bool isInIsland = false;
            for (int i = 0; i < wordB.Length; ++i)
            {
                if (wordB[i])
                {
                    ++count1;
                    if (count1 == n)
                    {
                        isInIsland = true;
                        islandPos.Add(i - (count1 - 1));
                    }
                }
                else
                {
                    if (isInIsland)
                    {
                        islandLen.Add(count1);
                        isInIsland = false;
                    }
                    count1 = 0;
                }
            }
            if (isInIsland)
                islandLen.Add(count1);
        }
    }
}
