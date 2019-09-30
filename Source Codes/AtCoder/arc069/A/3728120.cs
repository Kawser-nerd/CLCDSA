using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Linq.Expressions;
using System.Net;
using System.Security.Cryptography;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using static System.Math;
// ReSharper disable MemberCanBeMadeStatic.Local
// ReSharper disable PossibleNullReferenceException
// ReSharper disable UnusedMember.Global
// ReSharper disable UnusedMember.Local
// ReSharper disable ArrangeTypeMemberModifiers
// ReSharper disable SuggestVarOrType_BuiltInTypes
// ReSharper disable SuggestVarOrType_Elsewhere
// ReSharper disable InvertIf
// ReSharper disable InconsistentNaming
// ReSharper disable ConvertIfStatementToSwitchStatement

namespace AtCoder
{
    public class Program
    {
        public static void Main(string[] args)
        {
            new Program().Solve();
            Console.Read();
        }


        private void Solve()
        {
            long N = cin.Long, M = cin.Long;

            var S = N;
            var c = M;

            if ((c >= 2 && S >= 1) || c >= 4)
            {
                //????????????????
                var make = Min(c / 2, S);
                c -= make * 2;

                var add = Max(c / 4, 0);
                Console.WriteLine(Max(M / 4, make + add));
            }
            else
            {
                Console.WriteLine(0);
            }


            /*
            var MOD = 1000000007;
            var N = cin.Int;
            var pf = new PrimeFactor();
            //???
            var sum = 0L;
            for (int i = 1; i <= N; i++)
            {
                sum += pf.Enumerate(N).Count();
                sum %= MOD;
            }

            Console.WriteLine(sum);
            */

        }




        static long Gcd(long a, long b)
        {
            while (true) {
                if (a < b) {
                    var a1 = a;
                    a = b;
                    b = a1;
                    continue;
                }

                if (b > 0) {
                    var a1 = a;
                    a = b;
                    b = a1 % b;
                    continue;
                }
                return a;
            }
        }

        static long Lcm(long a, long b)
        {
            return a / Gcd(a, b) * b;
        }
        
    }

    public class PrimeFactor
    {

        public IEnumerable<long> Enumerate(long n)
        {
            while (n > 1)
            {
                long factor = GetFactor(n);
                yield return factor;
                n = n / factor;
            }
        }

        private long GetFactor(long n, int seed = 1)
        {
            while (true)
            {
                if (n % 2 == 0) return 2;
                if (IsPrime(n)) return n;
                long x = 2;
                long y = 2;
                long d = 1;
                long count = 0;
                while (d == 1)
                {
                    count++;
                    x = f(x, n, seed);
                    y = f(f(y, n, seed), n, seed);
                    d = Gcd(Math.Abs(x - y), n);
                }

                if (d == n)
                {
                    seed = seed + 1;
                    continue;
                }

                n = d;
                seed = 1;
                // ????????????????????
            }
        }

        private readonly int[] seeds = new int[] { 3, 5, 7, 11, 13, 17 };
        private long f(long x, long n, int seed)
        {
            return (seeds[seed % 6] * x + seed) % n;
        }

        private static long Gcd(long a, long b)
        {
            while (true)
            {
                if (a < b)
                {
                    var a1 = a;
                    a = b;
                    b = a1;
                    continue;
                }

                if (b == 0) return a;
                long d = 0;
                do
                {
                    d = a % b;
                    a = b;
                    b = d;
                } while (d != 0);

                return a;
            }
        }

        // ??????????????????????????????
        private static bool IsPrime(long number)
        {
            long boundary = (long)Math.Floor(Math.Sqrt(number));

            if (number == 1)
                return false;
            if (number == 2)
                return true;

            for (long i = 2; i <= boundary; ++i)
            {
                if (number % i == 0)
                    return false;
            }

            return true;
        }
    }

#pragma warning disable IDE1006 // ??????
    public static class cin
#pragma warning restore IDE1006 // ??????
    {
        private const char _separator = ' ';
        private static readonly Queue<string> _input = new Queue<string>();


        public static string ReadLine => Console.ReadLine();

        public static string Str => Read;
        public static string Read
        {
            get {
                if (_input.Count != 0) return _input.Dequeue();

                // ReSharper disable once PossibleNullReferenceException
                var tmp = Console.ReadLine().Split(_separator);
                foreach (var val in tmp) {
                    _input.Enqueue(val);
                }

                return _input.Dequeue();
            }
        }

        public static int Int => int.Parse(Read);

        public static long Long => long.Parse(Read);

        public static double Double => double.Parse(Read);

        public static string[] StrArray(long n)
        {
            var ret = new string[n];
            for (long i = 0; i < n; ++i) ret[i] = Read;
            return ret;
        }

        public static int[] IntArray(long n)
        {
            var ret = new int[n];
            for (long i = 0; i < n; ++i) ret[i] = Int;
            return ret;
        }

        public static long[] LongArray(long n)
        {
            var ret = new long[n];
            for (long i = 0; i < n; ++i) ret[i] = Long;
            return ret;
        }

        static bool TypeEquals<T, U>() => typeof(T) == typeof(U);
        static T ChangeType<T, U>(U a) => (T)System.Convert.ChangeType(a, typeof(T));
        static T Convert<T>(string s) => TypeEquals<T, int>() ? ChangeType<T, int>(int.Parse(s))
            : TypeEquals<T, long>() ? ChangeType<T, long>(long.Parse(s))
            : TypeEquals<T, double>() ? ChangeType<T, double>(double.Parse(s))
            : TypeEquals<T, char>() ? ChangeType<T, char>(s[0])
            : ChangeType<T, string>(s);

        static void Multi<T>(out T a) => a = Convert<T>(Str);
        static void Multi<T, U>(out T a, out U b)
        {
            var ar = StrArray(2); a = Convert<T>(ar[0]); b = Convert<U>(ar[1]);
        }
        static void Multi<T, U, V>(out T a, out U b, out V c)
        {
            var ar = StrArray(3); a = Convert<T>(ar[0]); b = Convert<U>(ar[1]); c = Convert<V>(ar[2]);
        }
    }
}