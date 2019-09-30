using System;
using System.Numerics;
using System.Text;

namespace C
{
    public class C
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Case #1:");

            int len = 32, cnt = 500;

            string seed = new string('0', len - 2);
            seed = '1' + seed + '1';

            BigInteger[] num = new BigInteger[11];
            int[] divs = new int[11];
            int[] bases = new int[9];
            for (int i = 0; i < 9; i++)
                bases[i] = i + 2;

            int[] primes = new int[] { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271 };

            while (cnt > 0 && seed.Length == len)
            {
                foreach (var b in bases)
                    num[b] = ConstructBigInteger(seed, b);

                bool valid = true;

                foreach (var b in bases)
                {
                    bool divided = false;

                    foreach (var prime in primes)
                        if (num[b] % prime == 0)
                        {
                            divided = true;
                            divs[b] = prime;
                            break;
                        }

                    if (!divided)
                    {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                {
                    Console.Write(seed);
                    foreach (var b in bases)
                        Console.Write(" {0}", divs[b]);
                    Console.WriteLine();
                    cnt--;
                }

                num[2] += 2;
                seed = ConvertToBinaryString(num[2]);
            }
        }

        static BigInteger ConstructBigInteger(string s, int b)
        {
            BigInteger n = new BigInteger(0);
            for (int i = 0; i < s.Length; i++)
            {
                n *= b;
                if (s[i] == '1')
                    n++;
            }
            return n;
        }

        static string ConvertToBinaryString(BigInteger n)
        {
            StringBuilder s = new StringBuilder();
            while (n != 0)
            {
                if (n % 2 == 0)
                    s.Insert(0, '0');
                else
                    s.Insert(0, '1');
                n /= 2;
            }
            return s.ToString();
        }
    }
}
