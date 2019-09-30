using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Numerics;
using System.Text;
using System.Threading;

namespace Coin_Jam
{
    internal class Program
    {
        private static List<long> _primes;

        private static void Main(string[] args)
        {
            const string filename = @"..\..\sample.in.txt";
            //const string filename = @"..\..\B-small.in";
            //const string filename = @"..\..\B-large.in";

            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            Primes();

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (var reader = new StreamReader(filename))
            {
                using (var writer = new StreamWriter(filename.Replace(".in", ".out"), false))
                {
                    Mine(writer);
                    ////int n = int.Parse(reader.ReadLine());
                    ////for (int i = 1; i <= n; i++)
                    ////{
                    ////    Console.Write("N=" + i + " Time=");
                    ////    Process(i, reader, writer);
                    ////    Console.WriteLine((DateTime.Now - current).ToString().Substring(4));
                    ////    current = DateTime.Now;
                    ////}
                }
            }

            Console.WriteLine("Time=" + (DateTime.Now - begin));
            Console.ReadLine();
        }

        private static void Primes()
        {
            _primes = new List<long> {2};
            for (int i = 3; i < 1000000; i += 2)
            {
                bool all = true;
                foreach (int prime in _primes)
                {
                    if (prime*prime > i)
                        break;
                    if (i%prime == 0)
                    {
                        all = false;
                        break;
                    }
                }
                if (all)
                    _primes.Add(i);
            }
        }

        private static string BtS(BigInteger s)
        {
            Stack<int> st=new Stack<int>();
            while (s>0)
            {
                st.Push((int)(s&1));
                s >>= 1;
            }
           
            StringBuilder bb=new StringBuilder();
            foreach (var i in st)
            {
                bb.Append(i == 0 ? '0' : '1');
            }
            return bb.ToString();
        }

        private static void Mine(TextWriter writer)
        {
            BigInteger start = Convert.ToInt64("10000000000000000000000000000001", 2);

            int count = 0;
            for (BigInteger i = start;; i += 2)
            {
                string s = BtS(i);
                var divs = new long[11];
                bool ok = true;
                for (int j = 2; j <= 10; j++)
                {
                    BigInteger value = ConvertToInt64(s, j);

                    foreach (long prime in _primes)
                    {
                        if (prime*prime > value)
                            break;
                        if (value%prime == 0)
                        {
                            divs[j] = prime;
                            break;
                        }
                    }

                    if (divs[j] == 0)
                    {
                        ok = false;
                        break;
                    }
                }

                if (!ok)
                    continue;

                count++;
                writer.Write(s);
                Console.WriteLine(i);
                for (int j = 2; j < 11; j++)
                {
                    writer.Write(' ');
                    writer.Write(divs[j]);
                }
                writer.WriteLine();
                if (count == 500)
                    return;
            }
        }

        private static BigInteger ConvertToInt64(string s, int bas)
        {
            BigInteger b = 1;
            BigInteger sum = 0;
            for (int i = s.Length - 1; i >= 0; i--)
            {
                sum += (s[i] - '0')*b;

                b *= bas;
            }
            return sum;
        }

        private static void Process(int Case, TextReader reader, TextWriter writer)
        {
            string[] ss = reader.ReadLine().Split(' ');

            double time = 0;

            Console.WriteLine("Case #{0}: {1:#.0000000}", Case, time);
            writer.WriteLine("Case #{0}: {1:#.0000000}", Case, time);
        }
    }
}