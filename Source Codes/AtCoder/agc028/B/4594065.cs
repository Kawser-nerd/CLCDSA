using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AGC_BC
{
    class Program
    {
        static int _Mod = 1000000007;

        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int[] A = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

            long Nf = Factorial(N)[N];
            long[] s = new long[N];
            for (int i = 0; i < N; i++) //i:??
            {
                long val = (Nf * InverseElement(i+1)) % _Mod;
                if (i == 0) s[i] = val;
                else s[i] = (s[i - 1] + val) % _Mod;
            }

            long sum = 0;
            for (int i = 0; i < N; i++)
            {
                //????????????????????????????
                long ss = s[N - i - 1] + s[i] - s[0];ss += _Mod; ss %= _Mod;
                long val = A[i] * ss; val %= _Mod;
                sum += val; sum %= _Mod;
            }
            Console.WriteLine(sum);
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

    }
}