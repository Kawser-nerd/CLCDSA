using System;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Alphabet_Cake
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
            string[] ss = reader.ReadLine().Split(' ');
            int r = int.Parse(ss[0]);
            int c = int.Parse(ss[1]);

            var map = new char[r,c];

            for (int i = 0; i < r; i++)
            {
                string s = reader.ReadLine();
                for (int j = 0; j < c; j++)
                {
                    map[i, j] = s[j];
                }
            }

            var rf = new bool[r];
            for (int i = 0; i < r; i++)
            {
                bool f = false;
                for (int j = 0; j < c; j++)
                {
                    if (map[i, j] != '?')
                    {
                        f = true;
                        break;
                    }
                }
                rf[i] = f;
            }

            bool topf = false;

            var ans = new char[r,c];

            for (int i = 0; i < r; i++)
            {
                int li = 0;
                int down = i;
                while (down + 1 < r && !rf[down + 1])
                {
                    down++;
                }

                for (int j = 0; j < c; j++)
                {
                    if (map[i, j] != '?')
                    {
                        int ri = j;
                        while (ri + 1 < c && map[i, ri + 1] == '?')
                        {
                            ri++;
                        }

                        if (topf)
                        {
                            for (int k = i; k <= down; k++)
                            {
                                for (int l = li; l <= ri; l++)
                                {
                                    ans[k, l] = map[i, j];
                                }
                            }
                        }
                        else
                        {
                            if (ri + 1 == c)
                                topf = true;

                            for (int k = 0; k <= down; k++)
                            {
                                for (int l = li; l <= ri; l++)
                                {
                                    ans[k, l] = map[i, j];
                                }
                            }
                        }

                        li = ri + 1;
                    }
                }
            }

            Console.WriteLine("Case #{0}:", Case);
            writer.WriteLine("Case #{0}:", Case);

            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    writer.Write(ans[i, j]);
                    Console.Write(ans[i, j]);
                }
                writer.WriteLine();
                Console.WriteLine();
            }
        }
    }
}