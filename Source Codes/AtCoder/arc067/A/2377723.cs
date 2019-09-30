using System;
using System.Collections.Generic;
using System.Linq;

namespace ARC067
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var N = int.Parse(Console.ReadLine());
            var prime = new Prime(1000);
            var factCounts = new int[1001];

            for (var i = 1; i <= N; i++)
            {
                foreach (var f in prime.Factorize(i)) factCounts[f]++;
            }

            ModInt ans = 1;
            foreach (var fc in factCounts) ans *= fc + 1;

            Console.WriteLine(ans);
        }
    }

    public struct ModInt
    {
        public static int Mod = 1000000007;

        readonly long value;
        public int Value { get { return (int)value; } }
        public ModInt Inverse { get { return GetInverse(); } }

        public ModInt(long value)
        {
            value %= Mod;
            this.value = value < 0 ? value + Mod : value;
        }

        ModInt GetInverse()
        {
            if (value == 0) throw new InvalidOperationException("value must NOT equal 0");
            return Pow(Mod - 2);
        }

        public ModInt Square()
        {
            return this * this;
        }

        public ModInt Pow(long exp)
        {
            if (exp == 0) return 1;
            if (exp % 2 == 0) return Pow(exp / 2).Square();
            return this * Pow(exp - 1);
        }

        public static ModInt Parse(string str)
        {
            return long.Parse(str);
        }

        public static implicit operator ModInt(long value)
        {
            return new ModInt(value);
        }

        public static ModInt operator +(ModInt left, ModInt right)
        {
            return left.value + right.value;
        }

        public static ModInt operator -(ModInt left, ModInt right)
        {
            return left.value - right.value;
        }

        public static ModInt operator *(ModInt left, ModInt right)
        {
            return left.value * right.value;
        }

        public static ModInt operator /(ModInt left, ModInt right)
        {
            return left * right.Inverse;
        }

        public override bool Equals(object obj)
        {
            if (!(obj is ModInt)) return false;
            return value == ((ModInt)obj).value;
        }

        public override int GetHashCode()
        {
            return value.GetHashCode();
        }

        public override string ToString()
        {
            return value.ToString();
        }
    }

    public class Prime
    {
        readonly List<int> primes;
        public IReadOnlyList<int> List { get { return primes; } }

        public Prime(int max)
        {
            primes = new List<int>();

            var sieve = new bool[max + 1];
            for (var i = 2; i <= max; i++)
            {
                if (sieve[i]) continue;
                primes.Add(i);
                for (var j = i * 2; j <= max; j += i) sieve[j] = true;
            }
        }

        public bool Is(int n)
        {
            return n > 1 && primes.TakeWhile(p => p * p <= n).All(p => n % p != 0);
        }

        public IEnumerable<int> Factorize(int n)
        {
            foreach (var p in primes.TakeWhile(p => p * p <= n))
            {
                while (n % p == 0)
                {
                    n /= p;
                    yield return p;
                }
            }
            if (n != 1) yield return n;
        }
    }
}