using System;
using System.Collections;
using System.IO;
using java.math;

namespace Fair_Warning
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            string filename = @"B-large.in.txt";

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

        class comparer : IComparer
        {

            public int Compare(object x, object y)
            {
                BigInteger bx = (BigInteger) x;
                BigInteger by = (BigInteger)y;

                return bx.compareTo(by);
            }
        }

        private static void Process(int C, TextReader reader, TextWriter writer)
        {
            string[] s = reader.ReadLine().Split(' ');

            int N = int.Parse(s[0]);

            BigInteger[] t = new BigInteger[N];

            for (int i = 0; i < N; i++)
                t[i] = new BigInteger(s[i + 1]);

            Array.Sort(t, new comparer());
            BigInteger[] delta = new BigInteger[N-1];

            for(int i=1; i<N; i++)
            {
                delta[i - 1] = t[i].subtract(t[i-1]);
            }

            BigInteger m = delta[0];
            for (int i = 1; i < N-1; i++)
            {
                m = m.gcd(delta[i]);
            }

            BigInteger[] d = t[0].divideAndRemainder(m);
            //BigInteger zero = new BigInteger("0");

            if (m.subtract(d[1]) == m)
            {
                Console.WriteLine("Case #{0}: {1}", C, 0);
                writer.WriteLine("Case #{0}: {1}", C, 0);
            }
            else
            {
                Console.WriteLine("Case #{0}: {1}", C, m.subtract(d[1]));
                writer.WriteLine("Case #{0}: {1}", C, m.subtract(d[1]));
            }
        }
    }
}