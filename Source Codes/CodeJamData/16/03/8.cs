using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Numerics;
using System.Diagnostics;

namespace CodeJam
{
    class Program
    {
        static string[] Solve(int N, int J)
        {
            var jamcoins = new string[J];
            for (int i = 0; i < J; ++i)
            {
                char[] digits = Enumerable.Repeat('0', N).ToArray();
                digits[0] = '1';
                digits[N - 1] = '1';
                for (int j = 0; j < N - 2; ++j)
                {
                    if ((i & (1 << j)) != 0)
                    {
                        digits[j * 2 + 1] = '1';
                        digits[j * 2 + 2] = '1';
                    }
                }
                jamcoins[i] = new string(digits.Reverse().ToArray());
            }
            return jamcoins;
        }
        static string[] Divisors(string jamcoin)
        {
            var values = new List<BigInteger>();
            for (int n = 2; n <= 10; ++n)
            {
                BigInteger value = new BigInteger(0);
                BigInteger digit = new BigInteger(1);
                foreach (char c in jamcoin.Reverse())
                {
                    if (c == '1') { value += digit; }
                    digit *= n;
                }
                Debug.Assert(value % (n + 1) == 0);
                values.Add(value / (n + 1));
            }
            return values.Select(value => value.ToString()).ToArray();
        }
        static void Main(string[] args)
        {
            string filename = "../C-large";
            var sr = new StreamReader(filename + ".in");
            var sw = new StreamWriter(filename + ".out");
            int T = int.Parse(sr.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                sw.WriteLine("Case #{0}:", i + 1);
                var values = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);
                foreach (var str in Solve(values[0], values[1]))
                {
                    sw.WriteLine("{0} {1}", str, string.Join(" ", Divisors(str)));
                }
                Console.WriteLine("Case #{0}: Done", i + 1);
            }
            sw.Close();
            sr.Close();
            Console.ReadKey();
        }
    }
}
