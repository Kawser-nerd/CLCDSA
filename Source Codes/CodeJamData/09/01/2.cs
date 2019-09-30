using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;

namespace CodeJam
{
    class AlienLanguage
    {
        static void Main(string[] args)
        {
            var split = Console.In.ReadLine().Split(' ');
            int l = int.Parse(split[0]);
            int d = int.Parse(split[1]);
            int n = int.Parse(split[2]);

            string [] words = readLines(d);
            string [] patterns = readLines(n);

            int cc = 1;
            foreach (string pattern in patterns)
                Console.WriteLine("Case #{0}: {1}", cc++, calculatePossibilities(words, new Pattern(pattern, l)));
        }

        private static int calculatePossibilities(string[] words, Pattern pattern)
        {
            return words.Count(w => pattern.Matches(w));
        }

        private static string[] readLines(int d)
        {
            var result = new List<string>();
            for (int i = 0; i < d; i++)
                result.Add(Console.ReadLine());
            return result.ToArray();
        }
    }

    class Pattern
    {
        public readonly char[][] variants;
        public Pattern(string pattern, int length)
        {
            variants = new char[length][];
            for (int i = 0; i < length; i++)
                variants[i] = getNextChar(ref pattern);
            Debug.Assert(String.IsNullOrEmpty(pattern));
        }

        private static char[] getNextChar(ref string pattern)
        {
            if(pattern[0] != '(')
            {
                var ch = pattern[0];
                pattern = pattern.Substring(1);
                return new char[]{ ch };
            }

            var vars = pattern.Substring(1, pattern.IndexOf(')')-1);
            var result = vars.ToCharArray();

            pattern = pattern.Substring(vars.Length + 2);

            return result;
        }

        internal bool Matches(string w)
        {
            Debug.Assert(w.Length == variants.Length);
            for (int i = 0; i < variants.Length; i++)
                if (!variants[i].Contains(w[i]))
                    return false;
            return true;
        }
    }
}
