using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Net.Mail;

namespace Contest
{
    class Scanner
    {
        private string[] line = new string[0];
        private int index = 0;

        public string Next()
        {
            if (line.Length <= index)
            {
                line = Console.ReadLine().Split(' ');
                index = 0;
            }

            var res = line[index];
            index++;
            return res;
        }

        public int NextInt()
        {
            return int.Parse(Next());
        }

        public long NextLong()
        {
            return long.Parse(Next());
        }

        public string[] Array()
        {
            line = Console.ReadLine().Split(' ');
            index = line.Length;
            return line;
        }

        public int[] IntArray()
        {
            var array = Array();
            var result = new int[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                result[i] = int.Parse(array[i]);
            }

            return result;
        }

        public long[] LongArray()
        {
            var array = Array();
            var result = new long[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                result[i] = long.Parse(array[i]);
            }

            return result;
        }
    }

    class MyMath
    {
        public static long Pow(long a, long b)
        {
            long res = 1;
            while (b > 0)
            {
                if (b % 2 == 1)
                {
                    res *= a;
                    res %= Mod;
                }

                a *= a;
                a %= Mod;
                b /= 2;
            }

            return res;
        }

        private const long Mod = 998244353;

        static MyMath()
        {
            _factorial = new long[700001];
            _factorial[0] = 1;
            for (int i = 1; i <= 700000; i++)
            {
                _factorial[i] = (_factorial[i - 1] * i) % Mod;
            }
        }

        private static long[] _factorial;



        private static long Factorial(long n)
        {
            return _factorial[n];
        }

        public static long Combination(long n, long m)
        {
            if (n < m) return 0;
            long bunsi = _factorial[n];
            long bunbo = (_factorial[m] * _factorial[n - m]) % Mod;
            long gyakugen = Pow(bunbo, Mod - 2);
            return (bunsi * gyakugen) % Mod;
        }
    }

    class Program
    {
        private long N, A, B;
        private long K;
        private const long Mod = 998244353;
        private void Scan()
        {
            var sc = new Scanner();
            N = sc.NextInt();
            A = sc.NextInt();
            B = sc.NextInt();
            K = sc.NextLong();
        }

        public void Solve()
        {
            Scan();
            long ans = 0;
            for (long r = 0; r <= N; r++)
            {
                long bb = K - r * A;
                long b;
                if (bb < 0) continue;
                if (bb % B == 0)
                {
                    b = bb / B;
                }
                else
                {
                    continue;
                }
                ans += MyMath.Combination(N, r) * MyMath.Combination(N, b);
                ans %= Mod;

            }
            Console.WriteLine(ans);
        }

        static void Main() => new Program().Solve();
    }
}