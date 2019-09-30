using System;
using System.Linq;
using System.Collections;
using System.Threading.Tasks;
using System.Collections.Generic;
using System.Runtime.InteropServices;
namespace NotFounds
{
    public class Program
    {
        public static void Main(string[] args)
        {
            new Program().Solve();
        }

        public void Solve()
        {
            var cin  = new MyInputStream();
            var h = cin.ReadInt();
            var w = cin.ReadInt();
            var hx = (h - 2 + 1) * w;
            var wx = (w - 2 + 1) * h;
            Console.WriteLine(hx + wx);
        }
    }

    public class MyInputStream
    {
        private char separator = ' ';
        private Queue<string> inputStream;
        public MyInputStream(char separator = ' ')
        {
            this.separator = separator;
            inputStream = new Queue<string>();
        }

        public string Read()
        {
            if (inputStream.Count != 0) return inputStream.Dequeue();
            string[] tmp = Console.ReadLine().Split(separator);
            for (int i = 0; i < tmp.Length; i++)
            {
                inputStream.Enqueue(tmp[i]);
            }
            return inputStream.Dequeue();
        }
        public string ReadLine()   { return Console.ReadLine(); }
        public int    ReadInt()    { return int.Parse(Read()); }
        public long   ReadLong()   { return long.Parse(Read()); }
        public double ReadDouble() { return double.Parse(Read()); }
    }

    public class MyMath
    {
        // nx = x + dxy[i], ny = y + dxy[i + 1] (i = 0..3)
        public static int[] dxy = new int[] {0, 1, 0, -1, 0};

        /// <summary>???????</summary>
        public static double EPS = 1e-11;

        /// <summary>??????</summary>
        public static long MOD = 1000000007;

        /// <summary>2???????????????</summary>
        public static bool EQ(double d1, double d2) { return (Math.Abs(d1 - d2) < EPS); }

        /// <summary>x^n % m</summary>
        public static long powmod(long x, long n, long m)
        {
            long ans = 1;
            long mul = x;
            for (; n > 0; n >>= 1, mul = (mul * mul) % m)
            {
                if ((n & 1) == 1) ans = (ans * mul) % m;
            }
            return ans % m;
        }

        /// <summary>n! % m</summary>
        public static long factmod(int n, long m)
        {
            long ans = 1;
            for (int i = 2; i <= n; i++)
            {
                ans *= i;
                ans %= m;
            }
            return ans;
        }

        /// <summary>n!</summary>
        public static long fact(int n)
        {
            long ans = 1;
            for (int i = 2; i <= n; i++) ans *= i;
            return ans;
        }

        /// <summary>nCr % mod</summary>
        public static long conbmod(int n, int r, long m)
        {
            long mul = factmod(n, m);
            long div = (factmod(r, m) * factmod(n - r, m)) % m;
            long inv = powmod(div, m - 2, m);
            return (mul * inv) % m;
        }

        /// <summary>nCr</summary>
        public static long conb(int n, int r)
        {
            long mul = parm(n, r);
            long div = fact(r);
            return mul / div;
        }

        /// <summary>nPr</summary>
        public static long parm(int n, int r)
        {
            long ans = 1;
            for (int i = n; i >= r; i--) ans *= i;
            return ans;
        }

        /// <summary>?????</summary>
        public static long gcd(long m, long n)
        {
            if (n == 0) return m;
            if (m < n) MyUtility.Swap(ref m, ref n);
            long tmp;
            while ((tmp = m % n) != 0)
            {
                m = n;
                n = tmp;
            }
            return n;
        }

        /// <summary>?????</summary>
        public static long lcm(long m, long n)
        {
            return m * n / gcd(m, n);
        }

        /// <summary>???</summary>
        public static double Dist(double x, double y)
        {
            return Math.Sqrt(x * x + y * y);
        }

        /// <summary>????</summary>
        public static bool isPrime(int n)
        {
            if (n < 2) return false;
            if ((n & 1) == 0) return n == 2 ? true : false;
            for (int i = 3; i * i <= n; i += 2)
            {
                if (n % i == 0) return false;
            }
            return true;
        }

        /// <summary>????(random)</summary>
        public static IEnumerable<int> GetPrimes(int n)
        {
            return Enumerable.Range(2, n - 1).AsParallel().Where(x => isPrime(x));
        }

        /// <summary>?????????</summary>
        public static int BitCount(uint n)
        {
            n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
            n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
            n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
            n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
            return (int)((n & 0x0000ffff) + ((n >> 16) & 0x0000ffff));
        }
    }

    public class MyUtility
    {
        /// <summary>???:????(n?????????????)</summary>
        public static double binarySearch(Func<double, double> calc, double min, double max, double target)
        {
            var mid = 0.0;
            for (int i = 0; i < 50; i++)
            {
                mid = (min + max) / 2.0;
                if (calc(mid) < target) min = mid;
                else max = mid;
            }
            return mid;
        }
        public static double binarySearch(Func<double, double> calc, double min, double max)
        {
            return binarySearch(calc, min, max, 0.0);
        }

        /// <summary>???:????<summary>
        public static double ternarySearch(Func<double, double> calc, double min, double max)
        {
            var left  = 0.0;
            var right = 0.0;
            for (int i = 0; i < 200; i++)
            {
                left  = (min * 2 + max) / 3.0;
                right = (min + max * 2) / 3.0;
                if (calc(left) < calc(right)) max = right;
                else min = left;
            }
            return (left + right) * 0.5;
        }

        /// <summary>??????</summary>
        /// calc : ?????( = 0), calcdash : calc????
        public static double newtonSearch(Func<double, double> calc, Func<double, double> calcdash)
        {
            var ans0 = 0.0;
            var ans1 = calc(ans0) / calcdash(ans0);
            for (int i = 0; i < 100; i++)
            {
                if (MyMath.EQ(ans0 - ans1, 0.0)) break;
                ans1 = ans0;
                ans0 -= calc(ans0) / calcdash(ans0);
            }
            return ans0;
        }

        public static int Coin(int[] coins, int price)
        {
            var N = coins.Length;
            var dp = new int[price + 1]; dp[0] = 0;
            for (var i = 1; i <= price; i++) dp[i] = int.MaxValue;
            for (var i = 1; i <= price; i++)
                for (var j = 0; j < N; j++)
                    if (i >= coins[j]) dp[i] = Math.Min(dp[i], dp[i - coins[j]] + 1);
                    else dp[i] = Math.Min(dp[i], dp[i - 1] + 1);
            return dp[price];
        }

        /// <summary>2???????</summary>
        public static void Swap<T>(ref T m, ref T n)
        {
            T tmp = m;
            m = n;
            n = tmp;
        }

        /// <summary>??????</summary>
        public static void Dump(params object[] data)
        {
            data.Dump();
        }
    }

#region extentions
    public static class MyEnumerableExtentions
    {
        public static string ConcatWith<T>(this IEnumerable<T> source, string separator,
                string format, IFormatProvider provider = null) where T : IFormattable
        {
            return source.Select(x => x.ToString(format, provider)).Aggregate((a, b) => a + separator + b);
        }

        public static string ConcatWith<T>(this IEnumerable<T> source, string separator)
        {
            return string.Join(separator, source);
        }

        public static void ForEach<T>(this IEnumerable<T> source, Action<T, int> func)
        {
            foreach (var item in source.Select((x, i) => new { val = x, idx = i }))
                func(item.val, item.idx);
        }

        public static void ForEach<T>(this IEnumerable<T> source, Action<T> func)
        {
            foreach (var item in source)
                func(item);
        }

        public static void Dump<T>(this IEnumerable<T> source)
        {
            Console.WriteLine("{ " + source.ConcatWith(", ") + " }");
        }

        public static IEnumerable<T> Shuffle<T>(this IEnumerable<T> source)
        {
            return source.OrderBy(x => Guid.NewGuid());
        }

        public static bool IsEmpty<T>(this IEnumerable<T> source)
        {
            return !source.Any();
        }

        public static string MaxLengthString(this IEnumerable<string> source)
        {
            return source.Aggregate("", (max, s) => s.Length > max.Length ? s : max);
        }

        public static string MinLengthString(this IEnumerable<string> source)
        {
            return source.Aggregate("", (min, s) => (s.Length < min.Length || min == "") ? s : min);
        }

        public static IEnumerable<IEnumerable<T>> Permutations<T>(this IEnumerable<T> source)
        {
            if (source.Count() != 0)
            {
                int index = 0;
                foreach (var item in source)
                {
                    var allOtherItems = source.RemoveAt(index++);
                    foreach (var permutation in allOtherItems.Permutations())
                    {
                        yield return new[] {item}.Concat(permutation);
                    }
                }
            }
            else {yield return new T[0];}
        }

        public static IEnumerable<T> RemoveAt<T>(this IEnumerable<T> source, int indexToRemove)
        {
            int index = 0;
            foreach (T item in source)
                if (index++ != indexToRemove)
                    yield return item;
        }
    }
#endregion
}