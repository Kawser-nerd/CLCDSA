using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ09QRQ1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(args[0]);
            List<string> output = new List<string>();
            int index = 0;
            string[] bits = lines[index].Split(' ');
            int len = int.Parse(bits[0]);
            int wCount = int.Parse(bits[1]);
            int cCount = int.Parse(bits[2]);
            index++;
            List<string> words = new List<string>();
            for (int j = 0; j < wCount; j++)
            {
                words.Add(lines[index]);
                index++;
            }
            for (int j = 0; j < cCount; j++)
            {
                output.Add(string.Format("Case #{0}: {1}", j + 1, Solve(len, words, lines[index])));
                index++;
            }
            File.WriteAllLines("output.txt", output.ToArray());
        }

        private static int Solve(int len, List<string> words, string test)
        {
            bool[,] check = new bool[26, len];
            int offset = 0;
            bool inOptions = false;
            foreach (char c in test)
            {
                if (c == '(')
                {
                    inOptions = true;
                    continue;
                }
                if (c == ')')
                {
                    inOptions = false;
                    offset++;
                    continue;
                }
                check[c - 'a', offset] = true;
                if (!inOptions)
                    offset++;
            }
            int count = 0;
            foreach (string word in words)
            {
                if (Match(word, check))
                    count++;
            }
            return count;
        }

        private static bool Match(string word, bool[,] check)
        {
            int offset = 0;
            foreach (char c in word)
            {
                if (!check[c - 'a', offset])
                    return false;
                offset++;
            }
            return true;
        }
    }
}
