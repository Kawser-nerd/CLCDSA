using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Number_Game
{
    class Program
    {
        static void Main(string[] args)
        {
            string filename = @"C-small-attempt0.in.txt";

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (StreamReader reader = new StreamReader(filename))
            {
                using (StreamWriter writer = new StreamWriter(filename.Replace(".in.", ".out."), false))
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

        private static void Process(int C, TextReader reader, TextWriter writer)
        {
            string[] s = reader.ReadLine().Split(' ');

            int a1 = int.Parse(s[0]);
            int a2 = int.Parse(s[1]);
            int b1 = int.Parse(s[2]);
            int b2 = int.Parse(s[3]);

            long c = calculate(a1, a2, b1, b2);
            Console.WriteLine("Case #{0}: {1}", C, c);
            writer.WriteLine("Case #{0}: {1}", C, c);
        }


        private static long calculate(int a1, int a2, int b1, int b2)
        {
            long total = 0;
            for (int i = a1; i <= a2; i++)
            {
                for (int j = b1; j <= b2; j++)
                {
                    total += win(i, j);
                }
            }
            return total;
        }

        private static int win(int a, int b)
        {
            if (a == b)
            {
                return 0;
            }
            if (b > a)
            {
                int c = b;
                b = a;
                a = c;
            }
            if (a % b == 0)
            {
                return 1;
            }

            if (a == 2 && b == 1)
            {
                return 1;
            }

            if (a - b > b)
            {
                return 1;
            }

            if (win(a - b, b) == 1)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }

        private static int gcd(int a, int b)
        {
            while (a > 0)
            {
                if (b > a)
                {
                    int c = b;
                    b = a;
                    a = c;
                }
                a = a % b;
            }
            return b;
        }
    }
}
