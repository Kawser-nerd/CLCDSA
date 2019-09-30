using MathX;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ABC110D___Factorization
{
    public class Program
    {
    
        public static readonly int MOD = (int)Math.Pow(10, 9) + 7;

        public static void Main(string[] args)
        {
            checked { 
                string[] line = Console.ReadLine().Trim().Split(' ');
                int n = int.Parse(line[0]);
                int m = int.Parse(line[1]);

                List<int> primes = MathX.MathX.PrimeFactor(m).Select(x => (int)x).ToList();
                Dictionary<int, int> primesDic = new Dictionary<int, int>();
                foreach (int i in primes)
                {
                    if (primesDic.ContainsKey(i)) primesDic[i]++;
                    else primesDic.Add(i, 1);
                }

                long rlt = 1;
                foreach(KeyValuePair<int,int> i in primesDic)
                {
                    rlt *= MathX.MathX.Combination(i.Value + n - 1, i.Value, MOD);
                    rlt %= MOD;
                }

                Console.WriteLine(rlt % MOD);
            }
        }
    }

}

namespace MathX
{
    public class MathX
    {
        //??????
        public static long Lcm(long a, long b)
        {
            return a / Gcd(a, b) * b;
        }

        //??????
        public static long Gcd(long a, long b)
        {
            if (a < b)
                return Gcd(b, a);  // ??????????????
            if (b == 0) return a; //???0??????????????GCD
            long d = 0;
            do
            {
                d = a % b;
                a = b;
                b = d;
            } while (d != 0);
            return a;
        }

        //?????????????????????
        public static IEnumerable<long> PrimeFactor(long n)
            {
                while (n > 1)
                {
                    long factor = GetFactor(n);
                    yield return factor;
                    n = n / factor;
                }
            }

         private static long GetFactor(long n, int seed = 1)
            {
                if (n % 2 == 0)  return 2;
                if (IsPrime(n))  return n;
                long x = 2, y = 2, d = 1;
                long count = 0;
                while (d == 1)
                {
                    count++;
                    x = f(x, n, seed);
                    y = f(f(y, n, seed), n, seed);
                    d = Gcd(Math.Abs(x - y), n);
                }
                if (d == n)
                    // ?????????????????????????
                    return GetFactor(n, seed + 1);
                // ????????????????????
                return GetFactor(d);
            }

            private static int[] seeds = new int[] { 3, 5, 7, 11, 13, 17 };
            private static long f(long x, long n, int seed)
            {
                return (seeds[seed % 6] * x + seed) % n;
            }


        //?????
        public static bool IsPrime(long number)
        {
            long boundary = (long)Math.Floor(Math.Sqrt(number));

            if (number == 1)  return false;
            if (number == 2)  return true;

            for (long i = 2; i <= boundary; ++i)
            {
                if (number % i == 0) return false;
            }
            return true;
        }

        //???
        public static long Factorial(long n, long mod = 0)
        {
            checked
            {
                if (n == 0)  return 1L;
                if (mod == 0)
                { return n * Factorial(n - 1); }
                else
                { return n * Factorial(n - 1, mod) % mod; }           
            }
        }

        //????????
        public static long Combination(long n,long r, long mod = 0)
        {
            checked
            {
                long ans = 1;
                if (r > n / 2) return Combination(n, n - r, mod);//???????(5C4 = 5C1)
                long div = 1;
                for (int i = 0; i < r; i++)
                {
                    ans *= n - i;
                    div *= i + 1;
                    if (mod != 0)
                    {
                        ans %= mod;
                        div %= mod;
                    }
                }

                if (mod != 0)
                {
                    ans *= Powmod(div, mod - 2, mod);
                    return ans % mod;
                }
                else return ans/div;

            }
        }


        //?mod???????
        public static  long Powmod(long a, long p,long mod)
        {
            checked
            {
                long ans = 1;
                long mul = a;
                for (; p > 0; p >>= 1, mul = (mul * mul) % mod)
                {
                    if ((p & 1) == 1) ans = (ans * mul) % mod;
                }
                return ans;
            }
        }
    }

}