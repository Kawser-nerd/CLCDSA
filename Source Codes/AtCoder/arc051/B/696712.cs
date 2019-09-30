using System;
using System.Linq;
using System.Collections;
using System.Threading.Tasks;
using System.Collections.Generic;
using static System.Console;
using static System.Math;
using static NotFounds.MyMath;
//using static NotFounds.MyUtility;

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
            MyInputStream cin = new MyInputStream();

            var N = cin.ReadInt();

            if (N == 1) WriteLine("1 1");
            else
            {

                var dp = new long[N + 2];
                dp[0] = 1;
                dp[1] = 1;
                for (int i = 2; i <= N + 1; i++)
                {
                    dp[i] = dp[i - 1] + dp[i - 2];
                }
                WriteLine($"{dp[N - 1]} {dp[N]}");
            }

        }
    }

    #region Pair
    public class Pair<T>
    {
        public T First { get; set; }
        public T Second { get; set; }
        public Pair(T f, T s) { First = f; Second = s; }
        public override string ToString() { return "(" + First + ", " + Second + ")"; }
        public override int GetHashCode() { return First.GetHashCode() ^ Second.GetHashCode(); }
        public override bool Equals(object obj)
        {
            if (ReferenceEquals(this, obj)) return true;
            else if (obj == null) return false;
            var tmp = obj as Pair<T, T>;
            return (object)tmp != null && First.Equals(tmp.First) && Second.Equals(tmp.Second);
        }
    }

    public class Pair<T1, T2>
    {
        public T1 First;
        public T2 Second;
        public Pair() { First = default(T1); Second = default(T2); }
        public Pair(T1 f, T2 s) { First = f; Second = s; }
        public override string ToString() { return "(" + First + ", " + Second + ")"; }
        public override int GetHashCode() { return First.GetHashCode() ^ Second.GetHashCode(); }
        public override bool Equals(object obj)
        {
            if (ReferenceEquals(this, obj)) return true;
            else if (obj == null) return false;
            var tmp = obj as Pair<T1, T2>;
            return (object)tmp != null && First.Equals(tmp.First) && Second.Equals(tmp.Second);
        }
    }
    #endregion
    public class MyMath
    {
        // nx = x + dxy[i], ny = y + dxy[i + 1] (i = 0..3)
        public static int[] dxy = new int[] { 0, 1, 0, -1, 0 };

        /// ???
        public static int INF = int.MaxValue >> 1;

        /// ???????
        public static double EPS = 1e-11;

        /// ??????
        public static long MOD = 1000000007;

        /// 2???????????????
        public static bool EQ(double d1, double d2) => (Math.Abs(d1 - d2) < EPS);

        /// x^n % m
        public static long PowMod(long x, long n, long m)
        {
            long ans = 1;
            long mul = x;
            for (; n > 0; n >>= 1, mul = (mul * mul) % m)
            {
                if ((n & 1) == 1) ans = (ans * mul) % m;
            }
            return ans % m;
        }

        /// n! % m
        public static long FactMod(int n, long m)
        {
            long ans = 1;
            for (int i = 2; i <= n; i++)
            {
                ans *= i;
                ans %= m;
            }
            return ans;
        }

        /// n!
        public static long Fact(int n)
        {
            long ans = 1;
            for (int i = 2; i <= n; i++) ans *= i;
            return ans;
        }

        /// nCr % mod
        public static long ConbMod(int n, int r, long m)
        {
            long mul = FactMod(n, m);
            long div = (FactMod(r, m) * FactMod(n - r, m)) % m;
            long inv = PowMod(div, m - 2, m);
            return (mul * inv) % m;
        }

        /// nCr
        public static long Conb(int n, int r)
        {
            long mul = Parm(n, r);
            long div = Fact(r);
            return mul / div;
        }

        /// nPr
        public static long Parm(int n, int r)
        {
            long ans = 1;
            for (int i = n; i >= r; i--) ans *= i;
            return ans;
        }

        /// ?????
        public static double Dist(double x, double y)
        {
            return Math.Sqrt(x * x + y * y);
        }

        /// ????
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

        /// ????(random)
        public static IEnumerable<int> GetPrimes(int n)
        {
            return Enumerable.Range(2, n - 1).AsParallel().Where(x => isPrime(x));
        }

        /// ?????????
        public static int BitCount(uint n)
        {
            n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
            n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
            n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
            n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
            return (int)((n & 0x0000ffff) + ((n >> 16) & 0x0000ffff));
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
        public string ReadLine() => Console.ReadLine();
        public int ReadInt() => int.Parse(Read());
        public long ReadLong() => long.Parse(Read());
        public double ReadDouble() => double.Parse(Read());
    }
}