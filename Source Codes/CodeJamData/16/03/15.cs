using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Numerics;
using System.Threading;

namespace ProblemC
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
            var t = int.Parse(Console.ReadLine());
            for (var caseNumber = 1; caseNumber <= t; caseNumber++)
            {
                var line = Console.ReadLine();
                var lineItems = line.Split(' ');
                var jamcoinLength = int.Parse(lineItems[0], CultureInfo.InvariantCulture);
                var jamcoinCount = int.Parse(lineItems[1], CultureInfo.InvariantCulture);

                var jamcoinsWithProof = FindCoins(jamcoinLength).Take(jamcoinCount);

                Console.WriteLine("Case #{0}:", caseNumber);
                foreach (var jamcoinWithProof in jamcoinsWithProof)
                {
                    Console.Write(jamcoinWithProof.Coin);
                    for (var numberBase = 2; numberBase <= 10; numberBase++)
                    {
                        Console.Write(' ');
                        Console.Write(jamcoinWithProof.Divisors[numberBase]);
                    }
                    Console.WriteLine();
                }
            }
        }

        private static IEnumerable<JamcoinWithProof> FindCoins(int coinLength)
        {
            if (coinLength > 62)
                throw new ArgumentException();

            var possibleDivisors = GetPrimes().Take(100).ToList();

            var minPossibleBinaryJamcoin = (1L << (coinLength - 1)) + 1;
            var maxPossibleBinaryJamcoin = (1L << coinLength) - 1;

            for (var possibleBinaryJamcoin = minPossibleBinaryJamcoin; 
                possibleBinaryJamcoin <= maxPossibleBinaryJamcoin; 
                possibleBinaryJamcoin += 2)
            {
                var jamcoinWithProof = TryGetJamcoinWithProof(possibleBinaryJamcoin, possibleDivisors);
                if (jamcoinWithProof != null)
                    yield return jamcoinWithProof;
            }
        }

        private static JamcoinWithProof TryGetJamcoinWithProof(long possibleBinaryJamcoin, IEnumerable<int> possibleDivisors)
        {
            var jamcoinWithProof = new JamcoinWithProof();
            for (var numberBase = 2; numberBase <= 10; numberBase++)
            {
                var coinInBase = GetCoinInBase(possibleBinaryJamcoin, numberBase);
                var divisor = possibleDivisors
                    .Where(possibleDivisor => ((coinInBase % possibleDivisor) == 0) && (possibleDivisor != coinInBase))
                    .Cast<int?>()
                    .FirstOrDefault();
                if (divisor == null)
                    return null;
                jamcoinWithProof.Divisors.Add(numberBase, divisor.Value);
            }

            jamcoinWithProof.Coin = GetCoinInBase(possibleBinaryJamcoin, 10).ToString(CultureInfo.InvariantCulture);
            return jamcoinWithProof;
        }

        private static IEnumerable<int> GetPrimes()
        {
            yield return 2;

            var oddPrimes = new List<int>();
            for (var possiblePrime = 3; possiblePrime < int.MaxValue - 1; possiblePrime += 2)
            {
                if (oddPrimes.All(prime => (possiblePrime % prime) != 0))
                {
                    oddPrimes.Add(possiblePrime);
                    yield return possiblePrime;
                }
            }
        }

        private static BigInteger GetCoinInBase(long binaryCoin, int numberBase)
        {
            var result = new BigInteger(0);
            var coinDigitsLeft = binaryCoin;
            var currentDigitWeight = new BigInteger(1);

            while (coinDigitsLeft > 0)
            {
                if ((coinDigitsLeft & 1) != 0)
                    result += currentDigitWeight;

                coinDigitsLeft >>= 1;
                currentDigitWeight *= numberBase;
            }

            return result;
        }

        private class JamcoinWithProof
        {
            public JamcoinWithProof()
            {
                Divisors = new Dictionary<int, int>();
            }

            public string Coin { get; set; }
            public IDictionary<int, int> Divisors { get; }
        }
    }
}
