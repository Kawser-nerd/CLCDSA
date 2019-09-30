using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace A
{
    class Program
    {
        private static TextReader GetFileTextReader()
        {
            return File.OpenText(@"..\..\a.in");
        }

        private static TextWriter GetFileTextWriter()
        {
            return File.CreateText(@"..\..\a.out");
        }

        static void Main(string[] args)
        {
            using (TextReader reader = GetFileTextReader())
            {
                using (TextWriter writer = GetFileTextWriter())
                {
                    int t = int.Parse(reader.ReadLine());

                    for (int p = 0; p < t; p++)
                    {
                        string[] s = reader.ReadLine().Split(" ".ToArray(), StringSplitOptions.RemoveEmptyEntries);

                        string word = s[0];
                        int n = int.Parse(s[1]);

                        long result = 0;
                        int k = 0;
                        long lastResult = 0;

                        for (int i = 0; i < word.Length; i++)
                        {
                            if (!IsVowel(word[i]))
                            {
                                k++;
                                if (k >= n)
                                {
                                    lastResult = i - n + 2;
                                }
                            }
                            else
                            {
                                k = 0;
                            }

                            result += lastResult;
                        }


                            writer.WriteLine("Case #{0}: {1}", p + 1, result);
                    }
                }
            }
        }

        private static bool IsVowel(char ch)
        {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        }

        private static int CountConsecutiveConsonants(string word, int x, int y)
        {
            int result = 0;
            int k = 0;

            for (int i = x; i <= y; i++)
            {
                if (!IsVowel(word[i])) k++;
                else
                {
                    if (k > result) result = k;
                    k = 0;
                }
            }

            if (k > result) result = k;

            return result;
        }
    }
}
