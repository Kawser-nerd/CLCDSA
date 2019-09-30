using System;
using System.Collections.Generic;
using System.IO;
using System.Threading;
using System.Globalization;

namespace IncreasingSpeedLimits
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            new Program().Process();
        }

        public void Process()
        {
            using (tr = File.OpenText("input.txt"))
            using (tw = new StreamWriter("output.txt"))
            {
                int testCases = ReadInt();
                for (int i = 0; i < testCases; ++i)
                {
                    ProcessCase(i + 1);
                }
            }
        }

        private void ProcessCase(int testCaseNb)
        {
            long n;
            long m;
            Decimal X;
            Decimal Y;
            Decimal Z;
            Read5Some(out n, out m, out X, out Y, out  Z);

            Decimal[] A = new Decimal[m];
            ReadArray(A);

            // algorytm generujący ciągki

            long[] sequence = new long[n];
            {
                for (int i = 0; i < n; ++i)
                {
                    sequence[i] = (long)A[i % m];
                    // todo: to się może wyjebać! za mało precyzji tutaj chyba mamy! Potrzebujemy decimali!
                    A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z;
                }
            }

            long[] results = new long[n];

            {
                for (int i = (int)n - 1; i >= 0; --i)
                {
                    results[i] = 1;
                    for (int j = i + 1; j < n; ++j)
                    {
                        if (sequence[j] > sequence[i])
                            results[i] = (results[i] + results[j]) % 1000000007;
                    }
                }
            }

            Decimal final = 0;
            for (int i = 0; i < n; ++i)
                final += results[i];

            final = final % 1000000007;

            tw.WriteLine(String.Format("Case #{0}: {1}", testCaseNb, final));
        }

        private void ReadArray(Decimal[] tab)
        {
            for (int i = 0; i < tab.Length; ++i)
                tab[i] = ReadDecimal();
        }


        private int ReadInt()
        {
            string line = tr.ReadLine();
            return int.Parse(line);
        }

        private Decimal ReadDecimal()
        {
            string line = tr.ReadLine();
            return Decimal.Parse(line);
        }


        private void Read5Some(out long a, out long b, out Decimal c, out Decimal d, out Decimal e)
        {
            string line = tr.ReadLine();
            string[] tokens = line.Split(' ', '\t');
            a = long.Parse(tokens[0]);
            b = long.Parse(tokens[1]);
            c = Decimal.Parse(tokens[2]);
            d = Decimal.Parse(tokens[3]);
            e = Decimal.Parse(tokens[4]);
        }

        private TextReader tr = null;
        private TextWriter tw = null;
    }
}
