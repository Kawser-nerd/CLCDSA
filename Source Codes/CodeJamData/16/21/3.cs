using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Getting_the_Digits
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            //const string filename = @"..\..\A-small-attempt0.in";
            const string filename = @"..\..\A-large.in";

            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (var reader = new StreamReader(filename))
            {
                using (var writer = new StreamWriter(filename.Replace(".in", ".out"), false))
                {
                    int n = int.Parse(reader.ReadLine());
                    for (int i = 1; i <= n; i++)
                    {
                        Console.Write("N=" + i + " Time=");
                        Process(i, reader, writer);
                        Console.WriteLine((DateTime.Now - current).ToString().Substring(4));
                        current = DateTime.Now;
                    }
                }
            }

            Console.WriteLine("Time=" + (DateTime.Now - begin));
            Console.ReadLine();
        }

        private static void Process(int Case, TextReader reader, TextWriter writer)
        {
            string ss = reader.ReadLine();

            var chars = new int['Z' - 'A' + 1];
            foreach (char i in ss)
            {
                chars[i - 'A']++;
            }

            var digit = new List<int>();
            while (chars['Z' - 'A'] != 0)
            {
                digit.Add(0);
                chars['Z' - 'A']--;
                chars['E' - 'A']--;
                chars['R' - 'A']--;
                chars['O' - 'A']--;
            }
            while (chars['W' - 'A'] != 0)
            {
                digit.Add(2);
                chars['T' - 'A']--;
                chars['W' - 'A']--;
                chars['O' - 'A']--;
            }
            while (chars['G' - 'A'] != 0)
            {
                digit.Add(8);
                chars['E' - 'A']--;
                chars['I' - 'A']--;
                chars['G' - 'A']--;
                chars['H' - 'A']--;
                chars['T' - 'A']--;
            }
            while (chars['T' - 'A'] != 0)
            {
                digit.Add(3);
                chars['T' - 'A']--;
                chars['H' - 'A']--;
                chars['R' - 'A']--;
                chars['E' - 'A']--;
                chars['E' - 'A']--;
            }
            while (chars['R' - 'A'] != 0)
            {
                digit.Add(4);
                chars['F' - 'A']--;
                chars['O' - 'A']--;
                chars['U' - 'A']--;
                chars['R' - 'A']--;
            }
            while (chars['F' - 'A'] != 0)
            {
                digit.Add(5);
                chars['F' - 'A']--;
                chars['I' - 'A']--;
                chars['V' - 'A']--;
                chars['E' - 'A']--;
            }
            while (chars['O' - 'A'] != 0)
            {
                digit.Add(1);
                chars['O' - 'A']--;
                chars['N' - 'A']--;
                chars['E' - 'A']--;
            }
            while (chars['V' - 'A'] != 0)
            {
                digit.Add(7);
                chars['S' - 'A']--;
                chars['E' - 'A']--;
                chars['V' - 'A']--;
                chars['E' - 'A']--;
                chars['N' - 'A']--;
            }
            while (chars['S' - 'A'] != 0)
            {
                digit.Add(6);
                chars['S' - 'A']--;
                chars['I' - 'A']--;
                chars['X' - 'A']--;
            }
            while (chars['I' - 'A'] != 0)
            {
                digit.Add(9);
                chars['I' - 'A']--;
            }

            digit.Sort();
            string res = string.Join("", digit);
            Console.WriteLine("Case #{0}: {1}", Case, res);
            writer.WriteLine("Case #{0}: {1}", Case, res);
        }
    }
}