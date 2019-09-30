using System;
using System.Text;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
using static System.Console;
using static System.Math;

namespace AtCoder
{
    class Program
    {

        static void Main(string[] args)
        {
            new Program().Solve(new ConsoleInput(Console.In, ' '));
        }

        public void Solve(ConsoleInput cin)
        {
            int n = cin.ReadInt;
            int m = cin.ReadInt;

            PrimeFactor pf = new PrimeFactor();
            IEnumerable<long> primes = pf.Enumerate(m);

            Dictionary<int, int> map = new Dictionary<int, int>();

            int max_r = 1;
            foreach (int num in primes)
            {
                if (map.ContainsKey(num))
                {
                    map[num]++;
                    if(max_r < map[num])
                    {
                        max_r = map[num];
                    }
                }
                else
                {
                    map[num] = 1;
                }
            }

            Modulo modulo = new Modulo(n + max_r);
            int result = 1;

            foreach (int r in map.Values)
            {
                result = modulo.Mul(result, modulo.Ncr(n + r - 1, r));
            }

            Console.WriteLine(result);
        }
    }

    public class ConsoleInput
    {
        private readonly System.IO.TextReader _stream;
        private char _separator = ' ';
        private Queue<string> inputStream;

        public ConsoleInput(System.IO.TextReader stream, char separator = ' ')
        {
            this._separator = separator;
            this._stream = stream;
            inputStream = new Queue<string>();
        }

        public string Read
        {
            get
            {
                if (inputStream.Count != 0) return inputStream.Dequeue();
                string[] tmp = _stream.ReadLine().Split(_separator);
                for (int i = 0; i < tmp.Length; ++i)
                    inputStream.Enqueue(tmp[i]);
                return inputStream.Dequeue();
            }
        }

        public string ReadLine { get { return _stream.ReadLine(); } }
        public int ReadInt { get { return int.Parse(Read); } }
        public long ReadLong { get { return long.Parse(Read); } }
        public double ReadDouble { get { return double.Parse(Read); } }
        public string[] ReadStrArray(long N) { var ret = new string[N]; for (long i = 0; i < N; ++i) ret[i] = Read; return ret; }
        public int[] ReadIntArray(long N) { var ret = new int[N]; for (long i = 0; i < N; ++i) ret[i] = ReadInt; return ret; }
        public long[] ReadLongArray(long N) { var ret = new long[N]; for (long i = 0; i < N; ++i) ret[i] = ReadLong; return ret; }
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
            if (n % 2 == 0)
                return 2;
            if (IsPrime(n))
                return n;
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
                // ?????????????????????????
                return GetFactor(n, seed + 1);
            // ????????????????????
            return GetFactor(d);
        }

        private int[] seeds = new int[] { 3, 5, 7, 11, 13, 17 };
        private long f(long x, long n, int seed)
        {
            return (seeds[seed % 6] * x + seed) % n;
        }

        private static long Gcd(long a, long b)
        {
            if (a < b)
                return Gcd(b, a);  // ??????????????
            if (b == 0)
                return a;
            long d = 0;
            do
            {
                d = a % b;
                a = b;
                b = d;
            } while (d != 0);
            return a;
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

    class Modulo
    {
        private const int M = 1000000007;
        private readonly int[] m_facs;
        public int Mul(int a, int b)
        {
            return (int)(Math.BigMul(a, b) % M);
        }
        public Modulo(int n)
        {
            m_facs = new int[n + 1];
            m_facs[0] = 1;
            for (int i = 1; i <= n; ++i)
            {
                m_facs[i] = Mul(m_facs[i - 1], i);
            }
        }
        public int Fac(int n)
        {
            return m_facs[n];
        }
        public int Pow(int a, int m)
        {
            switch (m)
            {
                case 0:
                    return 1;
                case 1:
                    return a;
                default:
                    int p1 = Pow(a, m / 2);
                    int p2 = Mul(p1, p1);
                    return ((m % 2) == 0) ? p2 : Mul(p2, a);
            }
        }
        public int Div(int a, int b)
        {
            return Mul(a, Pow(b, M - 2));
        }
        public int Ncr(int n, int r)
        {
            if (n < r) { return 0; }
            if (n == r) { return 1; }
            int res = Fac(n);
            res = Div(res, Fac(r));
            res = Div(res, Fac(n - r));
            return res;
        }
    }
}