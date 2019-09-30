using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace C
{
    class Program
    {
        static List<BigInteger> fairsquares = new List<BigInteger>();
        static int[] buff = new int[27];

        static int Solve(BigInteger A, BigInteger B)
        {
            int ia = fairsquares.BinarySearch(A);
            int ib = fairsquares.BinarySearch(B);

            int skip = ia < 0 ? ~ia : ia;
            int take = ib < 0 ? ~ib : ib + 1;

            return take - skip;
        }

        static void Push(string s)
        {
            BigInteger bi = BigInteger.Parse(s);
            fairsquares.Add(bi * bi);
        }

        static void Gen(int len, int p, int t)
        {
            if (p == len)
            {
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < len; i++)
                    sb.Append(buff[i]);

                string s = sb.ToString();
                string r = new String(s.Reverse().ToArray());

                if(s != "")
                    Push(s + r);

                for (int i = 0; i <= 3; i++)
                {
                    if (t + t + i * i < 10)
                        Push(s + i + r);
                }
            }
            else
            {
                int start = p == 0 ? 1 : 0;
                for (int i = start; i <= 2; i++)
                {
                    if (t + i * i >= 5)
                        continue;

                    buff[p] = i;
                    Gen(len, p + 1, t + i * i);
                }
            }
        }

        static void Prepare()
        {
            for (int i = 0; i < 27; i++)
                Gen(i, 0, 0);

            fairsquares.Sort();
        }

        static void Main(string[] args)
        {
            Prepare();

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] line = Console.ReadLine().Split();
                BigInteger A = BigInteger.Parse(line[0]);
                BigInteger B = BigInteger.Parse(line[1]);

                Console.WriteLine("Case #{0}: {1}", t, Solve(A, B));
            }
        }
    }
}
