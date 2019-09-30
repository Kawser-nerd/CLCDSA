using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class Googlerese
    {
        private static readonly Dictionary<char, char> table = new Dictionary<char, char>();
        private static readonly string[][] hints = new[] {
                new [] { "y qee", "a zoo" },
                new [] { "ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand" },
                new [] { "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities" },
                new [] { "de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up" },
                new [] { "z", "q" },
            };
        public Googlerese()
        {
            foreach (string[] hint in hints)
            {
                for (int i = 0; i < hint[0].Length; i++)
                {
                    table[hint[0][i]] = hint[1][i];
                }
            }
        }
        public string Solve(string str)
        {
            char[] res = new char[str.Length];
            for (int i = 0; i < str.Length; i++)
            {
                res[i] = table[str[i]];
            }
            return new string(res);
        }
    }
    static class Program
    {
        static T[] ReadArray<T>(this StreamReader sr, Converter<string, T> parse)
        {
            return Array.ConvertAll(sr.ReadLine().Split(' '), parse);
        }
        static void Main(string[] args)
        {
            Googlerese g = new Googlerese();
            string name = "../A-small-attempt0";

            StreamReader sr = new StreamReader(name + ".in");
            StreamWriter sw = new StreamWriter(name + ".out");
            int T = int.Parse(sr.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                sw.WriteLine("Case #{0}: {1}", i, g.Solve(sr.ReadLine()));
                Console.WriteLine("Case #{0}: Done", i);
            }
            sw.Close();
            sr.Close();
        }
    }
}
