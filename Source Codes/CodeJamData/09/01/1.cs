using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace gcj09q
{
    class Program
    {

        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"D:\Downloads\A-large.in");

            string[] ldn = lines[0].Split(' ');
            int l = int.Parse(ldn[0]);
            int d = int.Parse(ldn[1]);
            int n = int.Parse(ldn[2]);

            for (int cas = d+1; cas <= d+n; ++cas)
            {
                string pat = lines[cas];

                int idx = 0;

                string[] a = new string[d];
                Array.Copy(lines, 1, a, 0, d);
                List<string> toFilter = new List<string>(a);
                List<string> filteredOut = new List<string>();

                for (int pos = 0; pos < pat.Length; ++pos, ++idx)
                {
                    if (toFilter.Count == 0) break;
                    int mask = 0;
                    if (pat[pos] == '(')
                    {
                        while (true)
                        {
                            ++pos;
                            if (pat[pos] == ')') break;
                            mask |= 1 << (pat[pos] - 'a');
                        }
                    } else {
                        mask |= 1 << (pat[pos] - 'a');
                    }

                    foreach (string w in toFilter)
                    {
                        if ((mask & (1<<(w[idx]-'a'))) != 0)
                        {
                            filteredOut.Add(w);
                        }
                    }

                    List<string> tmp = filteredOut;
                    filteredOut = toFilter;
                    toFilter = tmp;

                    filteredOut.Clear();
                }

                Console.WriteLine("Case #{0}: {1}", cas-d, toFilter.Count);
            }
        }
    }
}
