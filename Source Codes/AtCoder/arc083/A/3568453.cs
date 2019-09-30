#pragma warning disable

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Text.RegularExpressions;
using System.Diagnostics;
using System.Numerics;
using System.Collections;
using System.Timers;
using System.Threading;
// using System.Threading.Tasks;

static class MainClass
{
    public static void Main(string[] args)
    {
        var abcdef = Console.ReadLine().SplittedStringToInt32List();
        var a = abcdef[0];
        var b = abcdef[1];
        var c = abcdef[2];
        var d = abcdef[3];
        var e = abcdef[4];
        var f = abcdef[5];

        //var ac = c / 100.0 * a;
        //var ad = d / 100.0 * a;

        //var bc = c / 100.0 * b;
        //var bd = d / 100.0 * b;

        //var types = new double[]{ ac, ad, bc, bd };

        //var dp = new double[5,f+1];

        //for (int i = 0; i < 4; i++)
        //{
        //    for (int j = 0; j <= f; j++)
        //    {
        //        dp[i + 1, j] = dp[i, j];
        //    }
        //}

        var max = 0;
        var weight = 0;
        decimal maxdec = 0;
        for (int i = 0; i < 31 + 3; i++)
        {
            for (int j = 0; j < Math.Max(31 + 3 - i*a,1); j++)
            {
                if (i == 0 && j == 0)
                    continue;
                for (int k = 0; k < Math.Max(3002 + 3 - 100*i*a - 100*j*b,1); k++)
                {

                    for (int l = 0; l < Math.Max(3002 - 100*i*a - 100*j*b - k*c + 3,1); l++)
                    {
                        var we = a*i * 100 + j *b* 100 + k*c + l*d;

                        if (we <= f && we != 0)
                        {
                            var nums =  (a*i + j * b) * e;

                            var num = k * c + l * d;
                            var numdec = ((decimal)num / (decimal)we);
                            if (num <= nums && numdec > maxdec)
                            {

                                weight = we;
                                max = num;
                                maxdec = numdec;
                            }
                        }
                    }
                }
            }
        }
        if (weight == 0)
            Console.WriteLine(a * 100 + " 0");
        else
            Console.WriteLine(weight + " " + max);
        Console.ReadLine();
    }
    

    #region ?????

    #region ?????

    public static int ToInt32(this string str) => int.Parse(str);
    public static BigInteger ToBigInteger(this string str) => BigInteger.Parse(str);
    public static List<string> SplittedStringToList(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).ToList();
    public static List<int> SplittedStringToInt32List(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => int.Parse(x)).ToList();

    public static List<BigInteger> SplittedStringToBigInteger(this string str) => str.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(x => BigInteger.Parse(x)).ToList();
    #endregion
    #region DeepClone
    public static T DeepClone<T>(this T src)
    {
        using (var memoryStream = new MemoryStream())
        {
            var binaryFormatter
              = new BinaryFormatter();
            binaryFormatter.Serialize(memoryStream, src);
            memoryStream.Seek(0, SeekOrigin.Begin);
            return (T)binaryFormatter.Deserialize(memoryStream);
        }
    }
    #endregion

    public static int Gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return Gcd(b, a % b);
    }
    public static BigInteger Gcd(BigInteger a, BigInteger b)
    {
        if (b == 0)
            return a;
        return Gcd(b, a % b);
    }

    public static BigInteger Lcm(BigInteger a, BigInteger b)
    {
        return (a * b) / Gcd(a, b);
    }

    public static BigInteger Factorial(int n)
    {
        var dp = new BigInteger[n];
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            dp[i] = dp[i - 1] * (i + 1);
        }
        return dp[n - 1];
    }

    public static List<long> PrimeFactorize(long n)
    {
        var bases = n;
        var num = (long)Math.Pow(n, 0.5);
        var ls = new List<long>();
        for (int i = 2; i <= num; i++)
        {
            if (n % i == 0)
            {
                n = n / i;
                ls.Add(i);
                i--;
                continue;
            }
        }
        long nnn = 1;
        foreach (var item in ls)
        {
            nnn = nnn * item;
        }
        if (nnn != bases)
            ls.Add(n);
        return ls;
    }
    public static class PrimeNumber
    {

        static long[] seedPrimes = {
        2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97
    };

        public static bool IsPrime(long num)
        {
            if (num == 1)
                return false;
            if (seedPrimes.Contains(num))
                return true;
            if (seedPrimes.Any(x => num % x == 0))
                return false;

            return (num < 2000000) ? IsPrimeBruteforce(num) : IsPrimeMillarRrabin(num);
        }

        private static bool IsPrimeBruteforce(long num)
        {
            if (num == 1)
                return false;
            if (num != 2 && num % 2 == 0)
                return false;
            if (num != 3 && num % 3 == 0)
                return false;
            if (num != 5 && num % 5 == 0)
                return false;
            long i = 0;
            while (true)
            {
                foreach (var p in seedPrimes.Skip(3).Take(8))
                {
                    var primeCandidte = p + i;
                    if (primeCandidte > Math.Sqrt(num))
                        return true;
                    if (num % (primeCandidte) == 0)
                        return false;
                }
                i += 30;
            }
        }

        private static bool IsPrimeMillarRrabin(long num)
        {
            if (num <= 1)
                return false;
            if ((num & 1) == 0)
                return num == 2;

            if (num < 100 && seedPrimes.Contains((int)num))
                return true;

            var WitnessMax = GetWitnessMax(num);

            long d = num - 1;
            long s = 0;
            while ((d & 1) == 0)
            {
                s++;
                d >>= 1;
            }
            foreach (var w in seedPrimes.Take(WitnessMax))
            {
                if (!MillarRrabin(num, s, d, w))
                    return false;
            }
            return true;
        }


        private static int GetWitnessMax(long num)
        {
            if (num < 2047)
                return 1;
            if (num < 1373653)
                return 2;
            if (num < 25326001)
                return 3;
            if (num < 3215031751)
                return 4;
            if (num < 2152302898747)
                return 5;
            if (num < 3474749660383)
                return 6;
            if (num < 341550071728321)
                return 7;
            if (num < 3825123056546413051)
                return 9;
            return 12;
        }


        private static bool MillarRrabin(long num, long s, long d, long witness)
        {
            long x = ModPow(witness, d, num);
            if (x == 1)
                return true;
            for (long r = 0; r < s; r++)
            {
                if (x == num - 1)
                    return true;
                BigInteger rem;
                BigInteger.DivRem(BigInteger.Multiply(x, x), num, out rem);
                x = (long)(rem);
            }
            return false;
        }

        private static long ModPow(long baseValue, long exponent, long modulus)
        {
            return (long)BigInteger.ModPow(baseValue, exponent, modulus);
        }

    }

    public static List<long> Make(long n)
    {
        var ls = new List<long>();
        // ls.Add(1);
        for (int i = 1; i*i <= n; i++)
        {
            if (n % i == 0)
            {
                ls.Add(i);
                if (i != 1 && i * i != n)
                {
                    ls.Add(n / i);
                }
            }
        }
        return ls;
    }

    // AOJ - Power
    public static BigInteger Power(BigInteger m,BigInteger n,int p)
    {
        BigInteger amari = 1;
        while (true)
        {
            if (n / 2 >= 1)
            {
                BigInteger b = m;
                m *= m;
                if (n % 2 == 1)
                {
                    amari *= b;
                    amari %= p;
                }
                n /= 2;
            }
            m %= p;
            if (n / 2== 0)
            {
                break;
            }
        }
        return (m * amari) % p;
    }
    #endregion

}