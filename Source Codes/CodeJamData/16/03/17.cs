using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace C
{
    class Program
    {
        static List<ulong> primes = new List<ulong>();

        static void GenPrimes(ulong until)
        {
            primes.Add(2);
            for (ulong u = 3; u <= until; u += 2)
                if (primes.TakeWhile(p => p * p <= u).All(p => u % p != 0))
                    primes.Add(u);
        }

        static ulong IsNoPrime(BigInteger u)
        {
            return primes.TakeWhile(p => p * p <= u).FirstOrDefault(p => u % p == 0);
        }

        static IEnumerable<ulong> GetCandidates(int n)
        {
            for (ulong x = (1ul << (n - 1)) + 1; ; x += 2)
                yield return x;
        }

        static BigInteger[] IsJamCoin(ulong coin)
        {
            ulong proof2 = IsNoPrime(coin);
            if (proof2 == 0) return null;

            BigInteger[] proof = new BigInteger[10];
            proof[1] = proof2;

            List<BigInteger> bits = new List<BigInteger>();
            for (; coin != 0; coin /= 2)
                bits.Add(coin % 2);
            bits.Reverse();

            for (ulong i = 3; i <= 10; ++i)
            {
                BigInteger bi = bits.Aggregate((a,b) => i * a + b);
                proof[i - 1] = IsNoPrime(bi);
                if (proof[i - 1] == 0) return null;
                if (i == 10) proof[0] = bi;
            }

            return proof;
        }

        static void Main(string[] args)
        {
            GenPrimes(10000);
            int t = int.Parse(Console.ReadLine());
            for (int i = 1; i <= t; ++i)
            {
                Console.WriteLine("Case #" + i + ":");
                var parts = Console.ReadLine().Split();
                int n = int.Parse(parts[0]);
                int j = int.Parse(parts[1]);
                var res = GetCandidates(n)
                    .AsParallel()
                    .Select(IsJamCoin)
                    .Where(p => p != null)
                    .Take(j)
                    .ToList();
                foreach (var r in res)
                    Console.WriteLine(string.Join(" ", r));
            }
        }
    }
}
