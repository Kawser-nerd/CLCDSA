using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Collections;
using System.Text.RegularExpressions;

namespace Alien_Language
{
    class Program
    {
        static StreamReader reader;
        static StreamWriter writer;

        static void Main(string[] args)
        {
            Console.WriteLine("Enter file name: ");
            String fileName = Console.ReadLine();
            reader = new StreamReader(fileName);
            writer = new StreamWriter(fileName.Replace(".in", ".out"));
            String[] numbers = reader.ReadLine().Split(new char[] { ' ' });
            int letters = Convert.ToInt32(numbers[0]);
            int wordCount = Convert.ToInt32(numbers[1]);
            int cases = Convert.ToInt32(numbers[2]);
            String[] words = new String[wordCount];
            for (int k = 0; k < wordCount; k++)
                words[k] = reader.ReadLine();
            for (int i = 1; i <= cases; i++)
                ProcessCase(i, words);
            writer.Flush();
            writer.Close();
        }

        static void ProcessCase(int caseNumber, String[] words)
        {
            String pattern = reader.ReadLine();
            pattern = pattern.Replace('(', '[');
            pattern = pattern.Replace(')', ']');
            Regex regex = new Regex(pattern);
            int matches = 0;
            foreach (String word in words)
                if (regex.IsMatch(word))
                    matches++;
            writer.WriteLine("Case #{0}: {1}", caseNumber, matches);
        }
    }
}
