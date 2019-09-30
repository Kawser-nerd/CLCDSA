using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using GCJDevKit.Tools;
using System.Threading;

namespace GCJDevKit.Solvers
{
    public class B : AbstractSolver
    {
        const long M = 1000000007L;

        int[] wordcharacters;

        protected override object Solve(System.IO.StreamReader input)
        {
            wordcharacters = new int['z' - 'a' + 1];
            int n = NextInt();
            var words = NextWordsInLine();

            List<String> realWords = new List<string>();

            for (int i = 0; i < n; i++)
            {
                words[i] = shortWord(words[i]);

                if (words[i].Length == 1)
                {
                    wordcharacters[words[i][0] - 'a']++;
                }
                else
                {
                    realWords .Add(words[i]);
                    Console.WriteLine("input: " + words[i]);
                }
            }

            for (int i = 0; i < wordcharacters.Length; i++)
            {
                char c = (char)('a' + i);
                if (wordcharacters[i] > 0)
                {
                    realWords.Add("" +c );
                    Console.WriteLine("input: " + c);
                }
            }

            realWords.Sort((a, b) => a.Length - b.Length);
            words = updateWords(realWords.ToArray());

            char last = '0';
            HashSet<char> present = new HashSet<char>();

            
            long total = 1;
            foreach (int current in wordcharacters) {
            total = total * silnia(current) % M;
            }


            foreach (var word in words) {
                Console.WriteLine("result: " + word);
                foreach (var c in word)
                {
                    if (c != last)
                    {
                        if (present.Contains(c))
                        {
                            return 0;
                        }
                        present.Add(c);
                    }
                    last = c;
                }
            }
            return total * silnia(words.Length) % M;
        }

        long silnia(int n)
        {
            long p = 1;
            for (int i = 2; i <= n; i++)
            {
                p = p * i % M ;
            }
            return p;
        }

        private String shortWord(String word)
        {
            char last = '0';
            String s = "";
            foreach (var c in word)
            {
                if (c != last)
                {
                    s = s + c;
                }
                last = c;
            }
            return s;
        }

        private String[] updateWords(String[] words)
        {
            List<String> newWords = new List<string>();
            for (int i = 0; i < words.Length; i++)
            {
                for (int j = 0; j < words.Length; j++)
                {
                    if (i != j)
                    {
                        var wi = words[i];
                        var wj = words[j];
                        if (wi != null && wj != null)
                        {
                            if (wi[0] == wj[wj.Length - 1])
                            {
                                newWords.Add(wj + wi);
                                words[i] = words[j] = null;
                            }
                            else
                            {
                                //Console.WriteLine("Not merging " + wj + " with " + wi);
                            }
                        }
                    }
                }
            }
            if (newWords.Count > 0)
            {
                foreach (String s in words)
                {
                    if (s != null) newWords.Add(s);
                }
                return updateWords(newWords.ToArray());
            }
            else
            {
                return words;
            }
        }

    }
}
