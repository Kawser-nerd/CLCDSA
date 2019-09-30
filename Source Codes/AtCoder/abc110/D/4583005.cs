using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//???WA??????????
//???????????????????
namespace ABC_D
{
    class D110
    {
        static int _Mod = 1000000007;

        static void Main(string[] args)
        {
            int[] a = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            int N = a[0], M = a[1];

            Dictionary<int, int> dic = GetPrimeFactorsAsDic(M);

            long count = 1;

            foreach (var v in dic)
            {
                long c = Combination(v.Value + N - 1, v.Value);
                count = (count * c) % _Mod;
            }

            Console.WriteLine(count);
        }

        //??????????x????????O(nlog(log(n)))
        //????O(n)???100M(10^8)???
        public static List<int> GetPrimeNumbersEratosthnes(int x)
        {
            List<bool> list = new List<bool>();
            for (int i = 0; i <= x; i++)
            {
                list.Add(true);
            }
            list[0] = false; list[1] = false;
            int k = 0;
            List<int> plist = new List<int>();
            while (true)
            {
                while (!list[k])
                {
                    k++;
                    if (k > x) goto LabelFinish;
                }
                plist.Add(k);
                int m = k;
                while (m <= x)
                {
                    list[m] = false;
                    m += k;
                }
            }

        LabelFinish:
            return plist;
        }


        public static Dictionary<int, int> GetPrimeFactorsAsDic(int x, List<int> primeNumbers = null)
        {
            int z = (int)Math.Sqrt(x);
            Dictionary<int, int> dic = new Dictionary<int, int>();
            if (primeNumbers == null) primeNumbers = GetPrimeNumbersEratosthnes(z);

            int k = 0;
            while (true)
            {
                bool can_div = false;
                for (int i = k; i < primeNumbers.Count; i++)
                {
                    int n = primeNumbers[i];
                    if (x % n == 0)
                    {
                        if (!dic.ContainsKey(n)) dic.Add(n, 1);
                        else dic[n]++;
                        x /= primeNumbers[i];
                        k = i;
                        can_div = true;
                        break;
                    }
                }
                if (!can_div)
                {
                    if (x > 1) dic.Add(x, 1);
                    break;
                }
            }
            return dic;
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
        public static long Combination(int n, int r)
        {
            List<long> power = Factorial(n);
            List<long> inv = InversePower(n);
            long denominator = (inv[r] * inv[n - r]) % _Mod;
            long val = (power[n] * denominator) % _Mod;
            return val;
        }


    }
}