using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_D
{
    class D058
    {

        static int _Mod = 1000000007;

        //??(a^n) O(logn)
        public static long ModPow(long a, int n)
        {
            long res = 1;
            while (n > 0)
            {
                if (n % 2 == 1) res = (res * a) % _Mod;
                a = (a * a) % _Mod;
                n >>= 1;
            }
            return res;
        }

        //??1/n(mod p) (1<=n<p)
        public static long InverseElement(long n)
        {
            return ModPow(n, _Mod - 2);
        }

        //??n!(mod p)?????
        public static List<long> Factorial(int n)
        {
            long x = 1;
            List<long> list = new List<long>();
            list.Add(x);
            for (int i = 1; i <= n; i++)
            {
                x = (x * i) % _Mod;
                list.Add(x);
            }
            return list;
        }

        //????? 1/n! (mod p)?????
        public static List<long> InversePower(int n)
        {
            long x = 1;
            List<long> list = new List<long>();
            list.Add(x);
            for (int i = 1; i <= n; i++)
            {
                x = (x * InverseElement(i)) % _Mod;
                list.Add(x);
            }
            return list;
        }

        //???????nCr (mod p)
        public static long Combination(int n, int r, List<long> power, List<long> inv)
        {
            long denominator = (inv[r] * inv[n - r]) % _Mod;
            long val = (power[n] * denominator) % _Mod;
            return val;
        }


        static void Main(string[] args)
        {
            int[] a = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            int H = a[0], W = a[1], A = a[2], B = a[3];

            List<long> power = Factorial(H + W);
            List<long> inv = InversePower(H + W);


            long sum = 0;
            for (int i = 0; i < H - A; i++)
            {
                long c1 = Combination(B + i - 1, i, power, inv) % _Mod;
                long c2 = Combination(W + H - B - i - 2, W - B - 1, power, inv) % _Mod;
                sum = (sum + c1 * c2) % _Mod;
            }
            Console.WriteLine(sum);
        }

    }
}