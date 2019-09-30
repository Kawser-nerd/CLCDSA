using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.IO;

namespace GCJ
{
    class P1
    {
        static void Main(string [] args)
        {
            if (args.Length == 0)
            {
                Process(Console.In, Console.Out);
            }
            else if (args.Length == 2)
            {
                using (var reader = new StreamReader(new FileStream(args[0], FileMode.Open)))
                {
                    using (var writer = new StreamWriter(new FileStream(args[1], FileMode.Create)))
                    {
                        Process(reader, writer);
                    }
                }
            }
        }

        static void Process(TextReader reader, TextWriter writer)
        {
            var fields = reader.ReadLine().Split(' ');

            var wordLength = int.Parse(fields[0]);
            var dictionarySize = int.Parse(fields[1]);
            var numPatterns = int.Parse(fields[2]);

            var dictionary = new string[dictionarySize];

            for (int i = 0; i < dictionarySize; i++)
            {
                dictionary[i] = reader.ReadLine();
            }

            for (int i = 0; i < numPatterns; i++)
            {
                var pattern = reader.ReadLine();

                writer.WriteLine("Case #{0}: {1}", i + 1, dictionary.Count(x => Match(x, pattern)));
            }
        }

        static bool Match(string text, string pattern)
        {
            for (int i = 0, j = 0; i < text.Length; i++)
            {
                if (pattern[j] == '(')
                {
                    bool found = false;

                    while (pattern[++j] != ')')
                    {
                        if (text[i] == pattern[j])
                            found = true;
                    }

                    if (found)
                        j++;
                    else
                        return false;
                }
                else if (text[i] != pattern[j++])
                    return false;
            }

            return true;
        }
    }
}
