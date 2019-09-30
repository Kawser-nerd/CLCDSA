using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace _1._1
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader(args[0]))
            {
                using (StreamWriter writer = new StreamWriter(args[1]))
                {
                    {
                        int cases = int.Parse(reader.ReadLine());
                        for (int i = 0; i < cases; i++)
                        {
                            string test = reader.ReadLine();

                            var alphabet = new Dictionary<char, int>();
                            foreach (var letter in test)
                                alphabet[letter] = -1;

                            int alphabetSize = alphabet.Count;
                            if (alphabetSize == 1)
                                alphabetSize++;

                            alphabet[test[0]] = 1;
                            int nextValue = 0;
                            long result = 0;
                            foreach (var letter in test)
                            {
                                if (alphabet[letter] == -1)
                                {
                                    alphabet[letter] = nextValue;
                                    nextValue++;
                                    if (nextValue == 1)
                                        nextValue++;
                                }
                                result *= alphabetSize;
                                result += alphabet[letter];
                            }

                            if (alphabet.Count > 1 || test.Length > 1)
                                writer.WriteLine("Case #" + (i + 1) + ": " + result);
                            else
                                writer.WriteLine("Case #" + (i + 1) + ": 1");
                        }
                    }
                }
            }
        }
    }
}
