using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace C
{
    class Program
    {
        private static List<string> dictionary = new List<string>();
        private static Dictionary<char, List<string>> d = new Dictionary<char, List<string>>();
        private static int result = 0;

        private static TextReader GetFileTextReader()
        {
            return File.OpenText(@"..\..\c.in");
        }

        private static TextWriter GetFileTextWriter()
        {
            return File.CreateText(@"..\..\c.out");
        }

        static void Main(string[] args)
        {
            using (TextReader reader = GetFileTextReader())
            {
                using (TextWriter writer = GetFileTextWriter())
                {
                    using (TextReader tr = File.OpenText(@"..\..\dictionary.txt"))
                    {
                        foreach (var word in tr.ReadToEnd().Split(new char[] { '\n', '\r' }, StringSplitOptions.RemoveEmptyEntries))
                        {
                            dictionary.Add(word);
                        }
                    }

                    int t = int.Parse(reader.ReadLine());

                    for (int i = 0; i < t; i++)
                    {
                        string s = reader.ReadLine();

                        int[,] a = new int[s.Length + 1, s.Length + 1];
                        for (int j = 0; j <= s.Length; j++)
                        {
                            for (int p = 0; p <= s.Length; p++)
                            {
                                a[j, p] = s.Length + 1;
                            }

                        }

                        a[0, s.Length] = 0;
                        List<string> ll = dictionary.ToList();

                        for (int j = 0; j < s.Length; j++)
                        {
                            ll = ll.Where(w => s.Length >= w.Length + j).ToList();
                            foreach (string word in ll)
                            {
                                bool cont = false;
                                int tt = -100;
                                for (int q = 0; q < word.Length; q++)
                                {
                                    if (word[q] != s[j + q])
                                    {
                                        if (j + q - tt < 5)
                                        {
                                            cont = true;
                                            break;
                                        }

                                        tt = j + q;
                                    }
                                }

                                if (cont) continue;

                                int p;
                                int last = -5;
                                if (IsValidWord(s, word, j, out p, ref last))
                                {
                                    int changed = last == -5 ? s.Length : last;

                                    if (a[j + word.Length, changed] > a[j, s.Length] + p)
                                    {
                                        a[j + word.Length, changed] = a[j, s.Length] + p;
                                    }
                                }

                                for (int c = 0; c < j; c++)
                                {
                                    last = c;
                                    if (IsValidWord(s, word, j, out p, ref last))
                                    {
                                        if (a[j + word.Length, last] > a[j, c] + p)
                                        {
                                            a[j + word.Length, last] = a[j, c] + p;
                                        }
                                    }
                                }
                            }
                        }

                        //result = int.MaxValue;

                        //Find(ref s, 0, 0, -100);

                        result = a[s.Length, s.Length];
                        for (int c = 0; c < s.Length; c++)
                        {
                            if (a[s.Length, c] < result)
                            {
                                result = a[s.Length, c];
                            }
                        }

                        writer.WriteLine("Case #{0}: {1}", i + 1, result);
                    }
                }
            }
        }

        private static bool IsValidWord(string s, string word, int start, out int p, ref int last)
        {
            bool ok = true;
            p = 0;

            for (int i = 0; i < word.Length; i++)
            {
                if (word[i] != s[start + i])
                {
                    if (start + i - last < 5)
                    {
                        ok = false;
                        break;
                    }

                    last = start + i;
                    p++;
                }
            }

            return ok;
        }

        private static void Find(ref string s, int start, int k, int lastChangedIndex)
        {
            if (k >= result)
            {
                return;
            }

            if (s.Length == start)
            {
                result = k;
                return;
            }
            
            foreach(string word in dictionary)
            {
                if (s.Length >= word.Length + start)
                {
                    bool ok = true;
                    int p = 0;
                    int last = lastChangedIndex;

                    for (int i = 0; i < word.Length; i++)
                    {
                        if (word[i] != s[start + i])
                        {
                            if (start + i - last < 5)
                            {
                                ok = false;
                                break;
                            }

                            last = start + i;
                            p++;
                        }
                    }

                    if (ok)
                    {
                        Find(ref s, start + word.Length, k + p, last);
                    }
                }
            }
        }
    }
}
