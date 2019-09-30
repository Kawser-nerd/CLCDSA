using System;
using System.Collections.Generic;
using System.Diagnostics;
using static System.Console;

namespace AtCoder
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> words = new List<string>();
            int N = int.Parse(ReadLine());

            for (int i = 0; i < N; i++)
                words = Insert(ReadLine(), words);

            foreach (string word in words)
                WriteLine(word);
            ReadLine();
        }
        static List<string> Insert(string line, List<string> words)
        {
            int i = 0;
            for (; i < words.Count; i++)
                if (IsInsertable(words[i], line))
                    break;
            words.Insert(i, line);
            return words;
        }
        static bool IsInsertable(string word, string line)
        {
            int w = word.Length - 1;
            int l = line.Length - 1;
            for (; w >= 0 && l >= 0; w--, l--)
            {
                if (word[w] < line[l])
                    return false;
                if (word[w] > line[l])
                    return true;
            }
            return l < 0;
        }
    }
}