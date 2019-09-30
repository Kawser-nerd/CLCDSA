using System;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Enclosure
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            const string filename = @"..\..\C-small-attempt5.in";
            //const string filename = @"..\..\B-large.in";

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
            int n = int.Parse(ss[0]);
            int m = int.Parse(ss[1]);
            int k = int.Parse(ss[2]);

            if (n > m)
            {
                int c = n;
                n = m;
                m = c;
            }

            int nm = n*m;
            int count=0;
            if (n == 1 || n == 2)
            {
                count = k;
            }
            if (n == 3)
            {
                if (k <= 4)
                {
                    count = k;
                }
                else if (k + 4 > nm)
                {
                    count = (2*m + 2*(n - 2)) - (nm - k);
                }
                else
                {
                    count = 4;
                    k -= 5;
                    while (k > 0)
                    {
                        if (k == 1)
                        {
                            k--;
                            count++;
                        }
                        else if (k > 1)
                        {
                            count += 2;
                            k -= 3;
                        }
                    }
                }
            }
            if (n == 4)
            {
                if (k <= 4)
                {
                    count = k;
                }
                else if (k<=5)
                {
                    count = 4;
                }
                else if (k + 4 > nm)
                {
                    count = (2 * m + 2 * (n - 2)) - (nm - k);
                }
                else if (k == 10)
                {
                    count = 7;
                }
                else if (k == 14)
                {
                    count = 9;
                }
                else if (k <= 11)
                {
                    count = 4;
                    k -= 5;
                    while (k > 0)
                    {
                        if (k == 1)
                        {
                            k--;
                            count++;
                        }
                        else if (k > 1)
                        {
                            count += 2;
                            k -= 3;
                        }
                    }
                }
                else
                {
                    count = 8;
                    k -= 12;
                    while (k > 0)
                    {
                        if (k == 1)
                        {
                            k--;
                            count++;
                        }
                        else if (k > 1)
                        {
                            count += 2;
                            k -= 4;
                        }
                    }
                }

            }
            Console.WriteLine("Case #{0}: {1}", Case, count);
            writer.WriteLine("Case #{0}: {1}", Case, count);
        }
    }
}