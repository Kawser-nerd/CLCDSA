using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

namespace CJ_Q
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = @"d:\Work\CodeJam\RB15\A-large.in";
            string output = @"d:\Work\CodeJam\RB15\A-large.out";

            using (var sin = new StreamReader(input))
            {
                using (var sout = new StreamWriter(output, false))
                {
                    var s = sin.ReadLine();
                    var N = long.Parse(s);
                    for (long i = 1; i <= N; i++)
                    {
                        string result = Task1(sin);
                        sout.Write("Case #{0}: ", i);
                        Console.Write("Case #{0}: ", i);
                        sout.Write(result);
                        Console.Write(result);
                        if (i != N)
                        {
                            sout.WriteLine();
                            Console.WriteLine();
                        }
                    }
                }
            }
        }

        private static string Task3(StreamReader sin)
        {
            return "";
        }

        private static string Task2(StreamReader sin)
        {
          
            return "".ToString();
        }

        private static string Task1(StreamReader sin)
        {
            var N = sin.ReadLine();
            var c = new long[]
            {
                0, 9+1, 9+1+9, 99+1+9, 99+1+99, 999+1+99, 999+1+999, 9999+1+999,
                9999+1+9999, 99999+1+9999, 99999+1+99999, 999999+1+99999, 999999+1+999999,
                9999999+1+999999, 9999999+1+9999999, 99999999+1+9999999
            };

            var l = N.Length;
            BigInteger basis = 0;

            var NN = BigInteger.Parse(N);
            if (NN <= 19) return N;

            if (N.Last() == '0')
            {
                basis += 1;
                NN--;
                N = NN.ToString();
                l = N.Length;
            }

            for (int i = 0; i < l; i++)
            {
                basis += c[i];
            }
            if (l%2 == 0)
            {
                // even
                var L = l/2;
                var N1 = N.Substring(L, L);
                var N2a = N.Substring(0, L).Reverse().ToArray();
                var N2 = new string(N2a);

                var NN1 = BigInteger.Parse(N1);
                var NN2 = BigInteger.Parse(N2)-1;
                basis += NN2;
                basis += 1;
                basis += NN1;
                if (NN2 == 0) basis--;
            }
            else
            {
                // odd
                var L = l / 2;
                var N1 = N.Substring(L, L+1);
                var N2a = N.Substring(0, L).Reverse().ToArray();
                var N2 = new string(N2a);

                var NN1 = BigInteger.Parse(N1);
                var NN2 = BigInteger.Parse(N2)-1;
                basis += NN2;
                basis += 1;
                basis += NN1;
                if (NN2 == 0) basis--;
            }

            return basis.ToString();
        }

    }
}
